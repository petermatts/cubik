#include "common.hpp"
#include "cube.hpp"
#include "moves.hpp"

#include <array>
#include <cassert>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;

Cube::Cube() {
    up = WHITE_FACE; // 19173961
    down = YELLOW_FACE; // 38347922
    front = GREEN_FACE; // 57521883
    back = BLUE_FACE; // 76695844
    left = ORANGE_FACE; // 115043766
    right = RED_FACE; // 95869805
}

Cube::Cube(const Cube &cube) {
    up = cube.up;
    front = cube.front;
    left = cube.left;
    right = cube.right;
    back = cube.back;
    down = cube.down;
}

Cube::~Cube() = default;

array<uint32_t, 6> Cube::state_array() const {
    assert(verify_orientation());
    uint8_t c_up = static_cast<uint8_t>((up << CLEAR_CENTER) >> CLEAR);
    uint8_t c_down = static_cast<uint8_t>((down << CLEAR_CENTER) >> CLEAR);
    uint8_t c_front = static_cast<uint8_t>((front << CLEAR_CENTER) >> CLEAR);
    uint8_t c_back = static_cast<uint8_t>((back << CLEAR_CENTER) >> CLEAR);
    uint8_t c_left = static_cast<uint8_t>((left << CLEAR_CENTER) >> CLEAR);
    uint8_t c_right = static_cast<uint8_t>((right << CLEAR_CENTER) >> CLEAR);

    array<uint8_t, 6> colors = {WHITE, GREEN, RED, BLUE, ORANGE, YELLOW};
    array<uint32_t, 6> state;
    vector<uint32_t> state_vector;

    for(uint8_t color : colors) {
        if(c_up == color) {
            state_vector.push_back(up);
        } else if (c_down == color) {
            state_vector.push_back(down);
        } else if (c_front == color) {
            state_vector.push_back(front);
        } else if (c_back == color) {
            state_vector.push_back(back);
        } else if (c_left == color) {
            state_vector.push_back(left);
        } else if (c_right == color) {
            state_vector.push_back(right);
        }
    }

    copy(state_vector.begin(), state_vector.end(), state.begin());
    return state;
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

bool Cube::isSolved() {
    return *this == Cube();
}

string Cube::toString() {
    const string square_space = "      ";
    const char* space = __USE_EMOJI ? "" : " ";
    string msg = "\n";

    // up
    msg += square_space;
    msg += getColor((up << CLEAR_TOP_LEFT) >> CLEAR) + space;
    msg += getColor((up << CLEAR_TOP_MIDDLE) >> CLEAR) + space;
    msg += getColor((up << CLEAR_TOP_RIGHT) >> CLEAR) + space;
    msg += square_space + square_space + "\n" + square_space;
    msg += getColor((up << CLEAR_MIDDLE_LEFT) >> CLEAR) + space;
    msg += getColor((up << CLEAR_CENTER) >> CLEAR) + space;
    msg += getColor((up << CLEAR_MIDDLE_RIGHT) >> CLEAR) + space;
    msg += square_space + square_space + "\n" + square_space;
    msg += getColor((up << CLEAR_BOTTOM_LEFT) >> CLEAR) + space;
    msg += getColor((up << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + space;
    msg += getColor((up << CLEAR_BOTTOM_RIGHT) >> CLEAR) + space;
    msg += square_space + square_space + "\n";

    // left front right back
    msg += getColor((left << CLEAR_TOP_LEFT) >> CLEAR) + space;
    msg += getColor((left << CLEAR_TOP_MIDDLE) >> CLEAR) + space;
    msg += getColor((left << CLEAR_TOP_RIGHT) >> CLEAR) + space;
    msg += getColor((front << CLEAR_TOP_LEFT) >> CLEAR) + space;
    msg += getColor((front << CLEAR_TOP_MIDDLE) >> CLEAR) + space;
    msg += getColor((front << CLEAR_TOP_RIGHT) >> CLEAR) + space;
    msg += getColor((right << CLEAR_TOP_LEFT) >> CLEAR) + space;
    msg += getColor((right << CLEAR_TOP_MIDDLE) >> CLEAR) + space;
    msg += getColor((right << CLEAR_TOP_RIGHT) >> CLEAR) + space;
    msg += getColor((back << CLEAR_TOP_LEFT) >> CLEAR) + space;
    msg += getColor((back << CLEAR_TOP_MIDDLE) >> CLEAR) + space;
    msg += getColor((back << CLEAR_TOP_RIGHT) >> CLEAR) + space;
    msg += "\n";
    msg += getColor((left << CLEAR_MIDDLE_LEFT) >> CLEAR) + space;
    msg += getColor((left << CLEAR_CENTER) >> CLEAR) + space;
    msg += getColor((left << CLEAR_MIDDLE_RIGHT) >> CLEAR) + space;
    msg += getColor((front << CLEAR_MIDDLE_LEFT) >> CLEAR) + space;
    msg += getColor((front << CLEAR_CENTER) >> CLEAR) + space;
    msg += getColor((front << CLEAR_MIDDLE_RIGHT) >> CLEAR) + space;
    msg += getColor((right << CLEAR_MIDDLE_LEFT) >> CLEAR) + space;
    msg += getColor((right << CLEAR_CENTER) >> CLEAR) + space;
    msg += getColor((right << CLEAR_MIDDLE_RIGHT) >> CLEAR) + space;
    msg += getColor((back << CLEAR_MIDDLE_LEFT) >> CLEAR) + space;
    msg += getColor((back << CLEAR_CENTER) >> CLEAR) + space;
    msg += getColor((back << CLEAR_MIDDLE_RIGHT) >> CLEAR) + space;
    msg += "\n";
    msg += getColor((left << CLEAR_BOTTOM_LEFT) >> CLEAR) + space;
    msg += getColor((left << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + space;
    msg += getColor((left << CLEAR_BOTTOM_RIGHT) >> CLEAR) + space;
    msg += getColor((front << CLEAR_BOTTOM_LEFT) >> CLEAR) + space;
    msg += getColor((front << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + space;
    msg += getColor((front << CLEAR_BOTTOM_RIGHT) >> CLEAR) + space;
    msg += getColor((right << CLEAR_BOTTOM_LEFT) >> CLEAR) + space;
    msg += getColor((right << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + space;
    msg += getColor((right << CLEAR_BOTTOM_RIGHT) >> CLEAR) + space;
    msg += getColor((back << CLEAR_BOTTOM_LEFT) >> CLEAR) + space;
    msg += getColor((back << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + space;
    msg += getColor((back << CLEAR_BOTTOM_RIGHT) >> CLEAR) + space;
    msg += "\n";

    // down
    msg += square_space;
    msg += getColor((down << CLEAR_TOP_LEFT) >> CLEAR) + space;
    msg += getColor((down << CLEAR_TOP_MIDDLE) >> CLEAR) + space;
    msg += getColor((down << CLEAR_TOP_RIGHT) >> CLEAR) + space;
    msg += square_space + square_space + "\n" + square_space;
    msg += getColor((down << CLEAR_MIDDLE_LEFT) >> CLEAR) + space;
    msg += getColor((down << CLEAR_CENTER) >> CLEAR) + space;
    msg += getColor((down << CLEAR_MIDDLE_RIGHT) >> CLEAR) + space;
    msg += square_space + square_space + "\n" + square_space;
    msg += getColor((down << CLEAR_BOTTOM_LEFT) >> CLEAR) + space;
    msg += getColor((down << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + space;
    msg += getColor((down << CLEAR_BOTTOM_RIGHT) >> CLEAR) + space;
    msg += square_space + square_space + "\n";

    return msg;
}

bool operator==(const Cube &cube1, const Cube &cube2) {
    return cube1.state_array() == cube2.state_array();
}

bool operator!=(const Cube &cube1, const Cube &cube2) {
    return !(cube1 == cube2);
}

string Cube::__str__() {
    return toString();
}

string Cube::__repr__() {
    return toString();
}

bool Cube::__eq__(const Cube &other) {
    return *this == other;
}

bool Cube::__ne__(const Cube &other) {
    return *this != other;
}

Cube Cube::apply_moves(const vector<string> &moves) {
    Cube newCube = *this;

    static const std::unordered_map<std::string, std::function<Cube(const Cube&)>> move_options = {
        {moves::U, [](const Cube &c) { return c.U(); }},
        {moves::D, [](const Cube &c) { return c.D(); }},
        {moves::L, [](const Cube &c) { return c.L(); }},
        {moves::R, [](const Cube &c) { return c.R(); }},
        {moves::F, [](const Cube &c) { return c.F(); }},
        {moves::B, [](const Cube &c) { return c.B(); }},
        {moves::U_prime, [](const Cube &c) { return c.U_prime(); }},
        {moves::D_prime, [](const Cube &c) { return c.D_prime(); }},
        {moves::L_prime, [](const Cube &c) { return c.L_prime(); }},
        {moves::R_prime, [](const Cube &c) { return c.R_prime(); }},
        {moves::F_prime, [](const Cube &c) { return c.F_prime(); }},
        {moves::B_prime, [](const Cube &c) { return c.B_prime(); }},
        {moves::U2, [](const Cube &c) { return c.U2(); }},
        {moves::D2, [](const Cube &c) { return c.D2(); }},
        {moves::L2, [](const Cube &c) { return c.L2(); }},
        {moves::R2, [](const Cube &c) { return c.R2(); }},
        {moves::F2, [](const Cube &c) { return c.F2(); }},
        {moves::B2, [](const Cube &c) { return c.B2(); }},
        {moves::u, [](const Cube &c) { return c.u(); }},
        {moves::d, [](const Cube &c) { return c.d(); }},
        {moves::l, [](const Cube &c) { return c.l(); }},
        {moves::r, [](const Cube &c) { return c.r(); }},
        {moves::f, [](const Cube &c) { return c.f(); }},
        {moves::b, [](const Cube &c) { return c.b(); }},
        {moves::u_prime, [](const Cube &c) { return c.u_prime(); }},
        {moves::d_prime, [](const Cube &c) { return c.d_prime(); }},
        {moves::l_prime, [](const Cube &c) { return c.l_prime(); }},
        {moves::r_prime, [](const Cube &c) { return c.r_prime(); }},
        {moves::f_prime, [](const Cube &c) { return c.f_prime(); }},
        {moves::b_prime, [](const Cube &c) { return c.b_prime(); }},
        {moves::u2, [](const Cube &c) { return c.u2(); }},
        {moves::d2, [](const Cube &c) { return c.d2(); }},
        {moves::l2, [](const Cube &c) { return c.l2(); }},
        {moves::r2, [](const Cube &c) { return c.r2(); }},
        {moves::f2, [](const Cube &c) { return c.f2(); }},
        {moves::b2, [](const Cube &c) { return c.b2(); }},
        {moves::M, [](const Cube &c) { return c.M(); }},
        {moves::E, [](const Cube &c) { return c.E(); }},
        {moves::S, [](const Cube &c) { return c.S(); }},
        {moves::M_prime, [](const Cube &c) { return c.M_prime(); }},
        {moves::E_prime, [](const Cube &c) { return c.E_prime(); }},
        {moves::S_prime, [](const Cube &c) { return c.S_prime(); }},
        {moves::M2, [](const Cube &c) { return c.M2(); }},
        {moves::E2, [](const Cube &c) { return c.E2(); }},
        {moves::S2, [](const Cube &c) { return c.S2(); }},
        {moves::X, [](const Cube &c) { return c.X(); }},
        {moves::Y, [](const Cube &c) { return c.Y(); }},
        {moves::Z, [](const Cube &c) { return c.Z(); }},
        {moves::X_prime, [](const Cube &c) { return c.X_prime(); }},
        {moves::Y_prime, [](const Cube &c) { return c.Y_prime(); }},
        {moves::Z_prime, [](const Cube &c) { return c.Z_prime(); }},
        {moves::X2, [](const Cube &c) { return c.X2(); }},
        {moves::Y2, [](const Cube &c) { return c.Y2(); }},
        {moves::Z2, [](const Cube &c) { return c.Z2(); }}
    };

    for(const string &m : moves) {
        newCube = move_options.at(m)(newCube);
    }

    return newCube;
}
