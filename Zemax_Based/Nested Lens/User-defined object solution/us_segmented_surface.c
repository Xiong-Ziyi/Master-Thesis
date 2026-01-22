#include <windows.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "usersurf.h"

/*
Written by Ziyi Xiong
December 3, 2025
*/

int __declspec(dllexport) APIENTRY UserDefinedSurface(USER_DATA *UD, FIXED_DATA *FD);

/* a generic Snells law refraction routine */
int Refract(double thisn, double nextn, double *l, double *m, double *n, double ln, double mn, double nn);

static void EvalConic(double c, double k, double r, double *z_conic, double *dzdr_conic);

static void EvalEvenPoly(const double *coeffs, int pmax, double r, double *z_poly, double *dzdr_poly);

/* 
The two lines above are declarations, which, tell the compiler the function¡¯s name, return type, and parameter types, 
let the rest of the file call Refract(...) even before the function body appears.
*/

BOOL WINAPI DllMain (HANDLE hInst, ULONG ul_reason_for_call, LPVOID lpReserved)
	{
   return TRUE;
   }

/*

This DLL models a rotationally symmetric segmented surface.

This surface is essentially made of two aspheric surfaces, the first even asperical surface ranges from 0 to q, the second even aspherical surface ranges from q to clear semi-diameter.

The sag of a even aspherical surface is given by:

if r < r1:
    Z1 = (c1*r*r) / (1+(1-((1+k1)*c1*c1*r*r))^ 1/2 ) + a12*(r)^2 + a14*(r)^4 + a16*(r)^6 + a18*(r)^8 + a110*(r)^10 +a112*(r)^12 + ...
else if r > r1:
    Z2 = (c2*r*r) / (1+(1-((1+k2)*c2*c2*r*r))^ 1/2 ) + a22*(r)^2 + a24*(r)^4 + a26*(r)^6 + a28*(r)^8 + a210*(r)^10 +a212*(r)^12 + ...
else if r = r1:
    Z1 = Z2 

Note the terms a, b, c, ... have units of length to the -1, -2, -3, ... power.

*/

