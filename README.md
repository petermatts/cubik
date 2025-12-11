![CI](https://github.com/petermatts/Cubik/actions/workflows/ci.yml/badge.svg)
![GitHub Release](https://img.shields.io/github/v/release/petermatts/cubik)

# Cubik

Python module, backended by C++ via SWIG, for emulating a Rubik's cube and its behaviors for implementing solving algorithms, search algorithms, and more.

## Usage

### Installation

To install simply run: `pip install cubik`

### Creating a Cube

```python
from cubik import Cube

cube = Cube()
print(cube)
```

Outputs:
```
      ⬜⬜⬜            
      ⬜⬜⬜            
      ⬜⬜⬜            
🟧🟧🟧🟩🟩🟩🟥🟥🟥🟦🟦🟦
🟧🟧🟧🟩🟩🟩🟥🟥🟥🟦🟦🟦
🟧🟧🟧🟩🟩🟩🟥🟥🟥🟦🟦🟦
      🟨🟨🟨            
      🟨🟨🟨            
      🟨🟨🟨    
```

### Applying a Move

```python
cube_R = cube.R() # applies R move
```

Note: *all move methods return a new cube*
This means that `cube` will be unchanged and `cube_R` is the result of applying a 'R' move to `cube`.

### Applying a Sequence of Moves

```python
from cubik import Cube, Moves

cube = Cube()

checker_moves = [Moves.M2, Moves.E2, Moves.S2] # sequence of moves to build a checker pattern on the cube

checkered_cube = cube.apply_moves(checker_moves)
```

Outputs:
```
      ⬜🟨⬜            
      🟨⬜🟨            
      ⬜🟨⬜            
🟧🟥🟧🟩🟦🟩🟥🟧🟥🟦🟩🟦
🟥🟧🟥🟦🟩🟦🟧🟥🟧🟩🟦🟩
🟧🟥🟧🟩🟦🟩🟥🟧🟥🟦🟩🟦
      🟨⬜🟨            
      ⬜🟨⬜            
      🟨⬜🟨   
```

### A Few Other Handy Functions and Features

```python
cube.is_solved() # returns true if the cube is solved, false otherwise
cube.get_state() # returns a tuple of 6 elements 

other_cube = cube()
other_cube == cube # true as both cubes are in equal states
other_cube.R() == cube.R() # ditto

other_cube != cube.R() # true because other_cube is not the as cube+R

canon = cube.cannonical() # returns a cube in canonical orientation*

cube.is_valid_state() # returns true if cube is in a solvable state
```
\* cannonical orientation is green in front, white on top, red on right, etc.

## Rubik's Cube Notation

For cube notation please refer to [3x3 Rubik's Cube Move Notation](https://jperm.net/3x3/moves).

## The Backend

Each face is represented as a `uint32_t` and each color is represented by a 3-bit section of the `uint32_t`. This means the entire represntation the cube only takes up $6*32=192$ bits or $24$ Bytes!!

Specifically:
| Sticker       | Bits                     |
| ------------- | ------------------------ |
| Top Left      | $(b_0,b_1,b_2)$          |
| Top Middle    | $(b_3,b_4,b_5)$          |
| Top Right     | $(b_6,b_7,b_8)$          |
| Middle Left   | $(b_9,b_{10},b_{11})$    |
| Center        | $(b_{12},b_{13},b_{14})$ |
| Middle Right  | $(b_{15},b_{16},b_{17})$ |
| Bottom Left   | $(b_{18},b_{19},b_{20})$ |
| Bottom Middle | $(b_{21},b_{22},b_{23})$ |
| Bottom Right  | $(b_{24},b_{25},b_{26})$ |


\* where `b0` is the least significant bit.