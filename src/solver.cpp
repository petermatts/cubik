#include <string>
#include "solver.hpp"

Solver::Solver(const SolverConfig& config, Heuristic& heuristic) :
    config_(config),
    heuristic_(heuristic)
{};

SolveResult Solver::solve(const Cube& start) {
    // Solve method implementation
    SolveResult* result = nullptr; // todo Placeholder return
    return *result; // Placeholder return
};

string Solver::toString() const {
    return "Solver instance"; // todo Placeholder implementation
};

