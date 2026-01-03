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
    /**
     * @brief Solver constructor.
     * 
     * @param config[in] Solver configuration
     * @param heuristic[in] Heuristic to use. Must be a Cubik.Heuristic subclass.
     * @return * Solver 
     */
    Solver(const SolverConfig& config, Heuristic& heuristic);

    /**
     * @brief Search for a soltion from the starting cube state and the solver configuration.
     * 
     * @param start[in] Starting cube state
     * @return SolveResult 
     */
    SolveResult solve(const Cube& start);

    string toString() const;
    string __str__() const { return toString(); }

// private:
//     SolverConfig config_;
//     Heuristic& heuristic_;
};

