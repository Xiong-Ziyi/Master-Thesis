from dataclasses import dataclass
from typing import Literal, Optional, Union

import torch 
import numpy as np

ArrayLike = Union[float, int, np.ndarray, "torch.Tensor"]

# dataclass generates __init__ and other methods automatically like __repr__ and __eq__
@dataclass(frozen=True)
class Backend:
    '''
    Class to handle different computational backends (NumPy and PyTorch).
    
    by Ziyi Xiong, 2026/1
    
    Attributes:
        name (Literal["numpy", "torch"]): The name of the backend to use.
        device (Literal["cpu", "cuda"]): The device to use for PyTorch tensors.
        dtype (Optional[torch.dtype]): The data type for PyTorch tensors.
    '''
    # Necessary to list attributes at class level for dataclass
    name: Literal["numpy", "torch"] = "numpy"
    device: Literal["cpu", "cuda"] = "cpu"
    dtype: Optional["torch.dtype"] = None  

    # dataclass automatically generates __init__, but we need to customize post-init, specially for dataclass
    def __post_init__(self):
        if self.name == "torch":
            if torch is None:
                raise ImportError("Backend(name='torch') requested but torch is not installed.")
            # frozen=True prevents setting attributes normally, so use object.__setattr__
            object.__setattr__(self, "dtype", self.dtype if self.dtype is not None else torch.float32)

    @property
    def is_torch(self) -> bool:
        return self.name == "torch"

    def tensor(self, x: ArrayLike) -> ArrayLike:
        if not self.is_torch:
            return x
        assert torch is not None
        if isinstance(x, torch.Tensor):
            # Move to the correct device and dtype
            return x.to(device=self.device, dtype=self.dtype)  
        # Convert numpy array or scalar to torch tensor on the correct device and dtype
        return torch.tensor(x, device=self.device, dtype=self.dtype)  

    def sqrt(self, x: ArrayLike) -> ArrayLike:
        if not self.is_torch:
            return np.sqrt(x)
        assert torch is not None
        t = self.tensor(x)
        assert isinstance(t, torch.Tensor) 
        return torch.sqrt(t)

    def exp(self, x: ArrayLike) -> ArrayLike:
        if not self.is_torch:
            return np.exp(x)
        assert torch is not None
        t = self.tensor(x)
        assert isinstance(t, torch.Tensor)  
        return torch.exp(t)

    def abs(self, x: ArrayLike) -> ArrayLike:
        if not self.is_torch:
            return np.abs(x)
        assert torch is not None
        t = self.tensor(x)
        assert isinstance(t, torch.Tensor)  
        return torch.abs(t)

    def scalar(self, x: ArrayLike) -> float:
        if not self.is_torch:
            return float(x)
        assert torch is not None
        t = self.tensor(x)
        assert isinstance(t, torch.Tensor)  
        return float(t.detach().cpu().item())
    
    def meshgrid(self, X: ArrayLike, Y: ArrayLike, indexing: Literal['xy', 'ij'] ='xy'):
        if not self.is_torch:
            if isinstance(X, torch.Tensor) or isinstance(Y, torch.Tensor):
                raise TypeError("meshgrid received torch.Tensor inputs but backend is numpy.")
            return np.meshgrid(X, Y, indexing=indexing)
        assert torch is not None
        X = self.tensor(X)
        Y = self.tensor(Y)
        assert isinstance(X, torch.Tensor)
        assert isinstance(Y, torch.Tensor)
        return torch.meshgrid(X, Y, indexing=indexing)
    
    def linspace(self, start: ArrayLike, end: ArrayLike, steps: int) -> ArrayLike:
        if not self.is_torch:
            return np.linspace(start, end, steps)
        assert torch is not None
        start_t = self.tensor(start)
        end_t = self.tensor(end)
        assert isinstance(start_t, torch.Tensor)
        assert isinstance(end_t, torch.Tensor)
        return torch.linspace(start_t, end_t, steps, device=self.device, dtype=self.dtype)
    
    def to_numpy(self, x: ArrayLike) -> np.ndarray:
        if not self.is_torch:
            if isinstance(x, np.ndarray):
                return x
            else:
                return np.array(x)
        assert torch is not None
        t = self.tensor(x)
        assert isinstance(t, torch.Tensor)
        return t.detach().cpu().numpy()
        