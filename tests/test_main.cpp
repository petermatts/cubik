#include <gtest/gtest.h>
#include <vector>
#include "cube.hpp"

class CubeTest : public ::testing::Test {
protected:
    Cube solved;

    void SetUp() override {
        // No setup required for now
    }
};

TEST_F(CubeTest, Cubeis_solvedAtStart) {
    EXPECT_TRUE(solved.is_solved());
}

TEST_F(CubeTest, SingleMoveUnsolvesCube) {
    Cube moved = solved.U();
    EXPECT_FALSE(moved.is_solved());
}

TEST_F(CubeTest, FourSameMovesRestoreCube) {
    Cube moved = solved.U().U().U().U();
    EXPECT_TRUE(moved.is_solved());
}

TEST_F(CubeTest, InverseMoveRestoresCube) {
    Cube moved = solved.U().U_prime();
    EXPECT_TRUE(moved.is_solved());
}

TEST_F(CubeTest, DifferentMovesYieldDifferentStates) {
    Cube u = solved.U();
    Cube r = solved.R();
    EXPECT_FALSE(u.is_solved());
    EXPECT_FALSE(r.is_solved());
    EXPECT_NE(u, r);
}

TEST_F(CubeTest, NoMutationOnOriginalCube) {
    Cube u = solved.U();
    EXPECT_TRUE(solved.is_solved()); // original should still be solved
    EXPECT_FALSE(u.is_solved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeUR) {
    Cube scrambled = solved.U().R();
    Cube restored = scrambled.R_prime().U_prime();
    EXPECT_TRUE(restored.is_solved());

    scrambled = solved.R().U();
    restored = scrambled.U_prime().R_prime();
    EXPECT_TRUE(restored.is_solved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeUR_) {
    Cube scrambled = solved.U_prime().R_prime();
    Cube restored = scrambled.R().U();
    EXPECT_TRUE(restored.is_solved());

    scrambled = solved.R_prime().U_prime();
    restored = scrambled.U().R();
    EXPECT_TRUE(restored.is_solved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeUL) {
    Cube scrambled = solved.U().L();
    Cube restored = scrambled.L_prime().U_prime();
    EXPECT_TRUE(restored.is_solved());

    scrambled = solved.L().U();
    restored = scrambled.U_prime().L_prime();
    EXPECT_TRUE(restored.is_solved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeUL_) {
    Cube scrambled = solved.U_prime().L_prime();
    Cube restored = scrambled.L().U();
    EXPECT_TRUE(restored.is_solved());

    scrambled = solved.L_prime().U_prime();
    restored = scrambled.U().L();
    EXPECT_TRUE(restored.is_solved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeFD) {
    Cube scrambled = solved.F().D();
    Cube restored = scrambled.D_prime().F_prime();
    EXPECT_TRUE(restored.is_solved());

    scrambled = solved.D().F();
    restored = scrambled.F_prime().D_prime();
    EXPECT_TRUE(restored.is_solved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeFD_) {
    Cube scrambled = solved.F_prime().D_prime();
    Cube restored = scrambled.D().F();
    EXPECT_TRUE(restored.is_solved());

    scrambled = solved.D_prime().F_prime();
    restored = scrambled.F().D();
    EXPECT_TRUE(restored.is_solved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeBD) {
    Cube scrambled = solved.B().D();
    Cube restored = scrambled.D_prime().B_prime();
    EXPECT_TRUE(restored.is_solved());

    scrambled = solved.D().B();
    restored = scrambled.B_prime().D_prime();
    EXPECT_TRUE(restored.is_solved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeBD_) {
    Cube scrambled = solved.B_prime().D_prime();
    Cube restored = scrambled.D().B();
    EXPECT_TRUE(restored.is_solved());

    scrambled = solved.D_prime().B_prime();
    restored = scrambled.B().D();
    EXPECT_TRUE(restored.is_solved());
}

TEST_F(CubeTest, WholeRotationEqualEqualNotSame) {
    Cube x = solved.X();
    Cube y = solved.Y();
    Cube z = solved.Z();
    EXPECT_FALSE(solved == x);
    EXPECT_FALSE(solved == y);
    EXPECT_FALSE(solved == z);
}

TEST_F(CubeTest, WholeRotationIsRotationEqual) {
    Cube x = solved.X();
    Cube y = solved.Y();
    Cube z = solved.Z();
    EXPECT_TRUE(solved.is_rotation_equal(x));
    EXPECT_TRUE(solved.is_rotation_equal(y));
    EXPECT_TRUE(solved.is_rotation_equal(z));
}

TEST_F(CubeTest, LoadedIsSameAsOriginal) {
    std::vector<uint32_t> solved_state = solved.get_state();
    Cube x;
    x.set_state(solved_state);
    EXPECT_TRUE(solved == x);

    std::vector<uint32_t> r_state = solved.R().get_state();
    bool result = x.set_state(r_state);
    EXPECT_TRUE(solved.R() == x);
}

TEST_F(CubeTest, CanonicalIsSame) {
    Cube canon = solved.canonical();
    EXPECT_TRUE(solved == canon);
}

TEST_F(CubeTest, CanonicalMoved) {
    Cube R = solved.R();
    EXPECT_TRUE(R == R.canonical());

    Cube RX = R.X();
    EXPECT_FALSE(RX == RX.canonical());
    EXPECT_TRUE(RX.canonical() == R);

    Cube RY = R.Y();
    EXPECT_FALSE(RY == RY.canonical());
    EXPECT_TRUE(RY.canonical() == R);

    Cube RZ = R.Z();
    EXPECT_FALSE(RZ == RZ.canonical());
    EXPECT_TRUE(RZ.canonical() == R);
}

TEST_F(CubeTest, SingleMoveIsAlsoWideMove) {
    Cube l2 = solved.l2();
    Cube R2 = solved.R2();

    EXPECT_TRUE(l2.is_rotation_equal(R2));
    EXPECT_FALSE(l2 == R2);
}
