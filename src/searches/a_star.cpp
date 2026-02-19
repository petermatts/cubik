#include "cube.hpp"
#include "solver.hpp"
#include <queue>
#include <functional>
#include <chrono>

Solution Solver::solve_a_star(const Cube& start, float heuristic_weight) {
    reset_search_state();

    Solution result{};
    auto t_start = std::chrono::steady_clock::now();

    struct Node {
        Cube cube;
        float g; // cost so far
        float h; // heuristic estimate
        MoveSequence path; // moves to reach this state
    };

    auto cmp = [&](const Node& a, const Node& b) {
        return (a.g + heuristic_weight * a.h) >
               (b.g + heuristic_weight * b.h);
    };

    std::priority_queue<Node, std::vector<Node>, decltype(cmp)> open(cmp);

    // Initial heuristic
    std::vector<Cube> init{start};
    std::vector<float> h_vals(1);
    h_vals = heuristic_->evaluate(init);

    open.push(Node{
        start,
        0.0f,
        h_vals[0],
        {}
    });

    while (!open.empty()) {
        if (nodes_expanded_ >= static_cast<size_t>(config_.node_limit)) {
            break;
        }

        Node current = open.top();
        open.pop();
        ++nodes_expanded_;

        if (current.cube.is_solved()) {
            solution_ = current.path;
            result.solved = true;
            break;
        }

        max_depth_reached_ = std::max(
            max_depth_reached_,
            static_cast<int>(current.path.size())
        );

        StateKey key = state_key(current.cube);

        // Transposition pruning
        if (config_.use_transposition) {
            auto it = transposition_.find(key);
            if (it != transposition_.end() && it->second <= current.g) {
                continue;
            }
            transposition_[key] = current.g;
        }

        // Generate moves
        std::vector<Move> moves;
        generate_moves(current.path, moves);

        // Generate children
        std::vector<Cube> children;
        children.reserve(moves.size());

        for (Move m : moves) {
            children.push_back(current.cube.apply(m));
        }

        // Batch heuristic evaluation
        std::vector<float> child_h_vals(children.size());
        child_h_vals = heuristic_->evaluate(children);

        for (size_t i = 0; i < children.size(); ++i) {
            MoveSequence next_path = current.path;
            next_path.push_back(moves[i]);

            open.push(Node{
                std::move(children[i]),
                current.g + 1.0f,
                child_h_vals[i],
                std::move(next_path)
            });
        }
    }

    auto t_end = std::chrono::steady_clock::now();
    result.nodes_expanded = nodes_expanded_;
    result.max_depth_reached = max_depth_reached_;
    result._solution_moves = solution_;

    result.time_taken = std::chrono::duration<double>(t_end - t_start).count();

    return result;
}
