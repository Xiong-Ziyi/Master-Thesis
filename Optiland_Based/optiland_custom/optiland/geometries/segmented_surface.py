"""
Segmented Even Asphere Geometry

The Segmented Even Asphere Geometry represents a surface with two zones, each
characterized by an independent even asphere.

Definition:

if r < r1:
    Z1 = (c1*r^2) / (1 + sqrt(1 - (1+k1)*c1^2*r^2))
       + a12*r^2 + a14*r^4 + a16*r^6 + a18*r^8 + a110*r^10 + a112*r^12 + ...
elif r > r1:
    Z2 = (c2*r^2) / (1 + sqrt(1 - (1+k2)*c2^2*r^2))
       + a22*r^2 + a24*r^4 + a26*r^6 + a28*r^8 + a210*r^10 + a212*r^12 + ...
else:
    Z1 = Z2

where:
- r^2 = x^2 + y^2
- c_i is curvature
- k_i is conic constant
- a_ij are aspherical coefficients

Ziyi Xiong, 2025/12
"""

from __future__ import annotations

import optiland.backend as be
from optiland.coordinate_system import CoordinateSystem
from optiland.geometries.newton_raphson import NewtonRaphsonGeometry


class SegmentedSurface(NewtonRaphsonGeometry):
    """
    Rotationally symmetric segmented even aspherical surface.
    """

    def __init__(
        self,
        coordinate_system: CoordinateSystem,
        split_radius: float,
        cv1: float,
        cv2: float,
        k1: float = 0,
        k2: float = 0,
        a1=None,
        a2=None,
        tol: float = 1e-10,
        max_iter: int = 100,
    ):
        if a1 is None:
            a1 = {2: 0.0, 4: 0.0, 6: 0.0, 8: 0.0}
        if a2 is None:
            a2 = {2: 0.0, 4: 0.0, 6: 0.0, 8: 0.0}

        # Initialize parent class with center zone parameters
        super().__init__(coordinate_system, cv1, k1, tol, max_iter)

        self.split_radius = split_radius
        self.cv1 = cv1
        self.cv2 = cv2
        self.k1 = k1
        self.k2 = k2

        self.powers1 = list(a1.keys())
        self.powers2 = list(a2.keys())

        for power, val in a1.items():
            setattr(self, f"z1_c{power}", val)

        for power, val in a2.items():
            setattr(self, f"z2_c{power}", val)

    def __str__(self):
        return "Segmented Surface"

    def _get_coeffs(self, zone_idx, power):
        return getattr(self, f"z{zone_idx}_c{power}")

    def _eval_sag_grad(self, x, y, cv, k, zone_idx, powers):
        r2 = x**2 + y**2
        r = be.sqrt(r2)
        c = 1.0 / cv if cv != 0 else 0.0

        # Conic term
        sqrt_term = be.sqrt(1 - (1 + k) * c**2 * r2)
        z_conic = (c * r2) / (1 + sqrt_term)
        dzdr_conic = c * r / sqrt_term

        # Polynomial term
        z_poly = 0.0
        dzdr_poly = 0.0

        for p in powers:
            val = self._get_coeffs(zone_idx, p)
            z_poly += val * r**p
            dzdr_poly += p * val * r ** (p - 1)

        z = z_conic + z_poly
        dzdr = dzdr_conic + dzdr_poly

        r_safe = be.where(r == 0, 1e-12, r)
        dzdx = dzdr * (x / r_safe)
        dzdy = dzdr * (y / r_safe)

        return z, dzdx, dzdy

    def sag(self, x=0, y=0):
        r = be.sqrt(x**2 + y**2)

        z_split1, _, _ = self._eval_sag_grad(
            self.split_radius, 0.0, self.cv1, self.k1, 1, self.powers1
        )
        z_split2, _, _ = self._eval_sag_grad(
            self.split_radius, 0.0, self.cv2, self.k2, 2, self.powers2
        )

        offset = z_split1 - z_split2

        z1, _, _ = self._eval_sag_grad(x, y, self.cv1, self.k1, 1, self.powers1)
        z2, _, _ = self._eval_sag_grad(x, y, self.cv2, self.k2, 2, self.powers2)

        return be.where(r < self.split_radius, z1, z2 + offset)

    def _surface_normal(self, x, y):
        r = be.sqrt(x**2 + y**2)

        _, dzdx1, dzdy1 = self._eval_sag_grad(
            x, y, self.cv1, self.k1, 1, self.powers1
        )
        _, dzdx2, dzdy2 = self._eval_sag_grad(
            x, y, self.cv2, self.k2, 2, self.powers2
        )

        dzdx = be.where(r < self.split_radius, dzdx1, dzdx2)
        dzdy = be.where(r < self.split_radius, dzdy1, dzdy2)

        mag = be.sqrt(dzdx**2 + dzdy**2 + 1.0)

        nx = dzdx / mag
        ny = dzdy / mag
        nz = -1.0 / mag

        return nx, ny, nz

    def to_dict(self):
        data = super().to_dict()
        data.update(
            {
                "split_radius": self.split_radius,
                "cv1": self.cv1,
                "cv2": self.cv2,
                "k1": self.k1,
                "k2": self.k2,
                "a1": {p: getattr(self, f"z1_c{p}") for p in self.powers1},
                "a2": {p: getattr(self, f"z2_c{p}") for p in self.powers2},
            }
        )
        return data

    @classmethod
    def from_dict(cls, data):
        required_keys = {"cs", "split_radius", "cv1", "cv2", "a1", "a2"}
        if not required_keys.issubset(data):
            missing = required_keys - data.keys()
            raise ValueError(f"Missing required keys: {missing}")

        cs = CoordinateSystem.from_dict(data["cs"])

        return cls(
            cs,
            data["split_radius"],
            data["cv1"],
            data["cv2"],
            data.get("k1", 0),
            data.get("k2", 0),
            data.get("a1"),
            data.get("a2"),
            data.get("tol", 1e-10),
            data.get("max_iter", 100),
        )
