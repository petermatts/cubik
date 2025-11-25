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

template <std::size_t N>
int permutation_parity(const std::array<int8_t, N> &perm)
{
    std::array<bool, N> visited{};
    int8_t parity = 0;

    for (std::size_t i = 0; i < N; ++i)
    {
        if (!visited[i])
        {
            int8_t cycle_len = 0;
            std::size_t j = i;

            while (!visited[j])
            {
                visited[j] = true;
                j = static_cast<std::size_t>(perm[j]);
                cycle_len++;
            }

            // This is always 0 or 1
            parity ^= ((cycle_len - 1) & 1);
        }
    }

    return parity; // still return int: 0 or 1
}

// Helper: return -1 if not found, else 0..7 and orientation by ref
static int find_corner_id_and_orient(const uint8_t colors[3], uint8_t &out_orient) {
    for (int id = 0; id < 8; ++id) {
        const uint8_t* ref = CORNERS[id];
        // try rotation 0: colors == {ref0, ref1, ref2}
        if (colors[0] == ref[0] && colors[1] == ref[1] && colors[2] == ref[2]) {
            out_orient = 0;
            return id;
        }
        // rotation 1: colors == {ref1, ref2, ref0}
        if (colors[0] == ref[1] && colors[1] == ref[2] && colors[2] == ref[0]) {
            out_orient = 1;
            return id;
        }
        // rotation 2
        if (colors[0] == ref[2] && colors[1] == ref[0] && colors[2] == ref[1]) {
            out_orient = 2;
            return id;
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
