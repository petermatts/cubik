from cubik import Cube, Moves
from cubik.solver import Solver, Heuristic, IDA_STAR


class ZeroHeuristic(Heuristic):
    def evaluate(self, states):
        print("hola")
        return [0.0] * len(states)


cube = Cube()
cube = cube.apply(Moves.R)

solver = Solver(
    IDA_STAR,
    5,
    1000.0,
    False,
    True,
    [Moves.R, Moves.R_prime],
    ZeroHeuristic()
)

solution = solver.solve(cube)

print(solution.solved)
print(solution.solution_moves)
