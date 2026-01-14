import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import cumulative_trapezoid
from scipy.optimize import least_squares 

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
        self.r = np.linspace(0, self.r_max, num_samples)
        self.R = np.linspace(0, self.R_max, num_samples)
        
        if beam_shaper.type not in ["Keplerian", "Galilean"]:
            raise ValueError("type must be either 'Keplerian' or 'Galilean'")
        
        self.type = beam_shaper.type
        self.num_samples = num_samples
        
    def plot(self, x: np.ndarray, y: np.ndarray, xlabel: str, ylabel: str, title: str):
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
               vertex_r = None, 
               k = None, 
               coeffs: dict = {}, 
               fit_type: str = "sag", 
               fit_surface: int = 1,
               bounds: tuple = ([-10000, -1000] , [10000, 1000]),
               verbose: bool = False
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
        
        if fit_surface == 1:
            r_data = self.r
            z_data = self.sag1() if fit_type == "sag" else self.grad_sag1()
        elif fit_surface == 2:
            r_data = self.R
            z_data = self.sag2() if fit_type == "sag" else self.grad_sag2()
        else:
            raise ValueError("fit_surface must be either 1 or 2, fit_type must be either 'sag' or 'grad_sag'")
        
        if vertex_r is None or k is None:
            initial = beam_shaper
            if fit_surface == 1:
                vertex_r = initial.r_c1
                k = initial.k_1
            else:
                vertex_r = initial.r_c2
                k = initial.k_2
        
        # Get initial parameter list
        coeffs_list = [coeffs.get(i, 0.0) for i in sorted(coeffs.keys())]
        p0 = [vertex_r, k] + coeffs_list
        
        def residuals(params):
            '''
            Computes the residuals between the data and the fitted aspheric surface for later optimization.
            '''
            vertex_r_fit = params[0]
            k_fit = params[1]
            coeffs_fit = {4 + 2*i: params[i + 2] for i in range(len(params) - 2)}
            ea = EvenAsphere(r_max=r_data[-1], vertex_r=vertex_r_fit, k=k_fit, coefficients=coeffs_fit, num_samples=len(r_data))
            z_fit = ea.sag() if fit_type == "sag" else ea.grad_sag()
            return z_data - z_fit
        
        # Perform least squares optimization, trf for Trust Region Reflective algorithm
        result = least_squares(residuals, p0, bounds = bounds, method='trf', ftol=1e-10, xtol=1e-10, gtol=1e-10, verbose=2 if verbose else 0)
        
        fitted_vr = result.x[0]
        fitted_k = result.x[1]
        fitted_coeffs = {4+2*i: result.x[i + 2] for i in range(len(result.x) - 2)}
        
        rms = np.sqrt(np.mean(residuals(result.x)**2))
        
        return {
            "vertex_r": fitted_vr,
            "k": fitted_k,
            "coefficients": fitted_coeffs,
            "rms": rms,
            "cost": result.cost,
            "success": result.success,
            "message": result.message,
            "nfev": result.nfev
        }
        