int __declspec(dllexport) APIENTRY UserDefinedSurface(USER_DATA *UD, FIXED_DATA *FD)
	{
   int loop, i;
   double r, r2, tp, t, x, y, z, dz, sag;

   switch(FD->type)
   	{
      case 0:
      	/* ZEMAX is requesting general information about the surface */
         switch(FD->numb)
         	{
            case 0:
            	/* ZEMAX wants to know the name of the surface */
		         /* do not exceed 12 characters */
		         strcpy(UD->string,"SegmentedAsph");
                 /* strcpy copies a C string from a source into a destination buffer */
               break;
            case 1:
            	/* ZEMAX wants to know if this surface is rotationally symmetric */
               /* it is, so return any character in the string; otherwise, return a null string */
            	strcpy(UD->string, "1");
               break;
            case 2:
            	/* ZEMAX wants to know if this surface is a gradient index media */
               /* it is not, so return a null string */
            	UD->string[0] = '\0';
            	break;
            }
         break;
      case 1:
      	/* ZEMAX is requesting the names of the parameter columns */
         /* the value FD->numb will indicate which value ZEMAX wants. */
         /* returning a null string indicates that the parameter is unused. */
         switch(FD->numb)
         	{
            /* parameter columns labels */
            /* The values entered by the user under the columns is accessible at runtime as FD->param[1]..[5] */
            case 1: strcpy(UD->string, "Boundary Clear"); break; 
            case 2: strcpy(UD->string, "Radius Zone 1"); break;
            case 3: strcpy(UD->string, "Conic Zone 1"); break;
            case 4: strcpy(UD->string, "Radius Zone 2"); break;
            case 5: strcpy(UD->string, "Conic Zone 2"); break;
            default:
            	UD->string[0] = '\0';
            	break;
            }
      	break;
      case 2:
      	/* ZEMAX is requesting the names of the extra data columns */
         /* the value FD->numb will indicate which value ZEMAX wants. */
         /* returning a null string indicates that the extradata value is unused. */
        {
            int p1 = (int)FD->xdata[1]; /* The number of even aspherical terms for zone 1*/
            int base2 = 2 + p1; /* index where pmax2 is stored */
            int p2 = (int)FD->xdata[base2];
            /* Map FD->numb to zone/term */
            switch(FD->numb)
            {
                case 1: strcpy(UD->string, "Seg1 #Terms"); break;
                default:
                {
                    int idx = FD->numb;
                    if (idx >= 2 && idx <= (p1 + 1)) {
                        int termIndex = idx - 1; /* 2->Term1(a2), 3->Term2(a4), ... */
                        sprintf(UD->string, "Seg1 A_%d", 2*termIndex);
                    } else if (idx == base2) {
                        strcpy(UD->string, "Seg2 #Terms");
                    } else if (idx > base2 && idx <= base2 + p2) {
                        int termIndex = idx - base2;
                        sprintf(UD->string, "Seg2 A_%d", 2*termIndex);
                    } else {
                        UD->string[0] = '\0';
                    }
                }
                break;
            }
        }
      	break;
      case 3:
        {
      	/* ZEMAX wants to know the sag of the surface */

         UD->sag1 = 0.0;
         UD->sag2 = 0.0;
         
         double r1 = FD->param[1];
         double radius1 = FD->param[2];
         double k1 = FD->param[3];
         double radius2 = FD->param[4];
         double k2 = FD->param[5];

		 double c1 = 1.0 / radius1;
		 double c2 = 1.0 / radius2;

         r2 = UD->x * UD->x + UD->y * UD->y;
         r = sqrt(r2);

         int p1 = (int)FD->xdata[1]; /* The number of even aspherical terms for zone 1*/
         const double *a1 = &FD->xdata[2]; /* The coefficients for zone 1 start at index 2 */
         int base2 = 2 + p1;
         int p2 = (int)FD->xdata[base2]; /* The number of even aspherical terms for zone 2*/
         /* Takes the address of FD->xdata[data2 + 1] and makes a2 a pointer to the startof the coefficients*/
         const double *a2 = &FD->xdata[base2 + 1];


        /* Evaluate sag of the zone 1*/
         double sag1_conic, d_sag1_conic; EvalConic(c1, k1, r, &sag1_conic, &d_sag1_conic);
         double sag1_aspht, d_sag1_aspht; EvalEvenPoly(a1, p1, r, &sag1_aspht, &d_sag1_aspht);
         double sag1 = sag1_aspht + sag1_conic;

         /* Evaluate sag of zone 2 */
         double sag2_conic, d_sag2_conic; EvalConic(c2, k2, r, &sag2_conic, &d_sag2_conic);
         double sag2_aspht, d_sag2_aspht; EvalEvenPoly(a2, p2, r, &sag2_aspht, &d_sag2_aspht);
         double sag2 = sag2_aspht + sag2_conic;

         /* Evaluate the possible offset between the two zones for compensate*/
         double sag1_r1_conic, d_sag1_r1_conic; EvalConic(c1, k1, r1, &sag1_r1_conic, &d_sag1_r1_conic);
         double sag1_r1_aspht, d_sag1_r1_aspht; EvalEvenPoly(a1, p1, r1, &sag1_r1_aspht, &d_sag1_r1_aspht);
         double sag1_r1 = sag1_r1_aspht + sag1_r1_conic;

         double sag2_r1_conic, d_sag2_r1_conic; EvalConic(c2, k2, r1, &sag2_r1_conic, &d_sag2_r1_conic);
         double sag2_r1_aspht, d_sag2_r1_aspht; EvalEvenPoly(a2, p2, r1, &sag2_r1_aspht, &d_sag2_r1_aspht);
         double sag2_r1 = sag2_r1_aspht + sag2_r1_conic;

         double offset = sag1_r1 - sag2_r1;

         double sag = (r <= r1) ? sag1 : (sag2 + offset);

         UD->sag1 = sag;
         UD->sag2 = UD->sag1;
        }
      	break;
      case 4:
      	/* ZEMAX wants a paraxial ray trace to this surface */
         /* x, y, z, and the optical path are unaffected, at least for this surface type */
         /* for paraxial ray tracing, the return z coordinate should always be zero. */
         /* paraxial surfaces are always planes with the following normals */
         /* we will ignore the aspheric terms, even the quadratic one, since it has a */
         /* meaning that is hard to interpret if q != 0.0 */

         UD->ln =  0.0;
         UD->mn =  0.0;
         UD->nn = -1.0;
         double power = (FD->n2 - FD->n1)*FD->cv;
         if ((UD->n) != 0.0)
         	{
            (UD->l) = (UD->l)/(UD->n);
            (UD->m) = (UD->m)/(UD->n);

            (UD->l) = (FD->n1*(UD->l) - (UD->x)*power)/(FD->n2);
            (UD->m) = (FD->n1*(UD->m) - (UD->y)*power)/(FD->n2);

            /* normalize */
            (UD->n) = sqrt(1/(1 + (UD->l)*(UD->l) + (UD->m)*(UD->m) ) );
            /* de-paraxialize */
            (UD->l) = (UD->l)*(UD->n);
            (UD->m) = (UD->m)*(UD->n);
            }
         break;
      case 5:
        {
      	/* ZEMAX wants a real ray trace to this surface */
         /* okay, not a plane. */
         /* do not allow n == 0 */
         if (UD->n == 0.0) return -1;

         /* Now, we illustrate an iterative method of finding
            the intercept for a general surface. */

			/* make sure we do at least 1 loop */

		 t = 100.0;
         tp = 0.0;
         x = UD->x;
         y = UD->y;
         z = UD->z;
         loop = 0;

         double r1 = FD->param[1];
         double radius1 = FD->param[2];
         double k1 = FD->param[3];
         double radius2 = FD->param[4];
         double k2 = FD->param[5];

		 double c1 = 1.0 / radius1;
		 double c2 = 1.0 / radius2;

         int p1 = (int)FD->xdata[1]; /* The number of even aspherical terms for zone 1*/
         const double *a1 = &FD->xdata[2]; /* The coefficients for zone 1 start at index 2 */
         int base2 = 2 + p1;
         int p2 = (int)FD->xdata[base2]; /* The number of even aspherical terms for zone 2*/
         /* Takes the address of FD->xdata[data2 + 1] and makes a2 a pointer to the startof the coefficients*/
         const double *a2 = &FD->xdata[base2 + 1];

         double sag1_r1_conic, d_sag1_r1_conic; EvalConic(c1, k1, r1, &sag1_r1_conic, &d_sag1_r1_conic);
         double sag1_r1_aspht, d_sag1_r1_aspht; EvalEvenPoly(a1, p1, r1, &sag1_r1_aspht, &d_sag1_r1_aspht);
         double sag1_r1 = sag1_r1_aspht + sag1_r1_conic;

         double sag2_r1_conic, d_sag2_r1_conic; EvalConic(c2, k2, r1, &sag2_r1_conic, &d_sag2_r1_conic);
         double sag2_r1_aspht, d_sag2_r1_aspht; EvalEvenPoly(a2, p2, r1, &sag2_r1_aspht, &d_sag2_r1_aspht);
         double sag2_r1 = sag2_r1_aspht + sag2_r1_conic;

         double offset = sag1_r1 - sag2_r1;

         while (fabs(t) > 1e-10)
         	{
				/*
            First, compute the sag using whatever the surface sag expression is.
            This is given the x and y starting points. The following block of code
            will change depending upon the surface shape, the rest of this iteration
            is typically common to all surface shapes.
            */

	         double r2 = x * x + y * y;
             double r = sqrt(r2);

	         double sag_conic, d_sag_conic, sag_aspht, d_sag_aspht;
             if (r <= r1) {
                EvalConic(c1, k1, r, &sag_conic, &d_sag_conic);
                EvalEvenPoly(a1, p1, r, &sag_aspht, &d_sag_aspht);
                sag = sag_conic + sag_aspht;
             } else {
                EvalConic(c2, k2, r, &sag_conic, &d_sag_conic);
                EvalEvenPoly(a2, p2, r, &sag_aspht, &d_sag_aspht);
                sag = sag_conic + sag_aspht + offset;
             }

            /* okay, now with sag in hand, how far are we away in z? */
			// modified 11/2012 to support larger angles of incidence
			dz = (sag - z)*fabs(UD->n);

            /* now compute how far along the z axis this is */
            /* note this will crash if n == 0!! */
            t = dz / (UD->n);

            /* propagate the additional "t" distance */
            x += UD->l*t;
            y += UD->m*t;
            z += UD->n*t;

            /* add in the optical path */
				tp += t;

            /* prevent infinte loop if no convergence */
            loop++;
            if (loop > 1000) return(-1);
            }

         /* okay, we should be a the intercept coordinates now */
         UD->x = x;
         UD->y = y;
         UD->z = z;
      	/* don't forget the path! */
		UD->path = tp;

        /* normals from radial slope dZ/dr of selected zone */
        {
         double r2 = x * x + y * y;
         double r = sqrt(r2);

			/* now do the normals */
         if (r==0.0)
         	{
            UD->ln =  0.0;
            UD->mn =  0.0;
            UD->nn = -1.0;
            }
         else
         	{
            /* compute slope dZ/dr at intercept */
            double dzdr;

            if (r <= r1) {
                double sag_conic, d_sag_conic; EvalConic(c1, k1, r, &sag_conic, &d_sag_conic);
                double sag_aspht, d_sag_aspht; EvalEvenPoly(a1, p1, r, &sag_aspht, &d_sag_aspht);
                dzdr = d_sag_conic + d_sag_aspht;
            } else {
                double sag_conic, d_sag_conic; EvalConic(c2, k2, r, &sag_conic, &d_sag_conic);
                double sag_aspht, d_sag_aspht; EvalEvenPoly(a2, p2, r, &sag_aspht, &d_sag_aspht);
                dzdr = d_sag_conic + d_sag_aspht;
            }
            
			double rad = dzdr / sqrt(1.0 + dzdr * dzdr);

            UD->ln = (x / r) * rad;
            UD->mn = (y / r) * rad;
            
            UD->nn = UD->ln * UD->ln + UD->mn * UD->mn;
            if (UD->nn >= 1.0) return(-1);
            else UD->nn = -sqrt(1.0 - UD->nn);
            }
         }
        }
         if (Refract(FD->n1, FD->n2, &UD->l, &UD->m, &UD->n, UD->ln, UD->mn, UD->nn)) return(-FD->surf);
         break;
      case 6:
      	/* ZEMAX wants the index, dn/dx, dn/dy, and dn/dz at the given x, y, z. */

         /* This is only required for gradient index surfaces, so return dummy values */
         UD->index = FD->n2;
         UD->dndx = 0.0;
         UD->dndy = 0.0;
         UD->dndz = 0.0;
      	break;
      case 7:
      	/* ZEMAX wants the "safe" data. */
         /* this is used by ZEMAX to set the initial values for all parameters and extra data */
         /* when the user first changes to this surface type. */
         /* this is the only time the DLL should modify the data in the FIXED_DATA FD structure */
         for (i = 1; i <= 8; i++) FD->param[i] = 0.0;
		 FD->param[2] = HUGE_VAL;
		 FD->param[4] = HUGE_VAL;
         for (i = 1; i <= 200; i++) FD->xdata[i] = 0.0;
         break;
      }
   return 0;
   }

