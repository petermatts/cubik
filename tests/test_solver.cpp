#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <memory>
#include "cube.hpp"
#include "solver.hpp"
#include "moves.hpp"

class ZeroHeuristic : public Heuristic {
public:
    void evaluate(
        const std::vector<Cube>& states,
        std::vector<float>& out_values
    ) override {
        out_values.resize(states.size());
        std::fill(out_values.begin(), out_values.end(), 0.0f);
    }
};

TEST(IDAStarSolver, SolvedCube) {
    Cube cube;  // solved by default

    SolverConfig config{
        SearchAlgorithm::IDA_STAR, // algorithm
        20,                        // max_depth
        1000,                      // node_limit
        false,                     // use_transposition
        false,                     // verbose
        {                           // allowed_moves
            moves::U, moves::U_prime,
            moves::R, moves::R_prime
        }
    };

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(config, heuristic);

    Solution result = solver.solve(cube);

    EXPECT_TRUE(result.solved);
    EXPECT_EQ(result.solution_moves.size(), 0);
    EXPECT_GE(result.nodes_expanded, 1);
}

TEST(IDAStarSolver, OneMoveScramble) {
    Cube cube;
    cube = cube.apply(moves::R);

    SolverConfig config{
        SearchAlgorithm::IDA_STAR, // algorithm
        5,                         // max_depth
        100,                       // node_limit
        false,                     // use_transposition
        false,                     // verbose
        {                           // allowed_moves
            moves::R, moves::R_prime
        }
    };

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(config, heuristic);

    Solution result = solver.solve(cube);

    ASSERT_TRUE(result.solved);

    // Robust correctness check
    Cube check = cube;
    for (auto m : result.solution_moves) {
        check = check.apply(m);
    }
    EXPECT_TRUE(check.is_solved());
}

TEST(IDAStarSolver, NodeLimitStopsSearch) {
    Cube cube;
    cube = cube.apply(moves::R);
    cube = cube.apply(moves::U);

    SolverConfig config{
        SearchAlgorithm::IDA_STAR, // algorithm
        20,                        // max_depth
        1,                         // node_limit (intentionally tiny)
        false,                     // use_transposition
        false,                     // verbose
        {                           // allowed_moves
            moves::U, moves::U_prime,
            moves::R, moves::R_prime
        }
    };

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(config, heuristic);

    Solution result = solver.solve(cube);

    EXPECT_FALSE(result.solved);
    EXPECT_LE(result.nodes_expanded, config.node_limit);
}

TEST(IDAStarSolver, DepthLimitStopsSearch) {
    Cube cube;
    cube = cube.apply(moves::R);
    cube = cube.apply(moves::U);

    SolverConfig config{
        SearchAlgorithm::IDA_STAR, // algorithm
        1,                         // max_depth (too shallow)
        1000,                      // node_limit
        false,                     // use_transposition
        false,                     // verbose
        {                           // allowed_moves
            moves::U, moves::U_prime,
            moves::R, moves::R_prime
        }
    };

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(config, heuristic);

    Solution result = solver.solve(cube);

    EXPECT_FALSE(result.solved);
}
