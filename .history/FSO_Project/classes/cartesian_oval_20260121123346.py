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
                              bounds: dict = {'vertex_r_min': -10000, 'vertex_r_max': 10000, 'k_min': -100, 'k_max': 100},
                              verbose: bool = False,
                              compare: bool = False 
                              ) -> EvenAsphere:
        
        if ea.r_max != self.r_max:
            raise ValueError("Even aspheric r_max must be equal to Cartesian val r_max.")
        
        if ea.num_samples != self.num_samples:
            raise ValueError("Even aspheric num_samples must be equal to Cartesian oval num_samples.")
        
        sag_cartesian = self.sag()
        