int Refract(double thisn, double nextn, double *l, double *m, double *n, double ln, double mn, double nn)
{
double nr, cosi, cosi2, rad, cosr, gamma;
if (thisn != nextn)
	{
	nr = thisn / nextn;
	cosi = fabs((*l) * ln + (*m) * mn + (*n) * nn);
	cosi2 = cosi * cosi;
	if (cosi2 > 1) cosi2 = 1;
	rad = 1 - ((1 - cosi2) * (nr * nr));
	if (rad < 0) return(-1);
	cosr = sqrt(rad);
	gamma = nr * cosi - cosr;
	(*l) = (nr * (*l)) + (gamma * ln);
	(*m) = (nr * (*m)) + (gamma * mn);
	(*n) = (nr * (*n)) + (gamma * nn);
	}
return 0;
}

/* helper to evaluate conic sag and radial slope for a given c,k at radius r */
static void EvalConic(double c, double k, double r, double *z_conic, double *dzdr_conic)
{
    /* Conic sag: Zc = (c*r^2) / (1 + sqrt(1 - (1+k)*c^2*r^2)) */
    double r2 = r*r;
    double c2r2 = (c*c)*r2;
    double alpha = 1.0 - (1.0 + k) * c2r2;
    if (alpha <= 0.0) {
        /* Outside valid domain; clamp to avoid NaN. Caller may treat as miss. */
        alpha = 1e-30;
    }
    double sq = sqrt(alpha);
    *z_conic = (c * r2) / (1.0 + sq);

    /* dZc/dr from known derivative of conic term */
    /* d/dr [ (c r^2) / (1 + sqrt(alpha)) ] with alpha = 1 - (1+k)c^2 r^2 */
    /* This matches your mm augmentation later; we compute directly for clarity. */
    double denom = (1.0 + sq);
    double d_alpha_dr = -2.0 * (1.0 + k) * (c*c) * r;
    double d_sq_dr = (0.5 / sq) * d_alpha_dr;
    double d_denom_dr = d_sq_dr;
    double num = c * r2;
    double d_num_dr = 2.0 * c * r;
    *dzdr_conic = (d_num_dr * denom - num * d_denom_dr) / (denom * denom);
}

