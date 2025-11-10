#include <gtest/gtest.h>
#include "cube.hpp"

class CubeTest : public ::testing::Test {
protected:
    Cube solved;

    void SetUp() override {
        // No setup required for now
    }
};

TEST_F(CubeTest, CubeIsSolvedAtStart) {
    EXPECT_TRUE(solved.isSolved());
}

TEST_F(CubeTest, SingleMoveUnsolvesCube) {
    Cube moved = solved.U();
    EXPECT_FALSE(moved.isSolved());
}

TEST_F(CubeTest, FourSameMovesRestoreCube) {
    Cube moved = solved.U().U().U().U();
    EXPECT_TRUE(moved.isSolved());
}

TEST_F(CubeTest, InverseMoveRestoresCube) {
    Cube moved = solved.U().U_prime();
    EXPECT_TRUE(moved.isSolved());
}

TEST_F(CubeTest, DifferentMovesYieldDifferentStates) {
    Cube u = solved.U();
    Cube r = solved.R();
    EXPECT_FALSE(u.isSolved());
    EXPECT_FALSE(r.isSolved());
    EXPECT_NE(u, r);
}

TEST_F(CubeTest, NoMutationOnOriginalCube) {
    Cube u = solved.U();
    EXPECT_TRUE(solved.isSolved()); // original should still be solved
    EXPECT_FALSE(u.isSolved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeUR) {
    Cube scrambled = solved.U().R();
    Cube restored = scrambled.R_prime().U_prime();
    EXPECT_TRUE(restored.isSolved());

    scrambled = solved.R().U();
    restored = scrambled.U_prime().R_prime();
    EXPECT_TRUE(restored.isSolved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeUR_) {
    Cube scrambled = solved.U_prime().R_prime();
    Cube restored = scrambled.R().U();
    EXPECT_TRUE(restored.isSolved());

    scrambled = solved.R_prime().U_prime();
    restored = scrambled.U().R();
    EXPECT_TRUE(restored.isSolved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeUL) {
    Cube scrambled = solved.U().L();
    Cube restored = scrambled.L_prime().U_prime();
    EXPECT_TRUE(restored.isSolved());

    scrambled = solved.L().U();
    restored = scrambled.U_prime().L_prime();
    EXPECT_TRUE(restored.isSolved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeUL_) {
    Cube scrambled = solved.U_prime().L_prime();
    Cube restored = scrambled.L().U();
    EXPECT_TRUE(restored.isSolved());

    scrambled = solved.L_prime().U_prime();
    restored = scrambled.U().L();
    EXPECT_TRUE(restored.isSolved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeFD) {
    Cube scrambled = solved.F().D();
    Cube restored = scrambled.D_prime().F_prime();
    EXPECT_TRUE(restored.isSolved());

    scrambled = solved.D().F();
    restored = scrambled.F_prime().D_prime();
    EXPECT_TRUE(restored.isSolved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeFD_) {
    Cube scrambled = solved.F_prime().D_prime();
    Cube restored = scrambled.D().F();
    EXPECT_TRUE(restored.isSolved());

    scrambled = solved.D_prime().F_prime();
    restored = scrambled.F().D();
    EXPECT_TRUE(restored.isSolved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeBD) {
    Cube scrambled = solved.B().D();
    Cube restored = scrambled.D_prime().B_prime();
    EXPECT_TRUE(restored.isSolved());

    scrambled = solved.D().B();
    restored = scrambled.B_prime().D_prime();
    EXPECT_TRUE(restored.isSolved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCubeBD_) {
    Cube scrambled = solved.B_prime().D_prime();
    Cube restored = scrambled.D().B();
    EXPECT_TRUE(restored.isSolved());

    scrambled = solved.D_prime().B_prime();
    restored = scrambled.B().D();
    EXPECT_TRUE(restored.isSolved());
}

TEST_F(CubeTest, WholeRotationIsSame) {
    Cube x = solved.X();
    Cube y = solved.Y();
    Cube z = solved.Z();
    EXPECT_TRUE(solved == x);
    EXPECT_TRUE(solved == y);
    EXPECT_TRUE(solved == z);
}
