import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import cumulative_trapezoid
from scipy.optimize import least_squares 
from typing import Optional
class BeamShaper:
    """
    This class is to model a initial Keplerian or Galilean beam shaper.

    This implementation is based on the formula provided in:
    - Title: "Laser Beam Shaping: Theory and Techniques"
      Editor: Fred M. Dickey
      Chapter: 7
      Edition: 2nd
      
    By Ziyi Xiong 2025/12

    Args:
        omega_0 (float): The radius of the input Gaussian beam waist.
        R_max (float): The maximum output radial coordinate.
        r_max (float): The maximum input radial coordinate.
        d (float): The thickness of the first lens' second surface.
        n (float): The refractive index of the two lens.
        type (str): Either "Keplerian" or "Galilean", indicatinig the type of beam shaper.
        approx (bool): indicates if the Longitudinal Aberration is approximated by parabolic
            function and Taylor expansion.
    """

    def __init__(
        self,
        omega_0: float,
        R_max: float,
        r_max: float,
        d: float,
        n: float,
        type: str = "Keplerian",
        approx: bool = True,
    ):
        self.omega_0 = omega_0
        self.R_max = R_max
        self.r_max = r_max
        self.d = d
        self.n = n

        if type not in ["Keplerian", "Galilean"]:
            raise ValueError("type must be either 'Keplerian' or 'Galilean'")
        self.type = type

        self.approx = approx

    @property
    def _B(self) -> float:
        """
        Returns a intermediate coefficient B given by Equation 7.13.
        """
        denom = np.sqrt(1 - np.exp(-2 * (self.r_max / self.omega_0) ** 2))
        if self.type == "Keplerian":
            return -self.R_max / denom
        else:
            return self.R_max / denom

    def s_prime(self, r) -> float:
        """
        Returns the object distance after the first lens at different ray height,
        given by Equation 7.16.
        """
        sqrt = np.sqrt(1 - np.exp(-2 * r**2 / self.omega_0**2))
        s_prime = self.d / (1 - (self._B / r) * sqrt)
        return s_prime

    @property
    def s_prime_zero(self) -> float:
        """
        Returns paraxial object distance, which is also equal to effective focal length f_1,
        given by Equation 7.17 and 7.18.
        """
        if self.approx:
            return self.d / (1 - np.sqrt(2) * self._B / self.omega_0)
        else:
            return self.s_prime(1e-15)

    @property
    def Delta_s_prime(self) -> float:
        """
        Returns the difference between real object distance and paraxial object distance,
        which is actually Longitudinal Aberration (LA), given by Equation 7.19, 7.20 and 7.21.
        """
        return self.s_prime(self.omega_0) - self.s_prime_zero

    @property
    def k_1(self) -> float:
        """
        Returns the conic constant of the first aspherical surface.
        """
        coeff = -2 * self.Delta_s_prime * self.s_prime_zero * (self.n - 1) ** 2
        return coeff / (self.omega_0**2) - self.n**2 

    @property
    def r_c1(self) -> float:
        """
        Returns the vertex radius of the first aspherical surface.
        """
        return -self.s_prime_zero * (self.n - 1)

    @property
    def k_2(self) -> float:
        """
        Returns the conic constant of the second aspherical surface.
        """
        coeff = self.s_prime_zero * self.k_1 + self.n**2 * self.d
        return coeff / (self.s_prime_zero - self.d)

    @property
    def r_c2(self) -> float:
        """
        Returns the vertex radius of the second aspherical surface.
        """
        return (self.n - 1) * (self.d - self.s_prime_zero)

    @property
    def xpan_ratio(self) -> float:
        """
        Returns the expansion ratio of the beam shaper.
        """
        f_1 = self.s_prime_zero
        f_2 = self.d - self.s_prime_zero
        return np.abs(f_2 / f_1)

    @property
    def apodization_factor(self) -> float:
        """
        Returns the apodization factor of the beam shaper.
        """
        return (self.r_max / self.omega_0)**2
  
    @property
    def result(self) -> dict:
        """
        Returns a dictionary containing parameters.
        """
        return {
            "r_c1": float(self.r_c1),
            "r_c2": float(self.r_c2),
            "k_1": float(self.k_1),
            "k_2": float(self.k_2),
        }


