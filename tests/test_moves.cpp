#include "gtest/gtest.h"
#include "toml.hpp"
#include "cube.hpp"
#include "moves.hpp"
#include "common.hpp"

#include <array>
#include <vector>
#include <string>
#include <cstdint>
#include <stdexcept>

using namespace std;

uint32_t string2colornum(string str) {
    if(str == "W") { return WHITE; }
    else if(str == "Y") { return YELLOW; }
    else if(str == "G") { return GREEN; }
    else if(str == "B") { return BLUE; }
    else if(str == "R") { return RED; }
    else if(str == "O") { return ORANGE; }
    else { throw invalid_argument("Unknown color read from TOML: " + str + "\n"); }
}

void set_face(toml::v3::node_view<toml::v3::node> node_view, uint32_t &face) {
    uint8_t i = 0;
    array<uint8_t, 9> shifts = {
        TOP_LEFT,
        TOP_MIDDLE,
        TOP_RIGHT,
        MIDDLE_LEFT,
        CENTER,
        MIDDLE_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_MIDDLE,
        BOTTOM_RIGHT
    };
    
    if(node_view.is_array()) {
        toml::array *toml_arr = node_view.as_array();
        for(auto&& elem : *toml_arr) {
            if(elem.is_string()) {
                face |= (string2colornum(*elem.value<std::string>()) << shifts[i++]);
            } else {
                cerr << "Non string element found when string element expected!" << endl;
            }
        }
    } else {
        //? add a helpful message
    }
}

array<uint32_t, 6> state(string toml_path) {
    array<uint8_t, 9> shifts = {
        TOP_LEFT,
        TOP_MIDDLE,
        TOP_RIGHT,
        MIDDLE_LEFT,
        CENTER,
        MIDDLE_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_MIDDLE,
        BOTTOM_RIGHT
    };

    array<uint8_t, 6> colors = {WHITE, GREEN, RED, BLUE, ORANGE, YELLOW};
    array<uint32_t, 6> state;
    vector<uint32_t> state_vector;

    
    try {
        toml::table solution = toml::parse_file(toml_path);
        
        uint32_t up = 0, front = 0, left = 0, right = 0, back = 0, down = 0;
        uint8_t u = 0, d = 0, l = 0, r = 0, f = 0, b = 0;

        if(auto node_view = solution["up"]) { set_face(node_view, up); }
        if(auto node_view = solution["front"]) { set_face(node_view, front); }
        if(auto node_view = solution["left"]) { set_face(node_view, left); }
        if(auto node_view = solution["right"]) { set_face(node_view, right); }
        if(auto node_view = solution["back"]) { set_face(node_view, back); }
        if(auto node_view = solution["down"]) { set_face(node_view, down); }

        uint8_t c_up = static_cast<uint8_t>((up << CLEAR_CENTER) >> CLEAR);
        uint8_t c_down = static_cast<uint8_t>((down << CLEAR_CENTER) >> CLEAR);
        uint8_t c_front = static_cast<uint8_t>((front << CLEAR_CENTER) >> CLEAR);
        uint8_t c_back = static_cast<uint8_t>((back << CLEAR_CENTER) >> CLEAR);
        uint8_t c_left = static_cast<uint8_t>((left << CLEAR_CENTER) >> CLEAR);
        uint8_t c_right = static_cast<uint8_t>((right << CLEAR_CENTER) >> CLEAR);

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
    } catch (const toml::parse_error& err) {
        cerr << "Error parsing TOML file: " << err << std::endl;
    }

    return state;
}

class MoveTest : public ::testing::Test {
protected:
    Cube solved;

    void SetUp() override {
        // No setup required for now
    }
};

