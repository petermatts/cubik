![CI](https://github.com/petermatts/Cubik/actions/workflows/ci.yml/badge.svg)
![GitHub Release](https://img.shields.io/github/v/release/petermatts/cubik)

# Cubik

C++ module for emulating a Rubik's cube and its behaviors for implementing solving algorithms, search algorithms, and more.

## The Cube Model

For cube notation please refer to [3x3 Rubik's Cube Move Notation](https://jperm.net/3x3/moves).

### Memory Model
In this cube model we attempt to be as memory efficient as possible so, in memory each face is stored as a uint32 such that:

<table>
    <thead>
    <tr>
        <th colspan="5">Unused</th>
        <th colspan="3">Bottom Right</th>
        <th colspan="3">Bottom Middle</th>
        <th colspan="3">Bottom Left</th>
        <th colspan="3">Middle Right</th>
        <th colspan="3">Center</th>
        <th colspan="3">Middle Left</th>
        <th colspan="3">Top Right</th>
        <th colspan="3">Top Middle</th>
        <th colspan="3">Top Left</th>
    </tr>
    </thead>
    <tbody>
    <tr>
        <td>b31</td>
        <td>b30</td>
        <td>b29</td>
        <td>b28</td>
        <td>b27</td>
        <td>b26</td>
        <td>b25</td>
        <td>b24</td>
        <td>b23</td>
        <td>b22</td>
        <td>b21</td>
        <td>b20</td>
        <td>b19</td>
        <td>b18</td>
        <td>b17</td>
        <td>b16</td>
        <td>b15</td>
        <td>b14</td>
        <td>b13</td>
        <td>b12</td>
        <td>b11</td>
        <td>b10</td>
        <td>b9</td>
        <td>b8</td>
        <td>b7</td>
        <td>b6</td>
        <td>b5</td>
        <td>b4</td>
        <td>b3</td>
        <td>b2</td>
        <td>b1</td>
        <td>b0</td>
    </tr>
    </tbody>
</table>


### Visualized/Printed Model

Cube Layout:
```text
          +---------+
          |         |
          |    U    |
          |         |
+---------+---------+---------+---------+
|         |         |         |         |
|    L    |    F    |    R    |    B    |
|         |         |         |         |
+---------+---------+---------+---------+
          |         |
          |    D    |
          |         |
          +---------+
```

| Letter | Face  |
| ------ | ----- |
| U      | Up    |
| L      | Left  |
| F      | Front |
| R      | Right |
| B      | Back  |
| D      | Down  |

Face Layout:
<table>
    <tbody>
    <tr>
        <td>Top Left</td>
        <td>Top Middle</td>
        <td>Top Right</td>
    </tr>
    <tr>
        <td>Middle Left</td>
        <td>Center</td>
        <td>Middle Right</td>
    </tr>
    <tr>
        <td>Bottom Left</td>
        <td>Bottom Middle</td>
        <td>Bottom Right</td>
    </tr>
    </tbody>
</table>


<!-- ### Moves Group

| Move | Composition |
| ---- | ----------- |
| I    |             |
| U    |             |
| D    |             |
| L    |             |
| R    |             |
| F    |             |
| B    |             |
| M    |             |
| E    |             |
| S    |             | -->
