#include "gtest/gtest.h"
#include <iostream>
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
    EXPECT_FALSE(cube.set_state(st));
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
    EXPECT_FALSE(cube.set_state(st));
}
