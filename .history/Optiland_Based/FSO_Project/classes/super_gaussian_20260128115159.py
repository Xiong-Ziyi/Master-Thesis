import matplotlib.pyplot as plt
from typing import Literal, Optional
import torch

from .backend import Backend, ArrayLike

class SuperGaussianIrradiance:
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
        self.num_samples = int(num_samples)
        self.coords = self.be.linspace(-self.max_coord, self.max_coord, self.num_samples)
        
    def profile(self) -> ArrayLike:
        X, Y = self.be.meshgrid(self.coords, self.coords, indexing='xy')
        R = self.be.sqrt(X**2 + Y**2)
        shape = self.be.exp(-2 * (R / self.flattop_radius) ** self.steepness)
        return self.peak_irradiance * shape
    
    def profile_1d(self) -> ArrayLike:
        X = self.coords
        shape = self.be.exp(-2 * (X / self.flattop_radius) ** self.steepness)
        return self.peak_irradiance * shape
    
    def plot_cross_section(self):
        y_values = self.profile_1d()
        
        X_np = self.be.to_numpy(self.coords)
        y_np = self.be.to_numpy(y_values)
        
        plt.figure(figsize=(8, 5))
        plt.plot(X_np, y_np, label=f'Super-Gaussian Irradiance (order={self.be.scalar(self.steepness)})')
        plt.title('Super-Gaussian Irradiance Profile')
        plt.xlabel('x')
        plt.ylabel('Irradiance')
        plt.grid(True)
        plt.legend()
        plt.show()
        
    def plot_2d(self):
        irradiance = self.profile()
        
        X_np = self.be.to_numpy(self.coords)
        Y_np = self.be.to_numpy(self.coords)
        I_np = self.be.to_numpy(irradiance)
        
        plt.figure(figsize=(8, 6))
        plt.imshow(I_np, extent=(-self.be.scalar(self.max_coord), self.be.scalar(self.max_coord), 
                                 -self.be.scalar(self.max_coord), self.be.scalar(self.max_coord)),
                   origin='lower', cmap='viridis')
        plt.colorbar(label='Irradiance')
        plt.title('Super-Gaussian Irradiance Profile (2D)')
        plt.xlabel('x')
        plt.ylabel('y')
        plt.show()