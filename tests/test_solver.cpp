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

    SolverConfig config{};
    config.algorithm = SearchAlgorithm::IDA_STAR; // algorithm
    config.max_depth = 20;                        // max_depth
    config.node_limit = 1000;                     // node_limit
    config.use_transposition = false;             // use_transposition
    config.verbose = false;                       // verbose
    config.allowed_moves = {                      // allowed_moves
        moves::U, moves::U_prime,
        moves::R, moves::R_prime
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

    SolverConfig config{};
    config.algorithm = SearchAlgorithm::IDA_STAR; // algorithm
    config.max_depth = 5;                         // max_depth
    config.node_limit = 100;                      // node_limit
    config.use_transposition = false;             // use_transposition
    config.verbose = false;                       // verbose
    config.allowed_moves = {                      // allowed_moves
        moves::R, moves::R_prime
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

    SolverConfig config{};
    config.algorithm = SearchAlgorithm::IDA_STAR; // algorithm
    config.max_depth = 20;                        // max_depth
    config.node_limit = 1;                        // node_limit (intentionally tiny)
    config.use_transposition = false;             // use_transposition
    config.verbose = false;                       // verbose
    config.allowed_moves = {                      // allowed_moves
        moves::U, moves::U_prime,
        moves::R, moves::R_prime
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

    SolverConfig config{};
    config.algorithm = SearchAlgorithm::IDA_STAR; // algorithm
    config.max_depth = 1;                         // max_depth (too shallow)
    config.node_limit = 1000;                     // node_limit
    config.use_transposition = false;             // use_transposition
    config.verbose = false;                       // verbose
    config.allowed_moves = {                      // allowed_moves
        moves::U, moves::U_prime,
        moves::R, moves::R_prime
    };

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(config, heuristic);

    Solution result = solver.solve(cube);

    EXPECT_FALSE(result.solved);
}

TEST(AStarSolver, SolvedCube) {
    Cube cube;

    SolverConfig config{};
    config.algorithm = SearchAlgorithm::A_STAR;
    config.node_limit = 1000;
    config.use_transposition = true;
    config.verbose = false;
    config.allowed_moves = {
        moves::U, moves::U_prime,
        moves::R, moves::R_prime
    };

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(config, heuristic);

    Solution result = solver.solve(cube);

    EXPECT_TRUE(result.solved);
    EXPECT_TRUE(result.solution_moves.empty());
    EXPECT_GE(result.nodes_expanded, 1u);
}

TEST(AStarSolver, OneMoveScramble) {
    Cube cube;
    cube = cube.apply(moves::R);

    SolverConfig config{};
    config.algorithm = SearchAlgorithm::A_STAR;
    config.node_limit = 100;
    config.use_transposition = true;
    config.verbose = false;
    config.allowed_moves = {
        moves::R, moves::R_prime
    };

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(config, heuristic);

    Solution result = solver.solve(cube);

    ASSERT_TRUE(result.solved);
    ASSERT_EQ(result.solution_moves.size(), 1u);

    Cube check = cube;
    for (auto m : result.solution_moves) {
        check = check.apply(m);
    }
    EXPECT_TRUE(check.is_solved());
}

TEST(AStarSolver, TwoMoveScramble) {
    Cube cube;
    cube = cube.apply(moves::R);
    cube = cube.apply(moves::U);

    SolverConfig config{};
    config.algorithm = SearchAlgorithm::A_STAR;
    config.node_limit = 1000;
    config.use_transposition = true;
    config.verbose = false;
    config.allowed_moves = {
        moves::U, moves::U_prime,
        moves::R, moves::R_prime
    };

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(config, heuristic);

    Solution result = solver.solve(cube);

    ASSERT_TRUE(result.solved);
    ASSERT_EQ(result.solution_moves.size(), 2u);

    Cube check = cube;
    for (auto m : result.solution_moves) {
        check = check.apply(m);
    }
    EXPECT_TRUE(check.is_solved());
}

TEST(AStarSolver, NodeLimitStopsSearch) {
    Cube cube;
    cube = cube.apply(moves::R);
    cube = cube.apply(moves::U);

    SolverConfig config{};
    config.algorithm = SearchAlgorithm::A_STAR;
    config.node_limit = 1;  // intentionally tiny
    config.use_transposition = true;
    config.verbose = false;
    config.allowed_moves = {
        moves::U, moves::U_prime,
        moves::R, moves::R_prime
    };

    auto heuristic = std::make_shared<ZeroHeuristic>();
    Solver solver(config, heuristic);

    Solution result = solver.solve(cube);

    EXPECT_FALSE(result.solved);
    EXPECT_LE(result.nodes_expanded, config.node_limit);
}

TEST(AStarSolver, TranspositionReducesExpansion) {
    Cube cube;
    cube = cube.apply(moves::R);
    cube = cube.apply(moves::U);
    cube = cube.apply(moves::R_prime);
    cube = cube.apply(moves::U_prime);

    SolverConfig with_tt{};
    with_tt.algorithm = SearchAlgorithm::A_STAR;
    with_tt.node_limit = 1000;
    with_tt.use_transposition = true;
    with_tt.verbose = false;
    with_tt.allowed_moves = {
        moves::U, moves::U_prime,
        moves::R, moves::R_prime
    };

    SolverConfig without_tt = with_tt;
    without_tt.use_transposition = false;

    auto heuristic = std::make_shared<ZeroHeuristic>();

    Solver solver_tt(with_tt, heuristic);
    Solver solver_no_tt(without_tt, heuristic);

    Solution r1 = solver_tt.solve(cube);
    Solution r2 = solver_no_tt.solve(cube);

    EXPECT_TRUE(r1.solved);
    EXPECT_TRUE(r2.solved);
    EXPECT_LE(r1.nodes_expanded, r2.nodes_expanded);
}
