#include <vector>
#include <string>
#include "cube.hpp"

enum class SearchAlgorithm {
    IDA_STAR,
    A_STAR,
    WEIGHTED_A_STAR,
    PUCT,
};


struct SolverConfig {
    SearchAlgorithm algorithm;
    int max_depth;
    int node_limit;
    float heuristic_weight;   // for WA*
    bool use_transposition;
    bool verbose;
};

struct SolveResult {
    bool solved;
    int nodes_expanded;
    int max_depth_reached;
    double time_taken;  // in seconds
    std::vector<std::string> solution_moves;
};

class Heuristic {
public:
    virtual ~Heuristic() = default;

    // Evaluate a batch of states
    virtual void evaluate(
        const std::vector<Cube>& states,
        std::vector<float>& out_values
    ) = 0;
};

class Solver {
public:
    Solver(const SolverConfig& config, Heuristic& heuristic);

    SolveResult solve(const Cube& start);
};

