import numpy as np

class SuperGaussian:
    def __init__(self, amplitude, center, width, order):
        self.amplitude = amplitude
        self.center = center
        self.width = width
        self.order = order

    def evaluate(self, x):
        exponent = -((x - self.center) / self.width) ** self.order
        return self.amplitude * np.exp(exponent)