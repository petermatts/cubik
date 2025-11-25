#include <array>
#include <algorithm>
#include <cstring>

#include "common.hpp"
#include "cube.hpp"
#include "parity.hpp"

bool Cube::is_valid_state() const {
    // return check_piece_counts()
    //     && check_corner_orientation()
    //     && check_edge_orientation()
    //     && check_parity();

    std::cout << "CHECKING STATE...\n";

    bool a = check_piece_counts();
    std::cout << "piece counts: " << a << "\n";

    bool b = check_corner_orientation();
    std::cout << "corner orientation: " << b << "\n";

    bool c = check_edge_orientation();
    std::cout << "edge orientation: " << c << "\n";

    bool d = check_parity();
    std::cout << "parity: " << d << "\n";

    return a && b && c && d;
}

#include <unordered_map>

bool Cube::check_piece_counts() const
{
    // Colors: WHITE=1 .. ORANGE=6
    static const uint8_t ALL_COLORS[6] = {
        WHITE, YELLOW, GREEN, BLUE, RED, ORANGE
    };

    // All sticker offsets on a face
    static const uint8_t OFFSETS[9] = {
        TOP_LEFT, TOP_MIDDLE, TOP_RIGHT,
        MIDDLE_LEFT, CENTER, MIDDLE_RIGHT,
        BOTTOM_LEFT, BOTTOM_MIDDLE, BOTTOM_RIGHT
    };

    // The six faces stored in Cube
    const uint32_t faces[6] = {
        up, down, left, right, front, back
    };

    std::unordered_map<uint8_t, int> count;

    // Initialize counts to 0
    for (uint8_t c : ALL_COLORS)
        count[c] = 0;

    // Count stickers
    for (uint32_t f : faces)
    {
        for (uint8_t off : OFFSETS)
        {
            uint8_t sticker = get(f, off);

            // If sticker is not a known color -> invalid cube
            if (count.find(sticker) == count.end())
                return false;

            count[sticker]++;
        }
    }

    // Validate that each color appears exactly 9 times
    for (uint8_t c : ALL_COLORS)
    {
        if (count[c] != 9)
            return false;
    }

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
    for (int pos = 0; pos < 8; ++pos) {
        CornerCubie c = get_corner_cubie(pos);
        if (c.id == 255) {
            perm[pos] = -1; // invalid / non-cyclic match (including 2-cycle transpositions)
        } else {
            perm[pos] = static_cast<int8_t>(c.id);
        }
    }
    return perm;
}

std::array<int8_t, 12> Cube::edge_permutation() const {
    std::array<int8_t, 12> perm;
    for (int pos = 0; pos < 12; ++pos) {
        EdgeCubie e = get_edge_cubie(pos);
        if (e.id == 255) {
            perm[pos] = -1;
        } else {
            perm[pos] = static_cast<int8_t>(e.id);
        }
    }
    return perm;
}

int Cube::corner_parity() const {
    auto perm = corner_permutation();

    for (auto p : perm) {
        if (p < 0) return -1;
    }

    return permutation_parity(perm);
}

int Cube::edge_parity() const {
    auto perm = edge_permutation();

    for (auto p : perm) {
        if (p < 0) return -1;
    }

    return permutation_parity(perm);
}

bool Cube::check_parity() const {
    int cp = corner_parity();
    int ep = edge_parity();

    // If either is -1, cube is invalid
    if (cp < 0 || ep < 0) return false;

    return cp == ep;
}


CornerCubie Cube::get_corner_cubie(uint8_t idx) const {
    CornerCubie c;
    // read the 3 stickers into the array in your current order
    for (int i = 0; i < 3; ++i) {
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

    // First try to identify cubie by exact cyclic color match (robust).
    uint8_t orient = 0;
    int id = find_corner_id_and_orient(c.colors, orient);
    if (id >= 0) {
        // we found the corner and its orientation (0..2)
        c.id = static_cast<uint8_t>(id);
        c.orientation = orient;
        return c;
    }

    // Fallback: if we couldn't find an exact cyclic match, use center-based method
    c.orientation = compute_corner_orientation(c.colors, get(up, CENTER), get(down, CENTER));
    c.id = 255; // mark unknown id
    return c;
}


EdgeCubie Cube::get_edge_cubie(uint8_t idx) const {
    EdgeCubie e;
    for (int i = 0; i < 2; ++i) {
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

    uint8_t orient = 0;
    int id = find_edge_id_and_orient(e.colors, orient);
    if (id >= 0) {
        e.id = static_cast<uint8_t>(id);
        e.orientation = orient;
        return e;
    }

    // Fallback: center-based heuristic
    e.orientation = compute_edge_orientation(e.colors,
        get(up, CENTER), get(down, CENTER), get(front, CENTER), get(back, CENTER));
    e.id = 255;
    return e;
}

bool Cube::verify_orientation() const {
    uint8_t c_up = static_cast<uint8_t>((up << CLEAR_CENTER) >> CLEAR);
    uint8_t c_down = static_cast<uint8_t>((down << CLEAR_CENTER) >> CLEAR);
    uint8_t c_front = static_cast<uint8_t>((front << CLEAR_CENTER) >> CLEAR);
    uint8_t c_back = static_cast<uint8_t>((back << CLEAR_CENTER) >> CLEAR);
    uint8_t c_left = static_cast<uint8_t>((left << CLEAR_CENTER) >> CLEAR);
    uint8_t c_right = static_cast<uint8_t>((right << CLEAR_CENTER) >> CLEAR);

    
    // check for valid opposite centers
    array<uint8_t, 3> poles = {
        static_cast<uint8_t>(c_up + c_down),
        static_cast<uint8_t>(c_front + c_back),
        static_cast<uint8_t>(c_left + c_right)
    };

    array<uint8_t, 3> axes {
        WHITE + YELLOW,
        GREEN + BLUE,
        RED + ORANGE
    };

    sort(poles.begin(), poles.end());
    sort(axes.begin(), axes.end());

    array<array<uint8_t, 3>, 8> cycles = {{
        {{WHITE, BLUE, RED}},
        {{WHITE, ORANGE, BLUE}},
        {{WHITE, GREEN, ORANGE}},
        {{WHITE, RED, GREEN}},
        {{YELLOW, BLUE, ORANGE}},
        {{YELLOW, RED, BLUE}},
        {{YELLOW, GREEN, RED}},
        {{YELLOW, ORANGE, GREEN}}
    }};

    array<uint8_t, 3> center_cycle = {c_up, c_right, c_front};

    bool result = false;
    for(auto c : cycles) {
        if(array_circular_equal(c, center_cycle)) {
            result = true;
            break;
        }
    }

    return (poles == axes) && result;
}
