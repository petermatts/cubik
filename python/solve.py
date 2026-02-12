from cubik import Cube, Moves
from cubik.solver import Solver, SolverConfig, Heuristic, IDA_STAR


class ZeroHeuristic(Heuristic):
    def evaluate(self, states):
        return [0.0] * len(states)


cube = Cube()
cube = cube.apply(Moves.R)
print(type(IDA_STAR))
config = SolverConfig(
    IDA_STAR,
    5,
    1000,
    1.0,
    False,
    True,
    [Moves.R, Moves.R_prime]
)

solver = Solver(config, ZeroHeuristic())
solution = solver.solve(cube)

print(solution.solved)
print(solution.solution_moves)
