"""
Segmented Surface's Ring Zone Conic Constant Variable Module

This module contains the K2Variable class, which represents an optimization
variable for the ring zone's conic constant of a segmented surface in an
optic system. The class inherits from VariableBehavior and is used during
optimization of conic surfaces.

Ziyi Xiong, 2025
"""

from __future__ import annotations

from optiland.optimization.scaling.identity import IdentityScaler
from optiland.optimization.variable.base import VariableBehavior


class K2Variable(VariableBehavior):
    """
    Variable for the ring zone's conic constant (k2) of a segmented surface.

    Args:
        optic (Optic): The optic object containing the surface.
        surface_number (int): Index of the surface in the optic.
        scaler (Scaler, optional): Scaler for the variable. Defaults to
            IdentityScaler().
        **kwargs: Additional keyword arguments passed to VariableBehavior.
    """

    def __init__(self, optic, surface_number, scaler=None, **kwargs):
        if scaler is None:
            scaler = IdentityScaler()
        super().__init__(optic, surface_number, scaler=scaler, **kwargs)

    def get_value(self):
        """
        Get the current ring zone conic constant.

        Returns:
            float: Current conic constant value.
        """
        return self._surfaces.surfaces[self.surface_number].geometry.k2

    def update_value(self, new_value):
        """
        Update the ring zone conic constant.

        Args:
            new_value (float): New conic constant value.
        """
        self.optic.set_k2(new_value, self.surface_number)

    def __str__(self):
        """
        String representation of the variable.

        Returns:
            str: Human-readable description.
        """
        return f"Ring Zone's Conic Constant, Surface {self.surface_number}"