/* evaluate even aspheric polynomial sum_j a_{2j} * r^(2j) and its radial derivative */
static void EvalEvenPoly(const double *coeffs, int pmax, double r, double *z_poly, double *dzdr_poly)
{
    /* coeffs[0] = a2, coeffs[1] = a4, ... coeffs[pmax-1] = a_{2*pmax} */
    double r2 = r*r;
    double z = 0.0;
    double dzdr = 0.0;
    double r_pow = r2;       /* starts at r^2 */
    double dr_pow = 2.0*r;   /* d/dr(r^2) = 2r; derivative multiplier for each term */

    for (int j = 0; j < pmax; ++j) {
        double a = coeffs[j];
        /* z += a * r^(2*(j+1)) */
        z += a * r_pow;
        /* dz/dr += a * d/dr(r^(2*(j+1))) = a * (2*(j+1))*r^(2*(j+1)-1) */
        /* Efficiently update derivative using current power:
           d/dr r_pow where r_pow = r^(2*(j+1)) is (2*(j+1))*r^(2*(j+1)-1) = (2*(j+1)) * r_pow / r
           but avoid division by r when r=0; use separate accumulation: */
        if (r > 0.0) {
            dzdr += a * (2.0*(j+1)) * (r_pow / r);
        }
        /* advance power: multiply by r^2 to get next even power */
        r_pow *= r2;
    }

    *z_poly = z;
    *dzdr_poly = dzdr;
}