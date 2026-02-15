#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <memory>
#include "cube.hpp"
#include "solver.hpp"
#include "moves.hpp"

class ZeroHeuristic : public Heuristic {
public:
    std::vector<float> evaluate(const std::vector<Cube>& states) override {
        std::vector<float> out_values(states.size());
        std::fill(out_values.begin(), out_values.end(), 0.0f);
        return out_values;
    }
};

TEST(IDAStarSolver, SolvedCube) {
    Cube cube;  // solved by default
    
    auto heuristic = std::make_shared<ZeroHeuristic>();
    // Solver solver(config, heuristic);
    Solver solver(
        SearchAlgorithm::IDA_STAR, // algorithm
        20,                       // max_depth
        1000,                     // node_limit
        false,                    // use_transposition
        false,                    // verbose
        {
            moves::U, moves::U_prime,
            moves::R, moves::R_prime
        },
        heuristic
    );

    Solution result = solver.solve(cube);

    EXPECT_TRUE(result.solved);
    EXPECT_EQ(result.solution_moves().size(), 0);
    EXPECT_GE(result.nodes_expanded, 1);
}

TEST(IDAStarSolver, OneMoveScramble) {
    Cube cube;
    cube = cube.apply(moves::R);

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(
        SearchAlgorithm::IDA_STAR, // algorithm
        20,                        // max_depth
        1000,                      // node_limit
        false,                     // use_transposition
        false,                     // verbose
        {
            moves::R, moves::R_prime
        },
        heuristic
    );

    Solution result = solver.solve(cube);

    ASSERT_TRUE(result.solved);

    // Robust correctness check
    Cube check = cube;
    for (auto m : result.solution_moves()) {
        check = check.apply(m);
    }
    EXPECT_TRUE(check.is_solved());
}

TEST(IDAStarSolver, NodeLimitStopsSearch) {
    Cube cube;
    cube = cube.apply(moves::R);
    cube = cube.apply(moves::U);

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(
        SearchAlgorithm::IDA_STAR, // algorithm
        20,                        // max_depth
        1,                         // node_limit
        false,                     // use_transposition
        false,                     // verbose
        {
            moves::U, moves::U_prime,
            moves::R, moves::R_prime
        },
        heuristic
    );

    Solution result = solver.solve(cube);

    EXPECT_FALSE(result.solved);
    EXPECT_LE(result.nodes_expanded, 1);
}

TEST(IDAStarSolver, DepthLimitStopsSearch) {
    Cube cube;
    cube = cube.apply(moves::R);
    cube = cube.apply(moves::U);

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(
        SearchAlgorithm::IDA_STAR, // algorithm
        1,                        // max_depth
        1000,                      // node_limit
        false,                     // use_transposition
        false,                     // verbose
        {
            moves::U, moves::U_prime,
            moves::R, moves::R_prime
        },
        heuristic
    );

    Solution result = solver.solve(cube);

    EXPECT_FALSE(result.solved);
}

TEST(AStarSolver, SolvedCube) {
    Cube cube;

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(
        SearchAlgorithm::A_STAR, // algorithm
        20,                        // max_depth
        1000,                      // node_limit
        false,                     // use_transposition
        false,                     // verbose
        {
            moves::U, moves::U_prime,
            moves::R, moves::R_prime
        },
        heuristic
    );

    Solution result = solver.solve(cube);

    EXPECT_TRUE(result.solved);
    EXPECT_TRUE(result.solution_moves().empty());
    EXPECT_GE(result.nodes_expanded, 1u);
}

TEST(AStarSolver, OneMoveScramble) {
    Cube cube;
    cube = cube.apply(moves::R);

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(
        SearchAlgorithm::A_STAR, // algorithm
        20,                        // max_depth
        1000,                      // node_limit
        false,                     // use_transposition
        false,                     // verbose
        {
            moves::U, moves::U_prime,
            moves::R, moves::R_prime
        },
        heuristic
    );

    Solution result = solver.solve(cube);

    ASSERT_TRUE(result.solved);
    ASSERT_EQ(result.solution_moves().size(), 1u);

    Cube check = cube;
    for (auto m : result.solution_moves()) {
        check = check.apply(m);
    }
    EXPECT_TRUE(check.is_solved());
}

TEST(AStarSolver, TwoMoveScramble) {
    Cube cube;
    cube = cube.apply(moves::R);
    cube = cube.apply(moves::U);

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(
        SearchAlgorithm::A_STAR, // algorithm
        20,                        // max_depth
        1000,                      // node_limit
        false,                     // use_transposition
        false,                     // verbose
        {
            moves::U, moves::U_prime,
            moves::R, moves::R_prime
        },
        heuristic
    );

    Solution result = solver.solve(cube);

    ASSERT_TRUE(result.solved);
    ASSERT_EQ(result.solution_moves().size(), 2u);

    Cube check = cube;
    for (auto m : result.solution_moves()) {
        check = check.apply(m);
    }
    EXPECT_TRUE(check.is_solved());
}

TEST(AStarSolver, NodeLimitStopsSearch) {
    Cube cube;
    cube = cube.apply(moves::R);
    cube = cube.apply(moves::U);

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(
        SearchAlgorithm::A_STAR, // algorithm
        20,                        // max_depth
        1,                         // node_limit
        false,                     // use_transposition
        false,                     // verbose
        {
            moves::U, moves::U_prime,
            moves::R, moves::R_prime
        },
        heuristic
    );

    Solution result = solver.solve(cube);

    EXPECT_FALSE(result.solved);
    EXPECT_LE(result.nodes_expanded, 1);
}

TEST(AStarSolver, TranspositionReducesExpansion) {
    Cube cube;
    cube = cube.apply(moves::R);
    cube = cube.apply(moves::U);
    cube = cube.apply(moves::R_prime);
    cube = cube.apply(moves::U_prime);

    auto heuristic = std::make_shared<ZeroHeuristic>();

    Solver solver_tt(
        SearchAlgorithm::A_STAR, // algorithm
        20,                        // max_depth
        1000,                      // node_limit
        true,                      // use_transposition
        false,                     // verbose
        {
            moves::U, moves::U_prime,
            moves::R, moves::R_prime
        },
        heuristic
    );
    Solver solver_no_tt(
        SearchAlgorithm::A_STAR, // algorithm
        20,                        // max_depth
        1000,                      // node_limit
        false,                     // use_transposition
        false,                     // verbose
        {
            moves::U, moves::U_prime,
            moves::R, moves::R_prime
        },
        heuristic
    );

    Solution r1 = solver_tt.solve(cube);
    Solution r2 = solver_no_tt.solve(cube);

    EXPECT_TRUE(r1.solved);
    EXPECT_TRUE(r2.solved);
    EXPECT_LE(r1.nodes_expanded, r2.nodes_expanded);
}
