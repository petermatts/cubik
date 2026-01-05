#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
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
        .algorithm = SearchAlgorithm::IDA_STAR,
        .max_depth = 20,
        .node_limit = 1000,
        .use_transposition = false,
        .verbose = false,
        .allowed_moves = {
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
        .algorithm = SearchAlgorithm::IDA_STAR,
        .max_depth = 5,
        .node_limit = 100,
        .use_transposition = false,
        .verbose = false,
        .allowed_moves = {
            moves::R, moves::R_prime
        }
    };

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(config, heuristic);

    Solution result = solver.solve(cube);

    ASSERT_TRUE(result.solved);
    // ASSERT_EQ(result.solution_moves.size(), 1);

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
        .algorithm = SearchAlgorithm::IDA_STAR,
        .max_depth = 20,
        .node_limit = 1,   // Must be below theoretical minimum
        .use_transposition = false,
        .verbose = false,
        .allowed_moves = {
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
        .algorithm = SearchAlgorithm::IDA_STAR,
        .max_depth = 1,  // too shallow
        .node_limit = 1000,
        .use_transposition = false,
        .verbose = false,
        .allowed_moves = {
            moves::U, moves::U_prime,
            moves::R, moves::R_prime
        }
    };

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(config, heuristic);

    Solution result = solver.solve(cube);

    EXPECT_FALSE(result.solved);
}
