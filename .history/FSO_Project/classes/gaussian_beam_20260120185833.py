import numpy as np

class GaussianBeam:
    def __init__(self, wavelength, omega_0, index=1.0):
        self.wavelength = wavelength  # Wavelength of the beam in micrometers
        self.omega_0 = omega_0  # Waist radius at z=0 in micrometers
        self.index = index  # Refractive index of the medium

    @property
    def rayleigh_range(self):
        """Calculate the Rayleigh range of the Gaussian beam."""
        return np.pi * self.omega_0**2 / (self.wavelength / self.index)

    @property
    def div_angle(self):
        """Calculate the divergence angle of the Gaussian beam."""
        return (self.wavelength / self.index) / (np.pi * self.omega_0)
    
    def beam_radius(self, z):
        """Calculate the beam radius at a distance z from the waist."""
        z_R = self.rayleigh_range
        return self.omega_0 * np.sqrt(1 + (z / z_R)**2)

    def radius_of_curvature(self, z):
        """Calculate the radius of curvature of the beam's wavefront at distance z."""
        z_R = self.rayleigh_range()
        if z == 0:
            return np.inf  # At the waist, the radius of curvature is infinite
        return z * (1 + (z_R / z)**2)
    
    def div_angle_z(self, z):
        """Calculate the divergence angle at distance z from the waist."""
        omega_z = self.beam_radius(z)
        if z > self.rayleigh_range:
            return np.arctan(omega_z / z)
        else:
            raise ValueError("Non-paraxial divergence angle is only defined for z greater than the Rayleigh range.")
    
    @property
    def position(self):
        """Calculate the position parameter used in Zemax OpticStudio Non-sequential mode in millimeters."""
        theta = self.div_angle
        return (self.omega_0 / np.tan(theta)) * 1e-3