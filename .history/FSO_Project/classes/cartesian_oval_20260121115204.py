import numpy as np

class CartesianOvalCollimator:
    def __init__(self, z_0, n, r_max, num_samples=100):
        self.z_0 = z_0
        self.n = n
        self.r_max = r_max
        self.num_samples = num_samples
        self.r = np.linspace(0, r_max, num_samples)
        
    def sag(self):
        term1 = self.r**2 / (self.n**2 - 1)
        term2 = self.z_0**2 / (self.n + 1)**2
        