class EvenAsphere:
    '''
    This class models an even aspheric surface defined by its conic constant and 
    higher-order even aspheric coefficients.
    
    Args:
        r_max (float): Maximum radial coordinate.
        vertex_r (float): Vertex radius of curvature.
        k (float): Conic constant.
        coefficients (dict): Dictionary of higher-order even aspheric coefficients.
        num_samples (int): Number of radial samples to compute.
        
    By Ziyi Xiong 2026/1
    '''
    def __init__(self,
                 r_max: float, 
                 vertex_r: float, 
                 k: float, 
                 coefficients: dict = {4: 0.0, 6: 0.0, 8: 0.0}, 
                 num_samples: int = 100
    ):
        self.r_max = r_max
        self.vertex_r = vertex_r
        self.k = k
        self.coefficients = coefficients
        self.r = np.linspace(0, r_max, num_samples)
            
    def sag(self) -> np.ndarray:
        '''
        Returns the sag of the aspheric surface at different radial coordinates.
        '''
        denom = np.sqrt(1 - (1 + self.k) * (self.r / self.vertex_r)**2)
        conic = (self.r**2) / (self.vertex_r * (1 + denom))
        asph = np.zeros_like(self.r)
        for key, Ai in self.coefficients.items():
            asph += Ai * (self.r ** key)
        
        sag_r = conic + asph
        return sag_r
    
    def grad_sag(self) -> np.ndarray:
        '''
        Returns the gradient of the sag of the aspheric surface at different radial coordinates.
        '''
        denom = np.sqrt(1 - (1 + self.k) * (self.r / self.vertex_r)**2)
        grad_conic = self.r / (denom * self.vertex_r)
        grad_asph = np.zeros_like(self.r)
        for key, Ai in self.coefficients.items():
            grad_asph += key * Ai * (self.r ** (key - 1))    
        
        grad_sag_r = grad_conic + grad_asph
        return grad_sag_r


