from cubik import Cube

# import pytest
# ? use unittest library instead

# cube = Cube()
# cubeU = cube.U()
# cubeR = cube.R()

# these should be different
# print(cube)
# print(cubeU)
# print(cubeR)

# assert (cubeU == cube.U())

cube = Cube()
state = cube.state_array()
print(state)
print(type(state))

checkered = cube.apply_moves(["M2", "E2", "S2"])
print(cube)
print(checkered)
