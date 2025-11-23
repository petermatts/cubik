#include <array>
#include <algorithm>
#include <cstring>

#include "common.hpp"
#include "cube.hpp"
#include "parity.hpp"

bool Cube::is_valid_state() const {
    return check_piece_counts()
        && check_corner_orientation()
        && check_edge_orientation()
        && check_parity();
}

bool Cube::check_piece_counts() const {
    return true;
}

bool Cube::check_corner_orientation() const {
    int sum = 0;

    for (uint8_t i = 0; i < 8; i++) {
        CornerCubie c = get_corner_cubie(i);
        sum += c.orientation;
    }

    return (sum % 3) == 0;
}

bool Cube::check_edge_orientation() const {
    int sum = 0;

    for (uint8_t i = 0; i < 12; i++) {
        EdgeCubie e = get_edge_cubie(i);
        sum += e.orientation;
    }

    return (sum % 2) == 0;
}

std::array<int8_t, 8> Cube::corner_permutation() const {
    std::array<int8_t, 8> perm;

    for (int8_t pos = 0; pos < 8; pos++) {
        CornerCubie c = get_corner_cubie(pos);

        // Normalize sticker colors (sort since order varies)
        uint8_t col_sorted[3] = {c.colors[0], c.colors[1], c.colors[2]};
        std::sort(col_sorted, col_sorted + 3);

        // Match against solved cubies
        bool found = false;
        for (int8_t solved_idx = 0; solved_idx < 8; solved_idx++) {
            uint8_t sol[3] = {
                CORNERS[solved_idx][0],
                CORNERS[solved_idx][1],
                CORNERS[solved_idx][2]
            };
            std::sort(sol, sol + 3);

            if (memcmp(sol, col_sorted, 3) == 0) {
                perm[pos] = solved_idx;
                found = true;
                break;
            }
        }

        if (!found)
            perm[pos] = -1; // Impossible piece
    }

    return perm;
}

std::array<int8_t, 12> Cube::edge_permutation() const {
    std::array<int8_t, 12> perm;

    for (int8_t pos = 0; pos < 12; pos++) {
        EdgeCubie e = get_edge_cubie(pos);

        uint8_t sorted_col[2] = {e.colors[0], e.colors[1]};
        std::sort(sorted_col, sorted_col + 2);

        bool found = false;
        for (int8_t solved_idx = 0; solved_idx < 12; solved_idx++) {
            uint8_t sol[2] = {
                EDGES[solved_idx][0],
                EDGES[solved_idx][1]
            };
            std::sort(sol, sol + 2);

            if (sol[0] == sorted_col[0] &&
                sol[1] == sorted_col[1]) {
                perm[pos] = solved_idx;
                found = true;
                break;
            }
        }

        if (!found)
            perm[pos] = -1;
    }

    return perm;
}


int Cube::corner_parity() const {
    auto perm = corner_permutation();
    return permutation_parity(perm);
}

int Cube::edge_parity() const {
    auto perm = edge_permutation();
    return permutation_parity(perm);
}

bool Cube::check_parity() const {
    return corner_parity() == edge_parity();
}


CornerCubie Cube::get_corner_cubie(uint8_t idx) const {
    CornerCubie c;

    for (int i = 0; i < 3; i++) {
        uint8_t face = CORNER_STICKERS[idx][i].face;
        uint8_t pos  = CORNER_STICKERS[idx][i].pos;

        const uint32_t &face_val =
            (face == UP    ? up :
            (face == DOWN  ? down :
            (face == FRONT ? front :
            (face == BACK  ? back :
            (face == LEFT  ? left : right)))));

        c.colors[i] = get(face_val, pos);
    }

    c.orientation = compute_corner_orientation(
        c.colors,
        get(up, CENTER),
        get(down, CENTER)
    );

    return c;
}


EdgeCubie Cube::get_edge_cubie(uint8_t idx) const {
    EdgeCubie e;

    for (int i = 0; i < 2; i++) {
        uint8_t face = EDGE_STICKERS[idx][i].face;
        uint8_t pos  = EDGE_STICKERS[idx][i].pos;

        const uint32_t &face_val =
            (face == UP    ? up :
            (face == DOWN  ? down :
            (face == FRONT ? front :
            (face == BACK  ? back :
            (face == LEFT  ? left : right)))));

        e.colors[i] = get(face_val, pos);
    }

    e.orientation = compute_edge_orientation(
        e.colors,
        get(up,    CENTER),
        get(down,  CENTER),
        get(front, CENTER),
        get(back,  CENTER)
    );

    return e;
}
