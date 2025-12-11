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
Moves = _MovesFiltered(_moves_module)
del _moves_module

for elem in ['StringVector', 'SwigPyIterator', 'Uint32Vector', '_MovesFiltered', '_cubik', '_cubik_moves']:
    if elem in globals():
        del globals()[elem]
del elem
del globals()['cubik']
del globals()['moves']


__doc__ = """Cubik Package.

A lightweight Python package for manipulating and solving Rubik's Cubes. Created using C++, CMake, and SWIG for performance and ease of use."""
