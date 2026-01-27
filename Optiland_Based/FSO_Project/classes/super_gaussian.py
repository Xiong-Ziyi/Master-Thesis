import numpy as np
import matplotlib.pyplot as plt

class SuperGaussianIntensity:
    
    '''
         A class to represent a Super-Gaussian function.

         By Ziyi Xiong 2026/1

         Args:
             amplitude (float): The peak value of the Super-Gaussian.
             center (float): The center position of the Super-Gaussian.
             width (float): The width parameter controlling the spread.
             order (int): The order of the Super-Gaussian, determining the steepness.
             max_coord (float): The maximum coordinate value for sampling.
             num_samples (int): The number of samples to generate.

         '''
    
    def __init__(self, Intensity: float = 1, center: float = 0, width: float = 1, order: int = 2, max_coord: float = 10, num_samples: int = 1000):
        self.Intensity = Intensity
        self.center = center
        self.width = width
        self.order = order
        self.max_coord = max_coord
        self.num_samples = num_samples
        self.x_values = np.linspace(-self.max_coord, self.max_coord, self.num_samples)
        
    def profile(self):
        exponent = -((self.x_values - self.center) / self.width) ** self.order
        return self.Intensity * np.exp(2*exponent)
    
    def plot(self):
        y_values = self.profile()
        
        plt.figure(figsize=(8, 5))
        plt.plot(self.x_values, y_values, label=f'Super-Gaussian Intensity (order={self.order})')
        plt.title('Super-Gaussian Intensity Profile')
        plt.xlabel('x')
        plt.ylabel('Intensity')
        plt.grid(True)
        plt.legend()
        plt.show()