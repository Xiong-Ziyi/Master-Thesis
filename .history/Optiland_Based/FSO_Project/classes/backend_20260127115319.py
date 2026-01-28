from dataclasses import dataclass
from typing import Literal, Optional, Union

import torch 
import numpy as np

ArrayLike = Union[float, int, np.ndarray, "torch.Tensor"]

@dataclass(frozen=True)
class Backend:
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
        if not self.is_torch:
            return x
        assert torch is not None
        if isinstance(x, torch.Tensor):
            return x.to(device=self.device, dtype=self.dtype)  # type: ignore[arg-type]
        return torch.tensor(x, device=self.device, dtype=self.dtype)  # type: ignore[arg-type]

    def sqrt(self, x: ArrayLike) -> ArrayLike:
        if not self.is_torch:
            return np.sqrt(x)
        assert torch is not None
        t = self.tensor(x)
        assert isinstance(t, torch.Tensor)  # <-- narrows type for the checker
        return torch.sqrt(t)

    def exp(self, x: ArrayLike) -> ArrayLike:
        if not self.is_torch:
            return np.exp(x)
        assert torch is not None
        t = self.tensor(x)
        assert isinstance(t, torch.Tensor)  # <-- narrows type for the checker
        return torch.exp(t)

    def abs(self, x: ArrayLike) -> ArrayLike:
        if not self.is_torch:
            return np.abs(x)
        assert torch is not None
        t = self.tensor(x)
        assert isinstance(t, torch.Tensor)  # <-- narrows type for the checker
        return torch.abs(t)

    def scalar(self, x: ArrayLike) -> float:
        if not self.is_torch:
            return float(x)
        assert torch is not None
        t = self.tensor(x)
        assert isinstance(t, torch.Tensor)  # <-- narrows type for the checker
        return float(t.detach().cpu().item())