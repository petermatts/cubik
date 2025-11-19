from . import moves as Moves
from . import cubik as _cubik_module
globals().update({k: getattr(_cubik_module, k)
                  for k in dir(_cubik_module) if not k.startswith('_')})
del _cubik_module

__all__ = [k for k in globals().keys()
           if not k.startswith("_")]
