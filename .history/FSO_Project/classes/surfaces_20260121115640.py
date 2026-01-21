import numpy as np

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
