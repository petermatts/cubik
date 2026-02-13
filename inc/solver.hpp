#ifndef CUBIK_SOLVER_HPP
#define CUBIK_SOLVER_HPP

#include <array>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <ostream>
#include <limits>
#include "cube.hpp"

using Move = std::string;
using MoveSequence = std::vector<Move>;

namespace SearchAlgorithm {
    constexpr const char *IDA_STAR = "IDA_STAR";
    constexpr const char *A_STAR = "A_STAR";
    constexpr const char *WEIGHTED_A_STAR = "WEIGHTED_A_STAR";
}

struct _SolverConfig {
    std::string algorithm;
    int max_depth;
    double node_limit;
    double heuristic_weight;   // for WA*
    bool use_transposition;
    bool verbose;
    MoveSequence allowed_moves;
};

struct Solution {
    bool solved = false;
    int nodes_expanded = 0;
    int max_depth_reached = 0;
    double time_taken = 0.0;    // seconds
    MoveSequence solution_moves;
};

/**
 * @brief Heuristic interface (Python-overridable via SWIG directors)
 *
 * Implementations must fill out_values with exactly states.size() values.
 */
class Heuristic {
public:
    virtual ~Heuristic() = default;

    virtual std::vector<float> evaluate(
        const std::vector<Cube>& states
    ) = 0;
};

class Solver {
public:
    // /**
    //  * @brief Construct a solver with a configuration and heuristic.
    //  *
    //  * @param config Solver configuration
    //  * @param heuristic Heuristic implementation (shared ownership)
    //  */
    // Solver(const SolverConfig& config, std::shared_ptr<Heuristic> heuristic);

    /**
     * @brief Construct a new Solver object
     * 
     * @param algorithm 
     * @param max_depth 
     * @param node_limit 
     * @param use_transposition 
     * @param verbose 
     * @param allowed_moves 
     * @param heuristic 
     * @param heuristic_weight 
     */
    Solver(
        std::string algorithm,
        int max_depth,
        double node_limit,
        bool use_transposition,
        bool verbose,
        MoveSequence allowed_moves,
        Heuristic* heuristic,
        double heuristic_weight = 1.0
    );

    virtual ~Solver() = default;

    /**
     * @brief Solve from a starting cube state.
     *
     * @param start[in] Cube to attempt tosolve
     * @return Solution
     */
    Solution solve(const Cube& start);

    std::string toString() const;
    std::string __str__() const { return toString(); }

    friend std::ostream& operator<<(std::ostream& os, const Solver& obj) {
        os << obj.toString();
        return os;
    }

private:
    /* Internal Types & Aliases */

    // Exact, collision-free state key
    using StateKey = std::array<uint32_t, 6>;

    struct StateKeyHash {
        std::size_t operator()(const StateKey& k) const noexcept {
            std::size_t h = 0;
            for (uint32_t v : k) {
                // Standard hash-combine pattern
                h ^= static_cast<std::size_t>(v)
                     + 0x9e3779b97f4a7c15ULL
                     + (h << 6)
                     + (h >> 2);
            }
            return h;
        }
    };

    using TranspositionTable = std::unordered_map<StateKey, float, StateKeyHash>;

    /* Solver Configuration */
    _SolverConfig config_;
    std::shared_ptr<Heuristic> heuristic_;

    /* Search State */
    size_t nodes_expanded_;
    int max_depth_reached_;
    MoveSequence solution_;
    TranspositionTable transposition_;

    /* Algorithm Entry Points  */
    Solution solve_ida_star(const Cube& start);
    Solution solve_a_star(const Cube& start);
    Solution solve_weighted_a_star(const Cube& start);
    // Solution solve_puct(const Cube& start);

    /* IDA* Internals */
    float ida_star_dfs(
        Cube& node,
        float g,
        float threshold,
        int depth,
        MoveSequence& path,
        std::unordered_set<StateKey, StateKeyHash>& path_visited
    );

    /* A* / WA* Internals */
    Solution a_star_search(const Cube& start, float heuristic_weight);

    /* PUCT / MCTS Internals */
    void puct_simulate(const Cube& root, int simulations);

    /* Helpers */
    void generate_moves(const std::vector<Move>& history, std::vector<Move>& out_moves) const;
    bool is_redundant(const MoveSequence& history, Move next_move) const;
    StateKey state_key(const Cube& cube) const {
        const auto state = cube.get_state();  // expected size == 6
        return StateKey{
            state[0], state[1], state[2],
            state[3], state[4], state[5]
        };
    }

    void reset_search_state() {
        solution_.clear();
        transposition_.clear();
        nodes_expanded_ = 0;
    }
};

#endif // CUBIK_SOLVER_HPP
