import numpy as np

class SuperGaussian:
    
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
    
    def __init__(self, amplitude: float = 1, center: float = 0, width: float = 1, order: int = 2, max_coord: float = 10, num_samples: int = 1000):
        self.amplitude = amplitude
        self.center = center
        self.width = width
        self.order = order
        self.max_coord = max_coord
        self.num_samples = num_samples
        
    def evaluate(self, x):
        exponent = -((x - self.center) / self.width) ** self.order
        return self.amplitude * np.exp(exponent)
    
    def