from cubik import Cube, Moves
import cubik.solver as solver
# import torch
# import torch.nn as nn
import numpy as np


# class CubeNet(nn.Module):
#     def __init__(self):
#         super().__init__()
#         self.net = nn.Sequential(
#             nn.Linear(6, 64),
#             nn.ReLU(),
#             nn.Linear(64, 64),
#             nn.ReLU(),
#             nn.Linear(64, 1)
#         )

#     def forward(self, x):
#         return self.net(x)


class ZeroHeuristic(solver.Heuristic):
    def __init__(self):
        super().__init__()

    def evaluate(self, states):
        return [0.0] * len(states)


class RandomHeuristic(solver.Heuristic):
    def __init__(self):
        super().__init__()

    def evaluate(self, states):
        return np.random.rand(len(states)).tolist()


# class NeuralHeuristic(solver.Heuristic):
#     def __init__(self, model, device="cpu"):
#         super().__init__()
#         self.device = torch.device(device)
#         self.model = model.to(self.device)
#         self.model.eval()

#     def evaluate(self, states):
#         # Build batch
#         batch = np.array(
#             [cube.get_state() for cube in states],
#             dtype=np.float32
#         )

#         batch_tensor = torch.from_numpy(batch).to(self.device)

#         with torch.no_grad():
#             outputs = self.model(batch_tensor).squeeze(-1)

#         return outputs.cpu().numpy().tolist()


cube = Cube()
cube = cube.apply_moves(
    [Moves.R, Moves.U, Moves.R_prime, Moves.U_prime])

h = ZeroHeuristic()
h = RandomHeuristic()
# h = NeuralHeuristic(CubeNet())
"""
! do not call ZeroHeuristic() in the constructor of Solver

 otherwise it will cause a segmentation fault when the solver tries
 to use the heuristic after it has been destroyed.

 Instead, create an instance of ZeroHeuristic and pass it to the
 Solver constructor.
"""
cube_solver = solver.Solver(
    solver.algorithms.IDA_STAR,
    5,
    1000000000.0,
    False,
    False,
    [Moves.R, Moves.R_prime, Moves.R2,
     Moves.U, Moves.U_prime, Moves.U2,],
    #  Moves.F, Moves.F_prime, Moves.F2,
    #  Moves.L, Moves.L_prime, Moves.L2,
    #  Moves.D, Moves.D_prime, Moves.D2,
    #  Moves.B, Moves.B_prime, Moves.B2],
    h
)

solution = cube_solver.solve(cube)

print(solution)

# print(solution.solved)
# print(" ".join(solution.solution_moves()))
