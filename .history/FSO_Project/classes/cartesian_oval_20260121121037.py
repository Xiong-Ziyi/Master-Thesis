import numpy as np
from scipy.optimize import least_squares

from .surfaces import EvenAsphere

class CartesianOvalCollimator:
    
    
    def __init__(self, z_0, n, r_max, num_samples=100):
        self.z_0 = z_0
        self.n = n
        self.r_max = r_max
        self.num_samples = num_samples
        self.r = np.linspace(0, r_max, num_samples)
        
    def sag(self) -> np.ndarray:
        term1 = self.r**2 / (self.n**2 - 1)
        term2 = self.z_0 / (self.n + 1)
        
        sag = np.sqrt(term1 + term2**2) - term2
        return sag
        
    def even_aspheric_fitting(self, 
                              ea: EvenAsphere,
                              
                              ) -> EvenAsphere:
        
        
        sag_cartesian = self.sag()
        def residuals(coeffs):
            ea.coefficients = {4: coeffs[0], 6: coeffs[1], 8: coeffs[2]}
            sag_ea = ea.sag()
            return sag_cartesian - sag_ea
        
        initial_guess = [0.0, 0.0, 0.0]
        result = least_squares(residuals, initial_guess)
        ea.coefficients = {4: result.x[0], 6: result.x[1], 8: result.x[2]}
        return ea