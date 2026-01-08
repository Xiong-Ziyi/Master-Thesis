import numpy as np


class BeamShaper:
    """
    This class is to model a Keplerian or Galilean beam shaper.

    This implementation is based on the formula provided in:
    - Title: "Laser Beam Shaping: Theory and Techniques"
      Editor: Fred M. Dickey
      Chapter: 7
      Edition: 2nd

    Args:
        omega_0 (float): The radius of the input Gaussian beam waist.
        R_max (float): The maximum output radial coordinate.
        r_max (float): The maximum input radial coordinate.
        d (float): The thickness of the first lens' second surface.
        n (float): The refractive index of the two lens.
        type (str): Either "Keplerian" or "Galilean", indicatinig the type of beam shaper.
        approx (bool): indicates if the Longitudinal Aberration is approximated by parabolic
            function and Taylor expansion.
    """

    def __init__(
        self,
        omega_0: float,
        R_max: float,
        r_max: float,
        d: float,
        n: float,
        type: str = "Keplerian",
        approx: bool = True,
    ):
        self.omega_0 = omega_0
        self.R_max = R_max
        self.r_max = r_max
        self.d = d
        self.n = n

        if type not in ["Keplerian", "Galilean"]:
            raise ValueError("type must be either 'Keplerian' or 'Galilean'")
        self.type = type

        self.approx = approx

    @property
    def _B(self) -> float:
        """
        Returns a intermediate coefficient B given by Equation 7.13.
        """
        denom = np.sqrt(1 - np.exp(-2 * (self.r_max / self.omega_0) ** 2))
        if self.type == "Keplerian":
            return -self.R_max / denom
        else:
            return self.R_max / denom

    def s_prime(self, r) -> float:
        """
        Returns the object distance after the first lens at different ray height,
        given by Equation 7.16.
        """
        sqrt = np.sqrt(1 - np.exp(-2 * r**2 / self.omega_0**2))
        s_prime = self.d / (1 - (self._B / r) * sqrt)
        return s_prime

    @property
    def s_prime_zero(self) -> float:
        """
        Returns paraxial object distance, which is also equal to effective focal length f_1,
        given by Equation 7.17 and 7.18.
        """
        if self.approx:
            return self.d / (1 - np.sqrt(2) * self._B / self.omega_0)
        else:
            return self.s_prime(1e-15)

    @property
    def Delta_s_prime(self) -> float:
        """
        Returns the difference between real object distance and paraxial object distance,
        which is actually Longitudinal Aberration (LA), given by Equation 7.19, 7.20 and 7.21.
        """
        return self.s_prime(self.omega_0) - self.s_prime_zero

    @property
    def k_1(self) -> float:
        """
        Returns the conic constant of the first aspherical surface.
        """
        coeff = -2 * self.Delta_s_prime * self.s_prime_zero * (self.n - 1) ** 2
        return coeff / (self.omega_0**2) - self.n**2 

    @property
    def r_c1(self) -> float:
        """
        Returns the vertex radius of the first aspherical surface.
        """
        return -self.s_prime_zero * (self.n - 1)

    @property
    def k_2(self) -> float:
        """
        Returns the conic constant of the second aspherical surface.
        """
        coeff = self.s_prime_zero * self.k_1 + self.n**2 * self.d
        return coeff / (self.s_prime_zero - self.d)

    @property
    def r_c2(self) -> float:
        """
        Returns the vertex radius of the second aspherical surface.
        """
        return (self.n - 1) * (self.d - self.s_prime_zero)

    @property
    def xpan_ratio(self) -> float:
        """
        Returns the expansion ratio of the beam shaper.
        """
        f_1 = self.s_prime_zero
        f_2 = self.d - self.s_prime_zero
        return np.abs(f_2 / f_1)

    @property
    def apodization_factor(self) -> float:
        """
        Returns the apodization factor of the beam shaper.
        """
        return (self.r_max / self.omega_0)**2

    @property
    def result(self) -> dict:
        """
        Returns a dictionary containing parameters.
        """
        return {
            "r_c1": float(self.r_c1),
            "r_c2": float(self.r_c2),
            "k_1": float(self.k_1),
            "k_2": float(self.k_2),
        }
