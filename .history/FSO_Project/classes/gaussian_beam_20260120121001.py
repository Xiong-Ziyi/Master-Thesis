import numpy as np

class GaussianBeam:
    def __init__(self, wavelength, waist_radius, z0=0):
        self.wavelength = wavelength  # Wavelength of the beam
        self.waist_radius = waist_radius  # Waist radius at z=0

    def rayleigh_range(self):
        """Calculate the Rayleigh range of the Gaussian beam."""
        return np.pi * self.waist_radius**2 / self.wavelength

    def beam_radius(self, z):
        """Calculate the beam radius at a distance z from the waist."""
        z_R = self.rayleigh_range()
        return self.waist_radius * np.sqrt(1 + ((z - self.z0) / z_R)**2)

    def radius_of_curvature(self, z):
        """Calculate the radius of curvature of the beam's wavefront at distance z."""
        z_R = self.rayleigh_range()
        if z == self.z0:
            return np.inf  # At the waist, the radius of curvature is infinite
        return (z - self.z0) * (1 + (z_R / (z - self.z0))**2)

    def gouy_phase(self, z):
        """Calculate the Gouy phase shift at distance z."""
        z_R = self.rayleigh_range()
        return np.arctan((z - self.z0) / z_R)