class BeamShaperFitter:
    '''
    This class is to fit Galilean or Keplerian beam shapers' two surfaces' sags with even aspheric surface equation.
    
    This implementation is based on the formula provided in:
    - Title: "Laser Beam Shaping: Aspheric Optics"
      Author: David L. Shealy, John A. Hoffnagle
    
    References: Shealy, D. L. and Hoffnagle, J. A. “Laser Beam Shaping: Aspheric Optics.” 
                In Encyclopedia of Optical Engineering, Driggers, R. (ed.), Taylor & Francis, New York, 2006.
      
    By Ziyi Xiong 2026/01
    
    Args:
        omega_0 (float): The radius of the input Gaussian beam waist.
        r_max (float): The maximum input radial coordinate.
        R_max (float): The maximum output radial coordinate.
        d (float): The thickness of the first lens' second surface.
        n (float): The refractive index of the two lens.
        type (str): Either "Keplerian" or "Galilean", indicatinig the type of beam shaper.
        num_samples (int): Number of radial samples to compute.
    '''
    def __init__(self, 
                 beam_shaper: BeamShaper, 
                 num_samples: int = 100
                 ):
        self.beam_shaper = beam_shaper
        self.omega_0 = beam_shaper.omega_0
        self.r_max = beam_shaper.r_max
        self.R_max = beam_shaper.R_max
        self.d = beam_shaper.d
        self.n = beam_shaper.n
        self.r = np.linspace(0, beam_shaper.r_max, num_samples)
        self.R = np.linspace(0, beam_shaper.R_max, num_samples)
        
        if beam_shaper.type not in ["Keplerian", "Galilean"]:
            raise ValueError("type must be either 'Keplerian' or 'Galilean'")
        
        self.type = beam_shaper.type
        self.num_samples = num_samples
        
    def plot(self, x: np.ndarray, y1: np.ndarray, y2: np.ndarray = 0, xlabel: str, ylabel: str, title: str):
        plt.plot(x, y)
        plt.xlabel(xlabel)
        plt.ylabel(ylabel)
        plt.title(title)
        plt.grid()
        plt.show()
    
    def R_from_r(self, plot: bool = False) -> np.ndarray:
        '''
        Returns the output radial coordinate R given input radial coordinate r.
        
        The relationship is given by Equation 19.10 in "Laser Beam Shaping: Aspheric Optics" by Shealy and Hoffnagle.
        
        R = epsilon * R_max * sqrt((1 - exp(-2*(r/omega_0)^2)) / (1 - exp(-2*(r_max/omega_0)^2)))
        
        '''
        e1 = np.exp(-2 * (self.r / self.omega_0) ** 2)
        e2 = np.exp(-2 * (self.r_max / self.omega_0) ** 2)
        R_r = self.R_max * np.sqrt((1 - e1) / (1 - e2))
        
        if self.type == "Keplerian":
            R_r = -R_r
        
        if plot:
            self.plot(self.r, R_r, "Input radial coordinate r", "Output radial coordinate R", f"{self.type} Beam Shaper Mapping")
        
        return R_r 
    
    def r_from_R(self, plot: bool = False) -> np.ndarray: 
        '''
        Returns the input radial coordinate r given output radial coordinate R.
        
        The relationship is given by Equation 20 in "Laser Beam Shaping: Aspheric Optics" by Shealy and Hoffnagle.
        
        r = epsilon * omega_0 * sqrt(-0.5 * ln(1 - (R/R_max)^2 * (1 - exp(-2*(r_max/omega_0)^2))))
        '''
        exp = np.exp(-2 * (self.r_max / self.omega_0) ** 2)
        sqrt = np.sqrt(-0.5 * np.log(1 - (self.R / self.R_max)**2 * (1 - exp)))
        r_R = self.omega_0 * sqrt
        
        if self.type == "Keplerian":
            r_R = -r_R
        
        if plot:
            self.plot(self.R, r_R, "Output radial coordinate R", "Input radial coordinate r", f"{self.type} Beam Shaper Inverse Mapping")
        
        return r_R    
    
    def grad_sag1(self, plot: bool = False) -> np.ndarray:
        '''
        Returns the gradient of the sag of the first surface at different radial coordinates.
        
        The relationship is given by Equation 32 in "Laser Beam Shaping: Aspheric Optics" by Shealy and Hoffnagle.
        
        z'(r) = 1 / sqrt( (d^2 * (1 - n)^2) / (R(r) - r)^2 + n^2 - 1)
        '''
        R_r = self.R_from_r()
        frac = (self.d**2 * (1 - self.n)**2) / (np.clip(R_r - self.r, a_min=1e-10, a_max=None)**2)
        grad_sag_r = 1 / np.sqrt(frac + self.n**2 - 1)
        
        if plot:
            self.plot(self.r, grad_sag_r, "Input radial coordinate r", "Gradient of Sag of Surface 1", f"{self.type} Beam Shaper Surface 1 Gradient of Sag")
            
        return grad_sag_r
    
    def sag1(self, plot: bool = False) -> np.ndarray:
        '''
        Returns the sag of the first surface at different radial coordinates.
        
        The relationship is given by integrating the gradient of sag over r.
        '''
        sag_r = cumulative_trapezoid(self.grad_sag1(), self.r, initial=0) # initial: constant of integration
        
        if plot:
            self.plot(sag_r, self.r, "Sag of Surface 1", "Input radial coordinate r", f"{self.type} Beam Shaper Surface 1 Sag")
            
        return sag_r
    
    def grad_sag2(self, plot: bool = False) -> np.ndarray:
        '''
        Returns the gradient of the sag of the first surface at different radial coordinates.
        
        The relationship is given by Equation 32 in "Laser Beam Shaping: Aspheric Optics" by Shealy and Hoffnagle.
        
        z'(R) = 1 / sqrt( (d^2 * (1 - n)^2) / (R - r(R))^2 + n^2 - 1)
        '''
        r_R = self.r_from_R()
        frac = (self.d**2 * (1 - self.n)**2) / (np.clip(self.R - r_R, a_min=1e-10, a_max=None)**2)
        grad_sag_r = 1 / np.sqrt(frac + self.n**2 - 1)
        
        if plot:
            self.plot(self.R, grad_sag_r, "Output radial coordinate R", "Gradient of Sag of Surface 2", f"{self.type} Beam Shaper Surface 2 Gradient of Sag")
            
        return grad_sag_r
    
    def sag2(self, plot: bool = False) -> np.ndarray:
        '''
        Returns the sag of the second surface at different radial coordinates.
        
        The relationship is given by integrating the gradient of the sag over R.
        '''
        # initial: constant of integration
        sag_R = cumulative_trapezoid(self.grad_sag2(), self.R, initial=0)
        
        if plot:
            self.plot(sag_R, self.R, "Sag of Surface 2", "Output radial coordinate R", f"{self.type} Beam Shaper Surface 2 Sag")
            
        return sag_R
        
    def ls_fit(self, 
               ea1: Optional[EvenAsphere] = None,
               ea2: Optional[EvenAsphere] = None, 
               fit_type: str = "sag", 
               bounds: dict = {'surface1': {'vertex_r_min': -10000, 'vertex_r_max': 10000, 'k_min': -1000, 'k_max': 1000},
                              'surface2': {'vertex_r_min': -10000, 'vertex_r_max': 10000, 'k_min': -1000, 'k_max': 1000}},
               verbose: bool = False,
               compare: bool = False,
               ) -> dict:
        
        '''
        Fits the sag or gradient of sag of the specified surface with an even aspheric surface equation using least squares optimization.
        
        Args:
            vertex_r (float): Initial guess for vertex radius of curvature.
            k (float): Initial guess for conic constant.
            coeffs (dict): Initial guess for higher-order even aspheric coefficients.
            fit_type (str): Either "sag" or "grad_sag", indicating which quantity to fit.
            fit_surface (int): Either 1 or 2, indicating which surface to fit.
            bounds (tuple): Bounds for the optimization parameters.
            verbose (bool): If True, prints detailed optimization information.
        '''
        
        z_data = self.sag1() if fit_type == "sag" else self.grad_sag1()
        Z_data = self.sag2() if fit_type == "sag" else self.grad_sag2()
        
        s1_bounds = bounds['surface1']
        s2_bounds = bounds['surface2']
        
        vr1_min = s1_bounds['vertex_r_min']
        vr1_max = s1_bounds['vertex_r_max']
        k1_min = s1_bounds['k_min']
        k1_max = s1_bounds['k_max']
        
        vr2_min = s2_bounds['vertex_r_min']
        vr2_max = s2_bounds['vertex_r_max']
        k2_min = s2_bounds['k_min']
        k2_max = s2_bounds['k_max']
        
        # Get initial parameter list
        coeffs_list1 = [ea1.coefficients.get(i, 0.0) for i in sorted(ea1.coefficients.keys())]
        p01 = [ea1.vertex_r, ea1.k] + coeffs_list1
        
        coeffs_list2 = [ea2.coefficients.get(i, 0.0) for i in sorted(ea2.coefficients.keys())]
        p02 = [ea2.vertex_r, ea2.k] + coeffs_list2
        
        p0 = np.array(p01 + p02, dtype=float)
        l1, l2 = len(p01), len(p02)
        
        num_coeffs1 = len(coeffs_list1)
        num_coeffs2 = len(coeffs_list2)
        
        lb_s1 = [vr1_min, k1_min] + [-np.inf]*num_coeffs1
        ub_s1 = [vr1_max, k1_max] + [np.inf]*num_coeffs1
        lb_s2 = [vr2_min, k2_min] + [-np.inf]*num_coeffs2
        ub_s2 = [vr2_max, k2_max] + [np.inf]*num_coeffs2
        
        lb = np.array(lb_s1 + lb_s2, dtype=float)
        ub = np.array(ub_s1 + ub_s2, dtype=float)
        
        bounds_tuple = (lb, ub)
        
        def residuals(params):
            '''
            Computes the residuals between the data and the fitted aspheric surface for later optimization.
            
            Args:
                params: 1D vector
            '''
            
            params1 = params[:l1]
            params2 = params[l1:l1+l2]
            
            vertex_r1_fit = params1[0]
            k1_fit = params1[1]
            coeffs1_fit = {4 + 2*i: params1[i + 2] for i in range(len(params1) - 2)}
            ea1_fit = EvenAsphere(r_max=self.r_max, vertex_r=vertex_r1_fit, k=k1_fit, coefficients=coeffs1_fit, num_samples=self.num_samples)
            z_fit = ea1_fit.sag() if fit_type == "sag" else ea1_fit.grad_sag()
            
            # Ensure the paraxial effective focal length to be infinity
            params2[0] = self.d * (self.n - 1) + vertex_r1_fit
            
            vertex_r2_fit = params2[0]
            k2_fit = params2[1]
            coeffs2_fit = {4 + 2*i: params2[i + 2] for i in range(len(params2) - 2)}
            ea2_fit = EvenAsphere(r_max = self.R_max, vertex_r=vertex_r2_fit, k = k2_fit, coefficients=coeffs2_fit, num_samples=self.num_samples)
            Z_fit = ea2_fit.sag() if fit_type == 'sag' else ea2_fit.grad_sag()
            
            return np.concatenate([(z_data - z_fit), (Z_data - Z_fit)])
        
        # Perform least squares optimization, trf for Trust Region Reflective algorithm
        result = least_squares(residuals, p0, bounds = bounds_tuple, method='trf', ftol=1e-10, xtol=1e-10, gtol=1e-10, verbose=2 if verbose else 0)
        
        x=result.x
        p1 = x[:l1]
        p2 = x[l1:l1+l2]
        
        fitted_vr1, fitted_k1 = p1[0], p1[1]
        fitted_coeffs1 = {4+2*i: p1[i + 2] for i in range(len(p1) - 2)}
        
        fitted_vr2, fitted_k2 = p2[0], p2[1]
        fitted_coeffs2 = {4+i*2: p2[i + 2] for i in range(len(p2) - 2)}
                
        rms = np.sqrt(np.mean(residuals(result.x)**2))
        
        if compare:
            ea1_fit = EvenAsphere(
                r_max = self.r_max, 
                vertex_r = fitted_vr1,
                k = fitted_k1,
                coefficients = fitted_coeffs1,
                num_samples = self.num_samples
            )
            ea2_fit = EvenAsphere(
                r_max = self.R_max,
                vertex_r = fitted_vr2,
                k = fitted_k2,
                coefficients = fitted_coeffs2,
                num_samples = self.num_samples
            )
            r = self.r
            z_data = self.sag1()
            R = self.R
            Z_data = self.sag2()
                
            z_fitted = ea1_fit.sag()
            Z_fitted = ea2_fit.sag()
            
            self.plot(r, z_data, f"{fit_type} Data", f"Radial Coordinate", f"{self.type} Beam Shaper Surface 1 {fit_type} Data")
            self.plot(r, z_fitted, f"Fitted {fit_type}", f"Radial Coordinate", f"{self.type} Beam Shaper Surface 1 Fitted {fit_type}")
            self.plot(r, z_data - z_fitted, f"Residuals of {fit_type}", f"Radial Coordinate", f"{self.type} Beam Shaper Surface 1 {fit_type} Residuals")
            
            self.plot(R, Z_data, f"{fit_type} Data", f"Radial Coordinate", f"{self.type} Beam Shaper Surface 2 {fit_type} Data")
            self.plot(R, Z_fitted, f"Fitted {fit_type}", f"Radial Coordinate", f"{self.type} Beam Shaper Surface 2 Fitted {fit_type}")
            self.plot(R, Z_data - Z_fitted, f"Residuals of {fit_type}", f"Radial Coordinate", f"{self.type} Beam Shaper Surface 2 {fit_type} Residuals")
        
        return {
            "surface1": {"vertex_r": fitted_vr1, "k": fitted_k1, "coefficients": fitted_coeffs1},
            "surface2": {"vertex_r": fitted_vr2, "k": fitted_k2, "coefficients": fitted_coeffs2},
            "rms": rms,
            "cost": result.cost,
            "success": result.success,
            "message": result.message,
            "nfev": result.nfev
        }
        
    '''def fit_compare(self,
                    ea: EvenAsphere, 
                    fit_surface: int = 1):
        '''
        Compares the fitted aspheric surface with the original sag or gradient of sag.
            
        Args:
            fit_surface (int): Either 1 or 2, indicating which surface to fit.
            fit_type (str): Either "sag" or "grad_sag", indicating which quantity to fit.
        '''
        sag_fit_result = self.ls_fit(fit_type="sag")
            
        if fit_surface == 1:    
            ea_fit = EvenAsphere(
                r_max = self.r_max, 
                vertex_r = fit_result['surface1']['vertex_r'],
                k = fit_result['surface1']['k'],
                coefficients = fit_result['surface1']['coefficients'],
                num_samples = self.num_samples
            )
            r = self.r
            data = self.sag1()
        else:
            ea_fit = EvenAsphere(
                r_max = self.R_max,
                vertex_r = fit_result['surface2']['vertex_r'],
                k = fit_result['surface2']['k'],
                coefficients = fit_result['surface2']['coefficients'],
                num_samples = self.num_samples
            )
            r = self.R
            data = self.sag2()
                
        fitted_data = ea_fit.sag() if fit_type == "sag" else ea_fit.grad_sag()
            
        self.plot(r, data, f"{fit_type} Data", f"Radial Coordinate", f"{self.type} Beam Shaper Surface {fit_surface} {fit_type} Data")
        self.plot(r, fitted_data, f"Fitted {fit_type}", f"Radial Coordinate", f"{self.type} Beam Shaper Surface {fit_surface} Fitted {fit_type}")
        self.plot(r, data - fitted_data, f"Residuals of {fit_type}", f"Radial Coordinate", f"{self.type} Beam Shaper Surface {fit_surface} {fit_type} Residuals")'''