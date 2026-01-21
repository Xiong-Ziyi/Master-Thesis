import numpy as np

class CartesianOvalCollimator:
    def __init__(self, z_0, n):
        self.z_0 = z_0
        self.n = n
        
    def sag(self):
        