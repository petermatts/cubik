#include <array>
#include <algorithm>
#include <cstring>

#include "common.hpp"
#include "cube.hpp"
#include "parity.hpp"

bool Cube::is_valid_state() const {
    Cube canon = canonical();

    return canon.check_piece_counts()
        && canon.check_corner_orientation()
        && canon.check_edge_orientation()
        && canon.check_parity()
        && canon.verify_centers();

    // std::cout << "CHECKING STATE...\n";
    // std::cerr << "Cube state:\n" << this->toString() << "\n";

    // bool a = check_piece_counts();
    // std::cout << "piece counts: " << a << std::endl;

    // bool b = check_corner_orientation();
    // std::cout << "corner orientation: " << b << std::endl;

    // bool c = check_edge_orientation();
    // std::cout << "edge orientation: " << c << std::endl;

    // bool d = check_parity();
    // std::cout << "parity: " << d << std::endl;

    // bool e = verify_centers();
    // std::cout << "center orientation: " << e << std::endl;

    // return a && b && c && d && e;
}

#include <unordered_map>

bool Cube::check_piece_counts() const
{
    // The six faces stored in Cube
    auto faces = get_state();

    std::unordered_map<uint8_t, int> count;

    // Initialize counts to 0
    for (uint8_t c : COLORS)
        count[c] = 0;

    // Count stickers
    for (uint32_t f : faces)
    {
        for (uint8_t off : OFFSETS)
        {
            uint8_t sticker = get(f, off); // if you are seeing, enjoy these funny param names

            // If sticker is not a known color -> invalid cube
            if (count.find(sticker) == count.end())
                return false;

            count[sticker]++;
        }
    }

    // Validate that each color appears exactly 9 times
    for (uint8_t c : COLORS)
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

// ---- Corner permutation ----
std::array<int8_t, 8> Cube::corner_permutation() const {
    std::array<int8_t, 8> perm;
    for (int i = 0; i < 8; ++i) {
        int id = get_corner_cubie(i).id;
        perm[i] = (id < 8 ? static_cast<int8_t>(id) : -1);
    }
    return perm;
}

// ---- Edge permutation ----
std::array<int8_t, 12> Cube::edge_permutation() const {
    std::array<int8_t, 12> perm;
    for (int i = 0; i < 12; ++i) {
        int id = get_edge_cubie(i).id;
        perm[i] = (id < 12 ? static_cast<int8_t>(id) : -1);
    }
    return perm;
}


// ---- Corner parity ----
int Cube::corner_parity() const {
    return permutation_parity(corner_permutation());
}

// ---- Edge parity ----
int Cube::edge_parity() const {
    return permutation_parity(edge_permutation());
}

// ---- Check parity ----
bool Cube::check_parity() const {
    // std::cout << "=== CENTERS ===\n";
    // std::cout << "UP   : " << getColor(get(up, CENTER)) << "raw: " << (int)get(up, CENTER) << std::endl;
    // std::cout << "FRONT: " << getColor(get(front, CENTER)) << "raw: " << (int)get(front, CENTER) << std::endl;
    // std::cout << "RIGHT: " << getColor(get(right, CENTER)) << "raw: " << (int)get(right, CENTER) << std::endl;
    // std::cout << "BACK : " << getColor(get(back, CENTER)) << "raw: " << (int)get(back, CENTER) << std::endl;
    // std::cout << "LEFT : " << getColor(get(left, CENTER)) << "raw: " << (int)get(left, CENTER) << std::endl;
    // std::cout << "DOWN : " << getColor(get(down, CENTER)) << "raw: " << (int)get(down, CENTER) << std::endl << std::endl;
    // std::cout << "=== CORNER CUBIES ===\n";
    // for (int pos = 0; pos < 8; ++pos) {
    //     CornerCubie c = get_corner_cubie(pos);
    //     std::cout << "pos=" << pos
    //             << "  id=" << (int)c.id
    //             << "  ori=" << (int)c.orientation
    //             << "  colors=("
    //             << (int)c.colors[0] << ","
    //             << (int)c.colors[1] << ","
    //             << (int)c.colors[2] << ")\n";
    // }

    // std::cout << "\n=== EDGE CUBIES ===\n";
    // for (int pos = 0; pos < 12; ++pos) {
    //     EdgeCubie e = get_edge_cubie(pos);
    //     std::cout << "pos=" << pos
    //             << "  id=" << (int)e.id
    //             << "  ori=" << (int)e.orientation
    //             << "  colors=("
    //             << (int)e.colors[0] << ","
    //             << (int)e.colors[1] << ")\n";
    // }

    int cp = corner_parity();
    int ep = edge_parity();
    if (cp < 0 || ep < 0) return false;
    return cp == ep;
}

CornerCubie Cube::get_corner_cubie(int pos) const {
    CornerCubie c{};
    // Map face index -> the uint32_t face value stored in this Cube
    auto faces_arr = get_state();

    uint8_t cols[3];
    for (int i = 0; i < 3; ++i) {
        uint8_t face_idx = CORNER_STICKERS[pos][i].face; // 0..5
        uint8_t offset   = CORNER_STICKERS[pos][i].pos;
        cols[i] = get(faces_arr[face_idx], offset);
    }

    // Try to identify id + orientation by color-cycle matching
    uint8_t orient = 0;
    int id = find_corner_id_and_orient(cols, orient);
    if (id >= 0) {
        c.id = static_cast<int>(id);
        c.orientation = orient;
        c.colors[0] = cols[0];
        c.colors[1] = cols[1];
        c.colors[2] = cols[2];
        return c;
    }

    // fallback: set colors, mark unknown id and compute orientation by UD-centers
    c.colors[0] = cols[0];
    c.colors[1] = cols[1];
    c.colors[2] = cols[2];
    c.id = 255;
    c.orientation = compute_corner_orientation(cols, get(up, CENTER), get(down, CENTER));
    return c;
}

EdgeCubie Cube::get_edge_cubie(int pos) const {
    EdgeCubie e{};
    // Map face index -> the uint32_t face value stored in this Cube
    auto faces_arr = get_state();

    uint8_t cols[2];
    for (int i = 0; i < 2; ++i) {
        uint8_t face_idx = EDGE_STICKERS[pos][i].face; // 0..5
        uint8_t offset   = EDGE_STICKERS[pos][i].pos;
        cols[i] = get(faces_arr[face_idx], offset);
    }

    uint8_t orient = 0;
    int id = find_edge_id_and_orient(cols, orient);
    if (id >= 0) {
        e.id = static_cast<int>(id);
        e.orientation = orient;
        e.colors[0] = cols[0];
        e.colors[1] = cols[1];
        return e;
    }

    // fallback: set colors, mark unknown id and compute orientation by centers
    e.colors[0] = cols[0];
    e.colors[1] = cols[1];
    e.id = 255;
    e.orientation = compute_edge_orientation(cols, get(up, CENTER), get(down, CENTER), get(front, CENTER), get(back, CENTER));
    return e;
}

bool Cube::verify_centers() const {
    uint8_t c_up = get(up, CENTER);
    uint8_t c_down = get(down, CENTER);
    uint8_t c_front = get(front, CENTER);
    uint8_t c_back = get(back, CENTER);
    uint8_t c_left = get(left, CENTER);
    uint8_t c_right = get(right, CENTER);
    
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
