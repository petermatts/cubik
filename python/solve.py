from cubik import Cube, Moves
from cubik.solver import Solver, Heuristic, IDA_STAR


class ZeroHeuristic(Heuristic):
    def __init__(self):
        super().__init__()

    def evaluate(self, states):
        return [0.0] * len(states)


cube = Cube()
cube = cube.apply(Moves.R).apply(Moves.U)

h = ZeroHeuristic()
"""
! do not call ZeroHeuristic() in the constructor of Solver

 otherwise it will cause a segmentation fault when the solver tries
 to use the heuristic after it has been destroyed.

 Instead, create an instance of ZeroHeuristic and pass it to the
 Solver constructor.
"""
solver = Solver(
    IDA_STAR,
    5,
    1000.0,
    False,
    False,
    [Moves.R, Moves.R_prime, Moves.U, Moves.U_prime],
    h
)

solution = solver.solve(cube)

print(solution)

# print(solution.solved)
# print(" ".join(solution.solution_moves()))
