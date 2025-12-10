#include <cstdint>
#include <array>

uint8_t compute_corner_orientation(const uint8_t colors[3],
                                   uint8_t UP_C, uint8_t DOWN_C)
{
    // Find which sticker is the U/D face color
    for (uint8_t o = 0; o < 3; o++) {
        if (colors[o] == UP_C || colors[o] == DOWN_C)
            return o;  // 0, 1, or 2
    }

    // Invalid cube if no UD sticker found (should never happen)
    return 0;
}

uint8_t compute_edge_orientation(const uint8_t colors[2],
                                 uint8_t UP_C, uint8_t DOWN_C,
                                 uint8_t FRONT_C, uint8_t BACK_C)
{
    // Does this edge contain a U/D color?
    bool hasUD0 = (colors[0] == UP_C || colors[0] == DOWN_C);
    bool hasUD1 = (colors[1] == UP_C || colors[1] == DOWN_C);

    if (hasUD0 || hasUD1) {
        // Oriented correctly if UD sticker is in position 0
        return hasUD0 ? 0 : 1;
    }

    // Otherwise check the F/B axis for the "slice" edges
    bool hasFB0 = (colors[0] == FRONT_C || colors[0] == BACK_C);
    bool hasFB1 = (colors[1] == FRONT_C || colors[1] == BACK_C);

    // For F/B edges: sticker belonging to FB axis must be in position 0
    return hasFB0 ? 0 : 1;
}

// Compute permutation parity of an array
template <std::size_t N>
int permutation_parity(const std::array<int8_t, N>& perm) {
    std::array<bool, N> visited{};
    int parity = 0;

    for (size_t i = 0; i < N; ++i) {
        if (!visited[i]) {
            int cycle_len = 0;
            size_t j = i;

            while (!visited[j]) {
                if (perm[j] < 0 || perm[j] >= static_cast<int8_t>(N)) {
                    // Invalid cubie detected → cannot compute parity
                    return -1;
                }
                visited[j] = true;
                j = static_cast<size_t>(perm[j]);
                cycle_len++;
            }
            parity ^= ((cycle_len - 1) & 1);
        }
    }
    return parity;
}


// Helper: return -1 if not found, else 0..7 and orientation by ref
static int find_corner_id_and_orient(const uint8_t colors[3], uint8_t &out_orient) {
    std::array<uint8_t, 3> arr_colors = {colors[0], colors[1], colors[2]};

    for (int id = 0; id < 8; ++id) {
        std::array<uint8_t, 3> ref = {CORNERS[id][0], CORNERS[id][1], CORNERS[id][2]};
        
        if (array_circular_equal(arr_colors, ref)) {
            for (uint8_t shift = 0; shift < 3; ++shift) {
                std::array<uint8_t, 3> rotated = { ref[shift % 3], ref[(shift + 1) % 3], ref[(shift + 2) % 3] };
                if (arr_colors == rotated) {
                    out_orient = shift;
                    return id;
                }
            }
        }
    }
    return -1;
}

static int find_edge_id_and_orient(const uint8_t colors[2], uint8_t &out_orient) {
    for (int id = 0; id < 12; ++id) {
        const uint8_t* ref = EDGES[id];
        // order 0
        if (colors[0] == ref[0] && colors[1] == ref[1]) {
            out_orient = 0;
            return id;
        }
        // swapped
        if (colors[0] == ref[1] && colors[1] == ref[0]) {
            out_orient = 1;
            return id;
        }
    }
    return -1;
}
