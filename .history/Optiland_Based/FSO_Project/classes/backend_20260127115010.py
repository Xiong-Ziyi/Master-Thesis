from dataclasses import dataclass
from typing import Literal, Optional, Union

import torch 
import numpy as np

ArrayLike = Union[float, int, np.ndarray, torch.Tensor]

@dataclass(frozen=True)
class Backend:
    """
    Small reusable backend adapter:
    - be.sqrt / be.exp / be.abs work for numpy or torch
    - be.tensor(x) converts to torch tensor if torch backend, otherwise returns x
    - be.scalar(x) converts backend scalar to python float (for warnings/result dict)
    """
    name: Literal["numpy", "torch"] = "numpy"
    device: Literal["cpu", "cuda"] = "cpu"
    dtype: Optional["torch.dtype"] = None  # type: ignore[name-defined]

    def __post_init__(self):
        if self.name == "torch":
            if torch is None:
                raise ImportError("Backend(name='torch') requested but torch is not installed.")
            object.__setattr__(self, "dtype", self.dtype if self.dtype is not None else torch.float32)

    @property
    def is_torch(self) -> bool:
        return self.name == "torch"

    def tensor(self, x: ArrayLike) -> ArrayLike:
        """Convert x to torch.Tensor if torch backend. Numpy backend returns x unchanged."""
        if not self.is_torch:
            return x
        assert torch is not None
        if isinstance(x, torch.Tensor):
            return x.to(device=self.device, dtype=self.dtype)
        return torch.tensor(x, device=self.device, dtype=self.dtype)

    def sqrt(self, x: ArrayLike) -> ArrayLike:
        if not self.is_torch:
            return np.sqrt(x)
        assert torch is not None
        return torch.sqrt(self.tensor(x))

    def exp(self, x: ArrayLike) -> ArrayLike:
        if not self.is_torch:
            return np.exp(x)
        assert torch is not None
        return torch.exp(self.tensor(x))

    def abs(self, x: ArrayLike) -> ArrayLike:
        if not self.is_torch:
            return np.abs(x)
        assert torch is not None
        return torch.abs(self.tensor(x))

    def scalar(self, x: ArrayLike) -> float:
        """Backend scalar -> python float."""
        if not self.is_torch:
            return float(x)
        assert torch is not None
        t = self.tensor(x)
        assert isinstance(t, torch.Tensor)
        return float(t.detach().cpu().item())