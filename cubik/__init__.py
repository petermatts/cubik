from types import SimpleNamespace
from . import moves as _moves_module
from . import cubik as _cubik_module
from . import solver as _solver_module

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


class _SolverFiltered:
    def __init__(self, module):
        self._module = module

        bad_attrs = ['StringVector', 'FloatVector', 'CubeVector',
                     'weakref', 'SwigPyIterator', 'SHARED_PTR_DISOWN']
        for attr in bad_attrs:
            if hasattr(self._module, attr):
                delattr(self._module, attr)

        self.algorithms = SimpleNamespace(
            IDA_STAR=module.IDA_STAR,
            A_STAR=module.A_STAR,
            WEIGHTED_A_STAR=module.WEIGHTED_A_STAR
        )

        # Remove them from top-level solver namespace
        for name in ["IDA_STAR", "A_STAR", "WEIGHTED_A_STAR"]:
            if hasattr(self._module, name):
                delattr(self._module, name)

    def __getattr__(self, name):
        # Expose anything that doesn't start with _
        if name.startswith("_"):
            raise AttributeError(f"'solver' has no attribute '{name}'")
        return getattr(self._module, name)

    def __dir__(self):
        module_names = [
            name for name in dir(self._module)
            if not name.startswith("_") and name != "cvar"
        ]

        wrapper_names = [
            name for name in self.__dict__.keys()
            if not name.startswith("_")
        ]

        return sorted(set(module_names + wrapper_names))


# Replace the original moves module with the filtered version
Moves = _MovesFiltered(_moves_module)
del _moves_module

solver = _SolverFiltered(_solver_module)
del _solver_module

for elem in ['StringVector', 'SwigPyIterator', 'Uint32Vector', '_MovesFiltered', '_SolverFiltered', '_cubik', '_cubik_moves']:
    if elem in globals():
        del globals()[elem]
del elem
del globals()['cubik']
del globals()['moves']


__doc__ = """Cubik Package.

A lightweight Python package for manipulating and solving Rubik's Cubes. Created using C++, CMake, and SWIG for performance and ease of use."""
