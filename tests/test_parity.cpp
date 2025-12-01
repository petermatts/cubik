#include "gtest/gtest.h"
#include <iostream>
#include <stdexcept>
#include "toml_helper.hpp"
#include "cube.hpp"

using namespace std;

class ParityTest : public ::testing::Test {
protected:
    Cube cube;

    void SetUp() override {
        // No setup required for now
    }
};

TEST_F(ParityTest, solved) {
    EXPECT_TRUE(cube.is_valid_state());
    EXPECT_TRUE(cube.is_solved());
}

TEST_F(ParityTest, SimpleMove) {
    auto moved = cube.R();
    EXPECT_TRUE(moved.is_valid_state());
}

TEST_F(ParityTest, EdgeFlip) {
    vector<uint32_t> st = state("solutions/parity/EdgeOrientation.toml"); 
    EXPECT_FALSE(cube.set_state(st));
}

TEST_F(ParityTest, EdgePermutation) {
    vector<uint32_t> st = state("solutions/parity/EdgePermutation.toml"); 
    EXPECT_FALSE(cube.set_state(st));
}

TEST_F(ParityTest, TooManyOfAColor) {
    vector<uint32_t> st = state("solutions/parity/OverColor.toml"); 
    EXPECT_THROW(cube.set_state(st), std::logic_error);
}

TEST_F(ParityTest, TwistedCorner) {
    vector<uint32_t> st = state("solutions/parity/TwistedCorner.toml"); 
    EXPECT_FALSE(cube.set_state(st));
}

TEST_F(ParityTest, TwistedCorner2) {
    vector<uint32_t> st = state("solutions/parity/TwistedCorner2.toml"); 
    EXPECT_FALSE(cube.set_state(st));
}

TEST_F(ParityTest, TwistedCorners) {
    vector<uint32_t> st = state("solutions/parity/TwistedCorners.toml"); 
    EXPECT_FALSE(cube.set_state(st));
}

TEST_F(ParityTest, TwistedCornersValid) {
    vector<uint32_t> st = state("solutions/parity/TwistedCornersValid.toml"); 
    EXPECT_TRUE(cube.set_state(st));
}

TEST_F(ParityTest, CornerPermutationBad) {
    vector<uint32_t> st = state("solutions/parity/CornerPermutationBad.toml"); 
    EXPECT_FALSE(cube.set_state(st));
}

TEST_F(ParityTest, CornerPermutationGood) {
    vector<uint32_t> st = state("solutions/parity/CornerPermutationGood.toml"); 
    EXPECT_TRUE(cube.set_state(st));
}

TEST_F(ParityTest, CornerOrientationBad) {
    vector<uint32_t> st = state("solutions/parity/CornerOrientationBad.toml"); 
    EXPECT_FALSE(cube.set_state(st));
}

TEST_F(ParityTest, ScrambleGood) {
    vector<uint32_t> st = state("solutions/parity/ScrambleGood.toml"); 
    EXPECT_TRUE(cube.set_state(st));
}

TEST_F(ParityTest, ScrambleBad) {
    vector<uint32_t> st = state("solutions/parity/ScrambleBad.toml"); 
    EXPECT_FALSE(cube.set_state(st));
}

TEST_F(ParityTest, BadCenters) {
    vector<uint32_t> st = state("solutions/parity/BadCenters.toml"); 
    EXPECT_THROW(cube.set_state(st), std::logic_error);
}

TEST_F(ParityTest, BadCornerAndEdge) {
    vector<uint32_t> st = state("solutions/parity/BadCornerAndEdge.toml"); 
    EXPECT_FALSE(cube.set_state(st));
}

TEST_F(ParityTest, ScrambleBadCorner) {
    vector<uint32_t> st = state("solutions/parity/ScrambleBadCorner.toml"); 
    EXPECT_FALSE(cube.set_state(st));
}

TEST_F(ParityTest, ScrambleBadEdge) {
    vector<uint32_t> st = state("solutions/parity/ScrambleBadEdge.toml"); 
    EXPECT_FALSE(cube.set_state(st));
}

TEST_F(ParityTest, ScrambleBadEdgeAndCorner) {
    vector<uint32_t> st = state("solutions/parity/ScrambleBadEdgeAndCorner.toml"); 
    EXPECT_FALSE(cube.set_state(st));
}

TEST_F(ParityTest, DoubleEdgeFlip) {
    vector<uint32_t> st = state("solutions/parity/DoubleEdgeFlip.toml"); 
    EXPECT_TRUE(cube.set_state(st));
}

TEST_F(ParityTest, SolvedRotatedX) {
    vector<uint32_t> st = state("solutions/rotation/X.toml"); 
    EXPECT_TRUE(cube.set_state(st));
}

TEST_F(ParityTest, SolvedRotatedY) {
    vector<uint32_t> st = state("solutions/rotation/Y.toml"); 
    EXPECT_TRUE(cube.set_state(st));
}

TEST_F(ParityTest, SolvedRotatedZ) {
    vector<uint32_t> st = state("solutions/rotation/Z.toml"); 
    EXPECT_TRUE(cube.set_state(st));
}
