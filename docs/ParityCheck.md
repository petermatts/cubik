# Methodology for checking cube parity

## General function
```c++
bool Cube::is_valid_state() const {
    // 1. Check Corner Orientation (mod 3)
    int corner_orientation_sum = 0;
    // Assuming get_state() gives the state in a specific order
    // e.g. [up, front, left, right, back, down] and each face is represented by a uint32_t
    // You should extract corner orientations from the state vector.
    // This depends on how your cube is implemented and how the color positions map to corners.
    // For simplicity, let's assume we have a function get_corner_orientation() which extracts
    // corner orientations from the state array.
    
    for (int i = 0; i < 8; ++i) {
        corner_orientation_sum += get_corner_orientation(i);  // Get orientation of corner i
    }
    
    // Corner orientations must sum to 0 mod 3
    if (corner_orientation_sum % 3 != 0) {
        return false;
    }

    // 2. Check Edge Orientation (mod 2)
    int edge_orientation_sum = 0;
    for (int i = 0; i < 12; ++i) {
        edge_orientation_sum += get_edge_orientation(i);  // Get orientation of edge i
    }

    // Edge orientations must sum to 0 mod 2
    if (edge_orientation_sum % 2 != 0) {
        return false;
    }

    // 3. Check Permutation Parity (even permutation)
    // A valid cube has an even permutation parity (both corner and edge pieces).
    if (!check_permutation_parity()) {
        return false;
    }

    // 4. Check for Duplicate Pieces and Stickers
    if (!check_unique_pieces()) {
        return false;
    }

    // If all checks pass, the cube is in a valid state.
    return true;
}
```

## Helper functions

```c++
int Cube::get_corner_orientation(int corner_index) const {
    // For example, if corner_index is 0 (top-left-front corner), we check its orientation
    // relative to the solved cube. In the solved state, all corners are oriented "correctly".
    
    // Access corner piece's stickers and calculate the orientation.
    // We will need to access the 3 adjacent faces of each corner.
    
    // Here's a rough idea for accessing corner orientation:
    // Let's assume we have corner faces: up, front, left
    
    int orientation = 0;  // Orientation: 0 for solved, 1 for 120 degrees, 2 for 240 degrees
    
    // Example: If corner is on the "top-left-front" position, check the stickers of each adjacent face:
    if (get(this->up, TOP_LEFT) == WHITE) {
        if (get(this->front, BOTTOM_LEFT) == GREEN && get(this->left, BOTTOM_RIGHT) == ORANGE) {
            orientation = 0;  // Solved orientation (just an example; you'd need a full check)
        }
    }
    
    return orientation; // Return corner orientation: 0, 1, or 2 (mod 3)
}


int Cube::get_edge_orientation(int edge_index) const {
    // For example, if edge_index is 0 (top-front edge), check its orientation relative to the solved state.
    
    int orientation = 0;  // Orientation: 0 for solved, 1 for 180-degree rotation
    
    // Example: Check edge orientation between front and up faces:
    if (get(this->front, TOP_MIDDLE) == GREEN) {
        if (get(this->up, BOTTOM_MIDDLE) == WHITE) {
            orientation = 0;  // Solved orientation
        } else if (get(this->up, BOTTOM_MIDDLE) == YELLOW) {
            orientation = 1;  // 180-degree rotation
        }
    }
    
    return orientation; // Return edge orientation: 0 or 1
}


bool Cube::check_permutation_parity() const {
    // Calculate corner parity
    int corner_parity = 0;
    for (int i = 0; i < 7; ++i) {  // Loop through 8 corners
        for (int j = i + 1; j < 8; ++j) {
            if (/* compare the positions of corners i and j */) {
                ++corner_parity;
            }
        }
    }

    // Calculate edge parity
    int edge_parity = 0;
    for (int i = 0; i < 11; ++i) {  // Loop through 12 edges
        for (int j = i + 1; j < 12; ++j) {
            if (/* compare the positions of edges i and j */) {
                ++edge_parity;
            }
        }
    }

    // The total number of swaps (corner_parity + edge_parity) should be even for a solvable state.
    return ((corner_parity + edge_parity) % 2 == 0);
}

bool Cube::check_unique_pieces() const {
    // This function checks that there are no duplicates or missing pieces.
    
    // Check corners:
    vector<int> corner_positions;  // Store positions of all corner pieces
    for (int i = 0; i < 8; ++i) {
        corner_positions.push_back(get_corner_position(i));
    }

    // Check for duplicates in corner positions
    std::sort(corner_positions.begin(), corner_positions.end());
    if (std::adjacent_find(corner_positions.begin(), corner_positions.end()) != corner_positions.end()) {
        return false;  // Found duplicate corner piece
    }

    // Check edges:
    vector<int> edge_positions;  // Store positions of all edge pieces
    for (int i = 0; i < 12; ++i) {
        edge_positions.push_back(get_edge_position(i));
    }

    // Check for duplicates in edge positions
    std::sort(edge_positions.begin(), edge_positions.end());
    if (std::adjacent_find(edge_positions.begin(), edge_positions.end()) != edge_positions.end()) {
        return false;  // Found duplicate edge piece
    }

    return true;  // No duplicates, all pieces are unique
}

```
