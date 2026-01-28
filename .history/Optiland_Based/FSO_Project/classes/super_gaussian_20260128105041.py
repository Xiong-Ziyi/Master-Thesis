import numpy as np
import matplotlib.pyplot as plt
from typing import Literal, Optional
import torch

from .backend import Backend, ArrayLike

class SuperGaussianIntensity:
    '''
         A class to represent a Super-Gaussian irradiance profile.

         By Ziyi Xiong 2026/1

         Args:
             amplitude (float): The peak value of the Super-Gaussian.
             center (float): The center position of the Super-Gaussian.
             width (float): The width parameter controlling the spread.
             order (int): The order of the Super-Gaussian, determining the steepness.
             max_coord (float): The maximum coordinate value for sampling.
             num_samples (int): The number of samples to generate.

         '''
    
    def __init__(self, 
                 peak_irradiance: float = 1, 
                 flattop_radius: float = 1, 
                 steepness: float = 2, 
                 max_coord: float = 10, 
                 num_samples: int = 1000,
                 backend: Literal['numpy', 'torch'] = 'numpy',
                 device: Literal['cpu', 'cuda'] = 'cpu',
                 dtype: Optional["torch.dtype"] = None
                 ):
        self.be = Backend(name=backend, device=device, dtype=dtype)
        
        self.peak_irradiance = self.be.tensor(peak_irradiance)
        self.flattop_radius = self.be.tensor(flattop_radius) 
        self.steepness = self.be.tensor(steepness)
        self.max_coord = self.be.tensor(max_coord)
        self.num_samples = self.be.tensor(num_samples)
        self.coords = np.linspace(-self.max_coord, self.max_coord, self.num_samples)
        
    def profile(self):
        exponent = -((self.x_values - self.center) / self.width) ** self.order
        return self.peak_irradiance * np.exp(2*exponent)
    
    def plot(self):
        y_values = self.profile()
        
        plt.figure(figsize=(8, 5))
        plt.plot(self.x_values, y_values, label=f'Super-Gaussian Irradiance (order={self.order})')
        plt.title('Super-Gaussian Irradiance Profile')
        plt.xlabel('x')
        plt.ylabel('Irradiance')
        plt.grid(True)
        plt.legend()
        plt.show()