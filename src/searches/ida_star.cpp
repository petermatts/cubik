#include <chrono>
#include <limits>
#include "cube.hpp"
#include "solver.hpp"

Solution Solver::solve_ida_star(const Cube& start) {
    reset_search_state();

    Solution result{};
    // auto t_start = std::chrono::steady_clock::now();

    // Initial heuristic
    std::vector<Cube> init_states{start};
    std::vector<float> h_vals(1);
    heuristic_->evaluate(init_states, h_vals);

    float threshold = h_vals[0];

    MoveSequence path;
    std::unordered_set<StateKey, StateKeyHash> path_visited;

    while (true) {
        Cube root = start;
        path.clear();
        path_visited.clear();
        path_visited.insert(state_key(root));

        solution_.clear();

        if (config_.verbose) {
            std::cout << "[IDA*] Starting iteration with threshold = " << threshold << std::endl;
        }

        std::vector<Cube> root_state{root};
        std::vector<float> root_h(1);
        heuristic_->evaluate(root_state, root_h);

        float f_root = root_h[0];
        if (f_root > threshold) {
            threshold = f_root;
        }

        float t = ida_star_dfs(
            root,
            /* g = */ 0.0f,
            threshold,
            /* depth = */ 0,
            path,
            path_visited
        );

        if (t == FOUND) {
            if (config_.verbose) {
                std::cout << "[IDA*] Solution found at depth "
                        << solution_.size()
                        << " after expanding "
                        << nodes_expanded_
                        << " nodes." << std::endl;
            }
            result.solved = true;
            result.solution_moves = solution_;
            break;
        }

        if (nodes_expanded_ >= static_cast<size_t>(config_.node_limit)) {
            if (config_.verbose) {
                std::cout << "[IDA*] Node limit reached. Aborting search."
                        << std::endl;
            }
            break;
        }


        threshold = t;
        if (config_.verbose) {
            std::cout << "[IDA*] Increasing threshold to "
                    << threshold << std::endl;
        }
    }

    // auto t_end = std::chrono::steady_clock::now();
    result.nodes_expanded = static_cast<int>(nodes_expanded_);
    result.max_depth_reached = max_depth_reached_;


    // result.time_taken =
    //     std::chrono::duration<double>(t_end - t_start).count();

    return result;
}

float Solver::ida_star_dfs(
    Cube& node,
    float g,
    float threshold,
    int depth,
    MoveSequence& path,
    std::unordered_set<StateKey, StateKeyHash>& path_visited
) {
    if (nodes_expanded_ >= static_cast<size_t>(config_.node_limit)) {
        return INF;
    }

    // Node expansion bookkeeping
    ++nodes_expanded_;

    if (node.is_solved()) {
        solution_ = path;
        return FOUND;
    }

    if (depth >= config_.max_depth) {
        return INF;
    }

    // Generate legal moves
    std::vector<Move> moves;
    generate_moves(path, moves);

    // Generate children
    std::vector<Cube> children;
    children.reserve(moves.size());

    for (Move m : moves) {
        Cube next = node.apply(m);
        children.push_back(std::move(next));
    }

    // Batch heuristic evaluation
    std::vector<float> h_vals(children.size());
    heuristic_->evaluate(children, h_vals);

    float min_excess = INF;

    for (size_t i = 0; i < children.size(); ++i) {
        float f = g + 1.0f + h_vals[i];

        if (f > threshold) {
            min_excess = std::min(min_excess, f);
            continue;
        }

        StateKey key = state_key(children[i]);
        if (path_visited.count(key)) {
            continue;
        }

        path.push_back(moves[i]);
        path_visited.insert(key);

        float t = ida_star_dfs(
            children[i],
            g + 1.0f,
            threshold,
            depth + 1,
            path,
            path_visited
        );

        if (t == FOUND) {
            return FOUND;
        }

        path.pop_back();
        path_visited.erase(key);

        min_excess = std::min(min_excess, t);
    }

    max_depth_reached_ = std::max(max_depth_reached_, depth);

    return min_excess;
}