TEST_F(MoveTest, solved) {
    array<uint32_t, 6> sol = state("solutions/solved/solved.toml");
    vector<uint32_t> sat = solved.get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, U) {
    array<uint32_t, 6> sol = state("solutions/faces/U.toml");
    vector<uint32_t> sat = solved.U().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, U_prime) {
    array<uint32_t, 6> sol = state("solutions/faces/U_prime.toml");
    vector<uint32_t> sat = solved.U_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, U2) {
    array<uint32_t, 6> sol = state("solutions/faces/U2.toml");
    vector<uint32_t> sat = solved.U2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, D) {
    array<uint32_t, 6> sol = state("solutions/faces/D.toml");
    vector<uint32_t> sat = solved.D().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, D_prime) {
    array<uint32_t, 6> sol = state("solutions/faces/D_prime.toml");
    vector<uint32_t> sat = solved.D_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, D2) {
    array<uint32_t, 6> sol = state("solutions/faces/D2.toml");
    vector<uint32_t> sat = solved.D2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, L) {
    array<uint32_t, 6> sol = state("solutions/faces/L.toml");
    vector<uint32_t> sat = solved.L().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, L_prime) {
    array<uint32_t, 6> sol = state("solutions/faces/L_prime.toml");
    vector<uint32_t> sat = solved.L_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, L2) {
    array<uint32_t, 6> sol = state("solutions/faces/L2.toml");
    vector<uint32_t> sat = solved.L2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, R) {
    array<uint32_t, 6> sol = state("solutions/faces/R.toml");
    vector<uint32_t> sat = solved.R().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, R_prime) {
    array<uint32_t, 6> sol = state("solutions/faces/R_prime.toml");
    vector<uint32_t> sat = solved.R_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, R2) {
    array<uint32_t, 6> sol = state("solutions/faces/R2.toml");
    vector<uint32_t> sat = solved.R2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, F) {
    array<uint32_t, 6> sol = state("solutions/faces/F.toml");
    vector<uint32_t> sat = solved.F().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, F_prime) {
    array<uint32_t, 6> sol = state("solutions/faces/F_prime.toml");
    vector<uint32_t> sat = solved.F_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, F2) {
    array<uint32_t, 6> sol = state("solutions/faces/F2.toml");
    vector<uint32_t> sat = solved.F2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, B) {
    array<uint32_t, 6> sol = state("solutions/faces/B.toml");
    vector<uint32_t> sat = solved.B().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, B_prime) {
    array<uint32_t, 6> sol = state("solutions/faces/B_prime.toml");
    vector<uint32_t> sat = solved.B_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, B2) {
    array<uint32_t, 6> sol = state("solutions/faces/B2.toml");
    vector<uint32_t> sat = solved.B2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, M) {
    array<uint32_t, 6> sol = state("solutions/slices/M.toml");
    vector<uint32_t> sat = solved.M().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, M_prime) {
    array<uint32_t, 6> sol = state("solutions/slices/M_prime.toml");
    vector<uint32_t> sat = solved.M_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, M2) {
    array<uint32_t, 6> sol = state("solutions/slices/M2.toml");
    vector<uint32_t> sat = solved.M2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, E) {
    array<uint32_t, 6> sol = state("solutions/slices/E.toml");
    vector<uint32_t> sat = solved.E().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, E_prime) {
    array<uint32_t, 6> sol = state("solutions/slices/E_prime.toml");
    vector<uint32_t> sat = solved.E_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, E2) {
    array<uint32_t, 6> sol = state("solutions/slices/E2.toml");
    vector<uint32_t> sat = solved.E2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, S) {
    array<uint32_t, 6> sol = state("solutions/slices/S.toml");
    vector<uint32_t> sat = solved.S().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, S_prime) {
    array<uint32_t, 6> sol = state("solutions/slices/S_prime.toml");
    vector<uint32_t> sat = solved.S_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, S2) {
    array<uint32_t, 6> sol = state("solutions/slices/S2.toml");
    vector<uint32_t> sat = solved.S2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, X) {
    array<uint32_t, 6> sol = state("solutions/rotation/X.toml");
    vector<uint32_t> sat = solved.X().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, X_prime) {
    array<uint32_t, 6> sol = state("solutions/rotation/X_prime.toml");
    vector<uint32_t> sat = solved.X_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, X2) {
    array<uint32_t, 6> sol = state("solutions/rotation/X2.toml");
    vector<uint32_t> sat = solved.X2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, Y) {
    array<uint32_t, 6> sol = state("solutions/rotation/Y.toml");
    vector<uint32_t> sat = solved.Y().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, Y_prime) {
    array<uint32_t, 6> sol = state("solutions/rotation/Y_prime.toml");
    vector<uint32_t> sat = solved.Y_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, Y2) {
    array<uint32_t, 6> sol = state("solutions/rotation/Y2.toml");
    vector<uint32_t> sat = solved.Y2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, Z) {
    array<uint32_t, 6> sol = state("solutions/rotation/Z.toml");
    vector<uint32_t> sat = solved.Z().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, Z_prime) {
    array<uint32_t, 6> sol = state("solutions/rotation/Z_prime.toml");
    vector<uint32_t> sat = solved.Z_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, Z2) {
    array<uint32_t, 6> sol = state("solutions/rotation/Z2.toml");
    vector<uint32_t> sat = solved.Z2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, u) {
    array<uint32_t, 6> sol = state("solutions/wide/u.toml");
    vector<uint32_t> sat = solved.u().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, u_prime) {
    array<uint32_t, 6> sol = state("solutions/wide/u_prime.toml");
    vector<uint32_t> sat = solved.u_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, u2) {
    array<uint32_t, 6> sol = state("solutions/wide/u2.toml");
    vector<uint32_t> sat = solved.u2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, d) {
    array<uint32_t, 6> sol = state("solutions/wide/d.toml");
    vector<uint32_t> sat = solved.d().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, d_prime) {
    array<uint32_t, 6> sol = state("solutions/wide/d_prime.toml");
    vector<uint32_t> sat = solved.d_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, d2) {
    array<uint32_t, 6> sol = state("solutions/wide/d2.toml");
    vector<uint32_t> sat = solved.d2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, l) {
    array<uint32_t, 6> sol = state("solutions/wide/l.toml");
    vector<uint32_t> sat = solved.l().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, l_prime) {
    array<uint32_t, 6> sol = state("solutions/wide/l_prime.toml");
    vector<uint32_t> sat = solved.l_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, l2) {
    array<uint32_t, 6> sol = state("solutions/wide/l2.toml");
    vector<uint32_t> sat = solved.l2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, r) {
    array<uint32_t, 6> sol = state("solutions/wide/r.toml");
    vector<uint32_t> sat = solved.r().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, r_prime) {
    array<uint32_t, 6> sol = state("solutions/wide/r_prime.toml");
    vector<uint32_t> sat = solved.r_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, r2) {
    array<uint32_t, 6> sol = state("solutions/wide/r2.toml");
    vector<uint32_t> sat = solved.r2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, f) {
    array<uint32_t, 6> sol = state("solutions/wide/f.toml");
    vector<uint32_t> sat = solved.f().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, f_prime) {
    array<uint32_t, 6> sol = state("solutions/wide/f_prime.toml");
    vector<uint32_t> sat = solved.f_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, f2) {
    array<uint32_t, 6> sol = state("solutions/wide/f2.toml");
    vector<uint32_t> sat = solved.f2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, b) {
    array<uint32_t, 6> sol = state("solutions/wide/b.toml");
    vector<uint32_t> sat = solved.b().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, b_prime) {
    array<uint32_t, 6> sol = state("solutions/wide/b_prime.toml");
    vector<uint32_t> sat = solved.b_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, b2) {
    array<uint32_t, 6> sol = state("solutions/wide/b2.toml");
    vector<uint32_t> sat = solved.b2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, checkers1) {
    array<uint32_t, 6> sol = state("solutions/composite/checkers.toml");
    vector<uint32_t> sat = solved.R2().L2().F2().B2().U2().D2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, checkers2) {
    array<uint32_t, 6> sol = state("solutions/composite/checkers.toml");
    vector<uint32_t> sat = solved.M2().E2().S2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, scramble1) {
    array<uint32_t, 6> sol = state("solutions/composite/scramble.toml");
    vector<uint32_t> sat = solved.U2().R2().D().F_prime().R2().B2().D().R_prime().D2().B_prime().R2().F2().D2().R2().L2().B().L2().U2().B().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, scramble2) {
    array<uint32_t, 6> sol = state("solutions/composite/scramble.toml");
    vector<string> moves = {moves::U2, moves::R2, moves::D, moves::F_prime, moves::R2, moves::B2, moves::D, moves::R_prime, moves::D2, moves::B_prime, moves::R2, moves::F2, moves::D2, moves::R2, moves::L2, moves::B, moves::L2, moves::U2, moves::B};
    vector<uint32_t> sat = solved.apply_moves(moves).get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}
