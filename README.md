![CI](https://github.com/petermatts/Cubik/actions/workflows/ci.yml/badge.svg)
![GitHub Release](https://img.shields.io/github/v/release/petermatts/cubik)

# Cubik

C++ module for emulating a Rubik's cube and its behaviors for implementing solving algorithms, search algorithms, and more.

## The Cube Model

For cube notation please refer to [3x3 Rubik's Cube Move Notation](https://jperm.net/3x3/moves).

### Memory Model
In this cube model we attempt to be as memory efficient as possible so, in memory each face is stored as a uint32 such that:

![](./docs/images/uint32.png)


### Visualized/Printed Model

Cube Layout:

![](./docs/images/cube.png)

In memory each face is stored within a `uint32` as:

![Face Layout](./docs/images/face.png)
