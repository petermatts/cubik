#include "common.hpp"
#include "cube.hpp"
#include "moves.hpp"

#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <stdexcept>

using namespace std;

static const array<vector<string>, 24> rotations = {{
    // --- Identity ---
    {},

    // --- Rotations around X ---
    { moves::X },
    { moves::X2 },
    { moves::X_prime },

    // --- Rotations around Y ---
    { moves::Y },
    { moves::Y2 },
    { moves::Y_prime },

    // --- Rotations around Z ---
    { moves::Z },
    { moves::Z2 },
    { moves::Z_prime},

    // --- Tilt cube using X, then spin using Y ---
    { moves::X, moves::Y },
    { moves::X, moves::Y2 },
    { moves::X, moves::Y_prime },

    // --- Tilt cube using X twice, then spin using Y ---
    { moves::X2, moves::Y },
    { moves::X2, moves::Y2},
    { moves::X2, moves::Y_prime },

    // --- Tilt cube using X3, then spin using Y ---
    { moves::X_prime, moves::Y },
    { moves::X_prime, moves::Y2 },
    { moves::X_prime, moves::Y_prime },

    // --- Tilt cube using Y, then spin using Z ---
    { moves::Y, moves::Z },
    { moves::Y, moves::Z2 },
    { moves::Y, moves::Z_prime},
}};

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

vector<uint32_t> Cube::get_state() const {
    vector<uint32_t> state_vector = {up, front, right, back, left, down};

    return state_vector;
}

bool Cube::set_state(const vector<uint32_t> &state) {
    if(state.size() != 6) return false;

    // Save current state in case the new one is invalid
    uint32_t old_up    = up;
    uint32_t old_down  = down;
    uint32_t old_left  = left;
    uint32_t old_right = right;
    uint32_t old_front = front;
    uint32_t old_back  = back;

    up    = state[0];
    front = state[1];
    right = state[2];
    back  = state[3];
    left  = state[4];
    down  = state[5];

    // Validate the cube
    if (!is_valid_state())
    {
        // Restore old state if invalid
        up    = old_up;
        down  = old_down;
        left  = old_left;
        right = old_right;
        front = old_front;
        back  = old_back;

        return false;
    }

    return true;
}

bool Cube::is_solved() {
    return *this == Cube();
}

string Cube::toString() const {
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

bool Cube::is_rotation_equal(Cube &other) const {
    vector<uint32_t> this_state = this->get_state();
    
    for (auto rotation : rotations) {
        vector<uint32_t> other_state = other.apply_moves(rotation).get_state();
        if (this_state == other_state) return true;
    }

    return false;
}

bool operator==(const Cube &cube1, const Cube &cube2) {
    return cube1.get_state() == cube2.get_state();
}

bool operator!=(const Cube &cube1, const Cube &cube2) {
    return !(cube1 == cube2);
}

std::ostream& operator<<(std::ostream& os, const Cube& obj) {
    os << obj.toString();
    return os;
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

Cube Cube::apply(const string &move) {
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

    return move_options.at(move)(newCube);
}

Cube Cube::apply_moves(const vector<string> &moves) {
    Cube newCube = *this;

    for(const string &m : moves) {
        newCube = newCube.apply(m);
    }

    return newCube;
}

Cube Cube::canonical() const {
    Cube tempCube = *this;

    auto faces = get_state();

    if (!verify_centers()) {
        throw logic_error("Cube orientation/centers are bad, cannot canonicalize.");
    }

    for (auto rotation : rotations) {
        Cube rotated = tempCube.apply_moves(rotation);
        if (get(rotated.up, CENTER) == WHITE &&
            get(rotated.front, CENTER) == GREEN &&
            get(rotated.right, CENTER) == RED &&
            get(rotated.back, CENTER) == BLUE &&
            get(rotated.left, CENTER) == ORANGE &&
            get(rotated.down, CENTER) == YELLOW) {return rotated; }
    }

    throw logic_error("This should never happen");
}
