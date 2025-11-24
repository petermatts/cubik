#include "gtest/gtest.h"
#include "toml_helper.hpp"
#include "cube.hpp"
#include "moves.hpp"

#include <array>
#include <vector>
#include <string>
#include <cstdint>
#include <stdexcept>

using namespace std;

class MoveTest : public ::testing::Test {
protected:
    Cube solved;

    void SetUp() override {
        // No setup required for now
    }
};

TEST_F(MoveTest, solved) {
    vector<uint32_t> sol = state("solutions/solved/solved.toml");
    vector<uint32_t> sat = solved.get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, U) {
    vector<uint32_t> sol = state("solutions/faces/U.toml");
    vector<uint32_t> sat = solved.U().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, U_prime) {
    vector<uint32_t> sol = state("solutions/faces/U_prime.toml");
    vector<uint32_t> sat = solved.U_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, U2) {
    vector<uint32_t> sol = state("solutions/faces/U2.toml");
    vector<uint32_t> sat = solved.U2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, D) {
    vector<uint32_t> sol = state("solutions/faces/D.toml");
    vector<uint32_t> sat = solved.D().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, D_prime) {
    vector<uint32_t> sol = state("solutions/faces/D_prime.toml");
    vector<uint32_t> sat = solved.D_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, D2) {
    vector<uint32_t> sol = state("solutions/faces/D2.toml");
    vector<uint32_t> sat = solved.D2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, L) {
    vector<uint32_t> sol = state("solutions/faces/L.toml");
    vector<uint32_t> sat = solved.L().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, L_prime) {
    vector<uint32_t> sol = state("solutions/faces/L_prime.toml");
    vector<uint32_t> sat = solved.L_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, L2) {
    vector<uint32_t> sol = state("solutions/faces/L2.toml");
    vector<uint32_t> sat = solved.L2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, R) {
    vector<uint32_t> sol = state("solutions/faces/R.toml");
    vector<uint32_t> sat = solved.R().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, R_prime) {
    vector<uint32_t> sol = state("solutions/faces/R_prime.toml");
    vector<uint32_t> sat = solved.R_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, R2) {
    vector<uint32_t> sol = state("solutions/faces/R2.toml");
    vector<uint32_t> sat = solved.R2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, F) {
    vector<uint32_t> sol = state("solutions/faces/F.toml");
    vector<uint32_t> sat = solved.F().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, F_prime) {
    vector<uint32_t> sol = state("solutions/faces/F_prime.toml");
    vector<uint32_t> sat = solved.F_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, F2) {
    vector<uint32_t> sol = state("solutions/faces/F2.toml");
    vector<uint32_t> sat = solved.F2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, B) {
    vector<uint32_t> sol = state("solutions/faces/B.toml");
    vector<uint32_t> sat = solved.B().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, B_prime) {
    vector<uint32_t> sol = state("solutions/faces/B_prime.toml");
    vector<uint32_t> sat = solved.B_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, B2) {
    vector<uint32_t> sol = state("solutions/faces/B2.toml");
    vector<uint32_t> sat = solved.B2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, M) {
    vector<uint32_t> sol = state("solutions/slices/M.toml");
    vector<uint32_t> sat = solved.M().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, M_prime) {
    vector<uint32_t> sol = state("solutions/slices/M_prime.toml");
    vector<uint32_t> sat = solved.M_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, M2) {
    vector<uint32_t> sol = state("solutions/slices/M2.toml");
    vector<uint32_t> sat = solved.M2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, E) {
    vector<uint32_t> sol = state("solutions/slices/E.toml");
    vector<uint32_t> sat = solved.E().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, E_prime) {
    vector<uint32_t> sol = state("solutions/slices/E_prime.toml");
    vector<uint32_t> sat = solved.E_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, E2) {
    vector<uint32_t> sol = state("solutions/slices/E2.toml");
    vector<uint32_t> sat = solved.E2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, S) {
    vector<uint32_t> sol = state("solutions/slices/S.toml");
    vector<uint32_t> sat = solved.S().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, S_prime) {
    vector<uint32_t> sol = state("solutions/slices/S_prime.toml");
    vector<uint32_t> sat = solved.S_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, S2) {
    vector<uint32_t> sol = state("solutions/slices/S2.toml");
    vector<uint32_t> sat = solved.S2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, X) {
    vector<uint32_t> sol = state("solutions/rotation/X.toml");
    vector<uint32_t> sat = solved.X().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, X_prime) {
    vector<uint32_t> sol = state("solutions/rotation/X_prime.toml");
    vector<uint32_t> sat = solved.X_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, X2) {
    vector<uint32_t> sol = state("solutions/rotation/X2.toml");
    vector<uint32_t> sat = solved.X2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, Y) {
    vector<uint32_t> sol = state("solutions/rotation/Y.toml");
    vector<uint32_t> sat = solved.Y().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, Y_prime) {
    vector<uint32_t> sol = state("solutions/rotation/Y_prime.toml");
    vector<uint32_t> sat = solved.Y_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, Y2) {
    vector<uint32_t> sol = state("solutions/rotation/Y2.toml");
    vector<uint32_t> sat = solved.Y2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, Z) {
    vector<uint32_t> sol = state("solutions/rotation/Z.toml");
    vector<uint32_t> sat = solved.Z().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, Z_prime) {
    vector<uint32_t> sol = state("solutions/rotation/Z_prime.toml");
    vector<uint32_t> sat = solved.Z_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, Z2) {
    vector<uint32_t> sol = state("solutions/rotation/Z2.toml");
    vector<uint32_t> sat = solved.Z2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, u) {
    vector<uint32_t> sol = state("solutions/wide/u.toml");
    vector<uint32_t> sat = solved.u().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, u_prime) {
    vector<uint32_t> sol = state("solutions/wide/u_prime.toml");
    vector<uint32_t> sat = solved.u_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, u2) {
    vector<uint32_t> sol = state("solutions/wide/u2.toml");
    vector<uint32_t> sat = solved.u2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, d) {
    vector<uint32_t> sol = state("solutions/wide/d.toml");
    vector<uint32_t> sat = solved.d().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, d_prime) {
    vector<uint32_t> sol = state("solutions/wide/d_prime.toml");
    vector<uint32_t> sat = solved.d_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, d2) {
    vector<uint32_t> sol = state("solutions/wide/d2.toml");
    vector<uint32_t> sat = solved.d2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, l) {
    vector<uint32_t> sol = state("solutions/wide/l.toml");
    vector<uint32_t> sat = solved.l().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, l_prime) {
    vector<uint32_t> sol = state("solutions/wide/l_prime.toml");
    vector<uint32_t> sat = solved.l_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, l2) {
    vector<uint32_t> sol = state("solutions/wide/l2.toml");
    vector<uint32_t> sat = solved.l2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, r) {
    vector<uint32_t> sol = state("solutions/wide/r.toml");
    vector<uint32_t> sat = solved.r().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, r_prime) {
    vector<uint32_t> sol = state("solutions/wide/r_prime.toml");
    vector<uint32_t> sat = solved.r_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, r2) {
    vector<uint32_t> sol = state("solutions/wide/r2.toml");
    vector<uint32_t> sat = solved.r2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, f) {
    vector<uint32_t> sol = state("solutions/wide/f.toml");
    vector<uint32_t> sat = solved.f().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, f_prime) {
    vector<uint32_t> sol = state("solutions/wide/f_prime.toml");
    vector<uint32_t> sat = solved.f_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, f2) {
    vector<uint32_t> sol = state("solutions/wide/f2.toml");
    vector<uint32_t> sat = solved.f2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, b) {
    vector<uint32_t> sol = state("solutions/wide/b.toml");
    vector<uint32_t> sat = solved.b().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, b_prime) {
    vector<uint32_t> sol = state("solutions/wide/b_prime.toml");
    vector<uint32_t> sat = solved.b_prime().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, b2) {
    vector<uint32_t> sol = state("solutions/wide/b2.toml");
    vector<uint32_t> sat = solved.b2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, checkers1) {
    vector<uint32_t> sol = state("solutions/composite/checkers.toml");
    vector<uint32_t> sat = solved.R2().L2().F2().B2().U2().D2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, checkers2) {
    vector<uint32_t> sol = state("solutions/composite/checkers.toml");
    vector<uint32_t> sat = solved.M2().E2().S2().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, scramble1) {
    vector<uint32_t> sol = state("solutions/composite/scramble.toml");
    vector<uint32_t> sat = solved.U2().R2().D().F_prime().R2().B2().D().R_prime().D2().B_prime().R2().F2().D2().R2().L2().B().L2().U2().B().get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}

TEST_F(MoveTest, scramble2) {
    vector<uint32_t> sol = state("solutions/composite/scramble.toml");
    vector<string> moves = {moves::U2, moves::R2, moves::D, moves::F_prime, moves::R2, moves::B2, moves::D, moves::R_prime, moves::D2, moves::B_prime, moves::R2, moves::F2, moves::D2, moves::R2, moves::L2, moves::B, moves::L2, moves::U2, moves::B};
    vector<uint32_t> sat = solved.apply_moves(moves).get_state();

    for (int i = 0; i < 6; i++) {
        EXPECT_TRUE(sol[i] == sat[i]);
    }
}
