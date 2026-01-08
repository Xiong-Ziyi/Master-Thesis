import numpy as np
import matplotlib.pyplot as plt

class FermiDirac:
    '''
    Class to model a 1D Fermi-Dirac beam profile.

    By Ziyi Xiong 2026/01
    
    Args:
        R_max (float): The maximum radial coordinate.
        beta (float): The steepness parameter of the Fermi-Dirac function.
        num_samples (int): Number of samples to generate the profile.
    '''
    def __init__(self, R_max: float, beta: float, num_samples: int = 100):
        self.R_max = R_max
        self.beta = beta
        self.num_samples = num_samples
    
    @property    
    def y(self) -> list:
        r = np.linspace(0, self.R_max, self.num_samples)
        y = 1 / (1 + np.exp(self.beta * (r/self.R_max - 1)))
        return y
    
    def plot(self):
        r = np.linspace(0, self.R_max, self.num_samples)
        y = self.y
        plt.plot(r, y)
        plt.xlabel('Radius (r)')
        plt.ylabel('Irradiance Profile f(r)')
        plt.title('Fermi-Dirac Beam Profile')
        plt.grid()
        plt.show()