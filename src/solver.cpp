#include <string>
#include <memory>
#include "cube.hpp"
#include "solver.hpp"
#include <cstring>

struct SearchStats {
    int nodes_expanded = 0;
    int max_depth = 0;
};

struct Node {
    Cube cube;
    float g;   // cost so far
    float h;   // heuristic
};

// Solver::Solver(const SolverConfig& config, std::shared_ptr<Heuristic> heuristic) :
//     config_(config),
//     heuristic_(heuristic)
// { /* todo verify config */ };

Solver::Solver(
    std::string algorithm,
    int max_depth,
    double node_limit,
    bool use_transposition,
    bool verbose,
    MoveSequence allowed_moves,
    std::shared_ptr<Heuristic> heuristic,
    double heuristic_weight
) : config_{
        algorithm,
        max_depth,
        node_limit,
        heuristic_weight,
        use_transposition,
        verbose,
        allowed_moves
    },
    heuristic_(heuristic)
{ /* todo verify config */ }

Solution Solver::solve(const Cube& start) {
    // Solve method implementation
    Solution result;

    if (config_.algorithm == SearchAlgorithm::IDA_STAR) {
        result = solve_ida_star(start);
    } else if (config_.algorithm == SearchAlgorithm::A_STAR) {
        result = solve_a_star(start);
    } else if (config_.algorithm == SearchAlgorithm::WEIGHTED_A_STAR) {
        result = solve_weighted_a_star(start);
    } // else if (config_.algorithm == SearchAlgorithm::PUCT) {
    //     result = solve_puct(start);
    // }

    return result;
};

std::string Solver::toString() const {
    return "Solver instance"; // todo Placeholder implementation
    // Detailed string representation (include config details)
};

// Map a move to its logical face for redundancy checks
inline char move_face(Move move) {
    switch (move[0]) {
        case 'U': case 'D': case 'L': case 'R':
        case 'F': case 'B': case 'M': case 'E': case 'S':
        case 'u': case 'd': case 'l': case 'r': case 'f': case 'b':
            return move[0]; // wide moves treated separately
        default:
            return '?'; // unknown moves and rotations like X/Y/Z ignored for now
    }
}

// Check if next_move is redundant given the history and allowed moves
bool Solver::is_redundant(const MoveSequence& history, Move next_move) const {
    if (history.empty()) return false;

    char next_face = move_face(next_move);
    Move last_move = history.back();
    char last_face = move_face(last_move);

    // Exact repetition of same move is always redundant
    if (last_move == next_move) return true;

    // Consecutive moves on the same face
    if (next_face == last_face) {
        // Check if allowed moves include an alternative on this face (inverse or 2-turn)
        bool has_alternative = false;
        for (auto m : config_.allowed_moves) {
            if (move_face(m) == next_face && (m != last_move)) {
                has_alternative = true;
                break;
            }
        }

        if (has_alternative) {
            // There is an alternative (R' or R2) -> current repetition is redundant
            return false; // inverses/half-turns allowed
        } else {
            // No alternatives allowed -> consecutive moves needed to reach solution
            return false;
        }
    }

    // Prevent three consecutive same-face moves if allowed
    if (history.size() >= 2) {
        char second_last_face = move_face(history[history.size() - 2]);
        if (second_last_face == next_face && last_face == next_face) {
            return true; // blocks trivial "R R R"
        }
    }

    // Otherwise, move is safe
    return false;
}

// Generate legal moves considering move history and redundancy
void Solver::generate_moves(const MoveSequence& history, std::vector<Move>& out_moves) const {
    out_moves.clear();
    for (Move m : config_.allowed_moves) {
        if (!is_redundant(history, m)) {
            out_moves.push_back(m);
        }
    }

    if (config_.verbose) {
        std::cout << "[DEBUG] Moves generated:";
        for (auto m : out_moves) std::cout << " " << m;
        std::cout << std::endl;
    }
}
