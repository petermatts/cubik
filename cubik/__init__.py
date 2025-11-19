from . import moves as _moves_module
from . import cubik as _cubik_module
globals().update({k: getattr(_cubik_module, k)
                  for k in dir(_cubik_module) if not k.startswith('_')})
del _cubik_module


class _MovesFiltered:
    def __init__(self, module):
        self._module = module

    def __getattr__(self, name):
        # Expose anything that doesn't start with _
        if name.startswith("_"):
            raise AttributeError(f"'moves' has no attribute '{name}'")
        return getattr(self._module, name)

    def __dir__(self):
        # List everything except private names
        return [name for name in dir(self._module) if not name.startswith("_") and name != "cvar"]


# Replace the original moves module with the filtered version
moves = _MovesFiltered(_moves_module)
del _moves_module
