#include <windows.h>
#include <math.h>
#include <string.h>
#include "usersurf.h"

/*
Written by Kenneth E. Moore
Oct 11, 1996
Modified Feb 1, 2006 to use newer FIXED_DATA3 structure KEM
*/

/*
注释：
QQ 260021863
*/

int __declspec(dllexport) APIENTRY UserDefinedSurface3(USER_DATA *UD, FIXED_DATA3 *FD);

/* 一个折射的函数 */
int Refract(double thisn, double nextn, double *l, double *m, double *n, double ln, double mn, double nn);

BOOL WINAPI DllMain (HANDLE hInst, ULONG ul_reason_for_call, LPVOID lpReserved)
	{
   return TRUE;
   }

/* 一个自定义面型，可用于平面球面二次曲面*/

int __declspec(dllexport) APIENTRY UserDefinedSurface3(USER_DATA *UD, FIXED_DATA3 *FD)
	{
   int i;
   double p2, alpha, power, a, b, c, rad, casp, t, zc;
   switch(FD->type)
   	{
      case 0:
      	/* ZEMAX 请求基本数据*/
         switch(FD->numb)
         	{
            case 0:
            	/* 请求面的名称 */
		         /* 不得超过12个字符 */
		         strcpy(UD->string,"User DLL");
               break;
            case 1:
            	/* 请求该面是否对称 */
               /* 是 返回任意字符，如果否返回空字符串*/
            	strcpy(UD->string, "1");
               break;
            case 2:
            	/* 请求该面是否为渐变折射率材料 */
               /* 不是，返回空字符串*/
            	UD->string[0] = '\0';
            	break;
            }
         break;
      case 1:
      	/* ZEMAX 请求 parameter 标题 */
         /* FD->numb  为列数 */
         /* 默认为 "Unused" 返回空字符串 */
         switch(FD->numb)
         	{
            default:
            	UD->string[0] = '\0';
            	break;
            }
      	break;
      case 2:
      	/* ZEMAX 请求 extra data 标题 */
         /* FD->numb  为列数 */
         /* 默认为 "Unused" 返回空字符串 */
         switch(FD->numb)
         	{
            default:
            	UD->string[0] = '\0';
            	break;
            }
      	break;
      case 3:
      	/* ZEMAX 请求计算矢高 */
        /* 如果只有sag， alternate sag 为 sag  */
        UD->sag1 = 0.0;
        UD->sag2 = 0.0;

		/* 平面 */
		if (FD->cv == 0) return(0);
        p2 = UD->x * UD->x + UD->y * UD->y;
        alpha = 1 - (1+FD->k)*FD->cv*FD->cv*p2;

		// 由于浮点数在计算机中不可能100%准确，如果 alpha 小于 1e-13 认为足够小，直接设为0
		if (fabs(alpha) < 1e-13)
			alpha = 0;

        if (alpha < 0) return(-1);
        UD->sag1 = (FD->cv*p2)/(1 + sqrt(alpha));
        if (alpha != 1.0) UD->sag2 = (FD->cv*p2)/(1 - sqrt(alpha));
			break;
      case 4:
      	/* ZEMAX 请求 追迹近轴光线 */
         /* x, y, z, and the path are unaffected, at least for this surface type */
         /* 对于近轴追迹z坐标都为0 */
         /* 近轴面都为平面 */

         UD->ln =  0.0;
         UD->mn =  0.0;
         UD->nn = -1.0;
         power = (FD->n2 - FD->n1)*FD->cv;
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
      	/* ZEMAX 请求 追迹实际光线 */
        if (FD->cv == 0.0) // 如果是平面
        {
			UD->ln =  0.0;
			UD->mn =  0.0;
			UD->nn = -1.0;
			if (Refract(FD->n1, FD->n2, &UD->l, &UD->m, &UD->n, UD->ln, UD->mn, UD->nn)) return(-FD->surf);
				return(0);
        }
         /* 不是平面 */
		a = (UD->n) * (UD->n) * FD->k + 1;
		b = ((UD->n)/FD->cv) - (UD->x) * (UD->l) - (UD->y) * (UD->m);
		c = (UD->x) * (UD->x) + (UD->y) * (UD->y);
		rad = b * b - a * c;
		if (rad < 0) return(FD->surf);  /* 光线与该面不相交 */
		if (FD->cv > 0) t = c / (b + sqrt(rad));
		else           t = c / (b - sqrt(rad));
		(UD->x) = (UD->l) * t + (UD->x);
		(UD->y) = (UD->m) * t + (UD->y);
		(UD->z) = (UD->n) * t + (UD->z);
		UD->path = t;
		zc = (UD->z) * FD->cv;
		rad = zc * FD->k * (zc * (FD->k + 1) - 2) + 1;
		casp = FD->cv / sqrt(rad);
		UD->ln = (UD->x) * casp;
		UD->mn = (UD->y) * casp;
		UD->nn = ((UD->z) - ((1/FD->cv) - (UD->z) * FD->k)) * casp;
        if (Refract(FD->n1, FD->n2, &UD->l, &UD->m, &UD->n, UD->ln, UD->mn, UD->nn)) return(-FD->surf);
			break;
      case 6:
      	/* ZEMAX 请求折射率 以及 在指定x y z 处的 dn/dx, dn/dy, and dn/dz  */

         /* 本例设为0即可 */
         UD->index = FD->n2;
         UD->dndx = 0.0;
         UD->dndy = 0.0;
         UD->dndz = 0.0;
      	break;
      case 7:
      	/* ZEMAX 请求设置初始参数 */
         /* 设置 parameter 和 extra data 的初始值 */
         /* 当面型第一次切换到的时候，被设置 */
         /* 这是唯一一次DLL修改FIXED_DATA FD 中的数据 */
         for (i = 0; i <= FD->max_parameter; i++) FD->param[i] = 0.0;
         for (i = 0; i <= FD->max_extradata; i++) FD->xdata[i] = 0.0;
         break;
      case 8:
      	/* ZEMAX 初始化调用 */
         break;
      case 9:
      	/* ZEMAX 卸载调用 */
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

