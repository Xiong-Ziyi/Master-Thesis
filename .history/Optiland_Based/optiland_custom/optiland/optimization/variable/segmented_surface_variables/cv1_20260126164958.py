"""
Segmented Surface's Radius of the Center Zone Variable Module

This module contains the Cv1Variable class, which represents an optimization
variable for the center zone's radius of a segmented surface in an optic.
The class inherits from VariableBehavior.

Ziyi Xiong, 2025
"""

from __future__ import annotations

from optiland.optimization.scaling.linear import LinearScaler
from optiland.optimization.variable.base import VariableBehavior


class Cv1Variable(VariableBehavior):
    """
    Variable for the center zone's radius (cv1) of a segmented surface.

    Args:
        optic (Optic): The optic object containing the surface.
        surface_number (int): Index of the surface in the optic.
        scaler (Scaler, optional): Scaler for the variable. Defaults to a
            LinearScaler with factor=1/100 and offset=-1.0.
        **kwargs: Additional keyword arguments passed to VariableBehavior.
    """

    def __init__(self, optic, surface_number, scaler=None, **kwargs):
        if scaler is None:
            scaler = LinearScaler(factor=1 / 100.0, offset=-1.0)
        super().__init__(optic, surface_number, scaler=scaler, **kwargs)

    def get_value(self):
        """
        Get the current value of the center zone's radius.

        Returns:
            float: Current radius value.
        """
        return self._surfaces.surfaces[self.surface_number].geometry.cv1

    def update_value(self, new_value):
        """
        Update the center zone's radius.

        Args:
            new_value (float): New radius value.
        """
        self.optic.set_cv1(new_value, self.surface_number)

    def __str__(self):
        """
        String representation of the variable.

        Returns:
            str: Human-readable description.
        """
        return f"Center Zone's Radius, Surface {self.surface_number}"
