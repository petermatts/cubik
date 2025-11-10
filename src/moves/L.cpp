#include "cube.hpp"

Cube Cube::L() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, temp);

    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, get(newCube.down, TOP_LEFT));
    set(newCube.down, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, temp);

    temp = get(newCube.up, BOTTOM_LEFT);
    set(newCube.up, BOTTOM_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, MIDDLE_LEFT);
    set(newCube.up, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.down, MIDDLE_LEFT));
    set(newCube.down, MIDDLE_LEFT, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, temp);

    return newCube;
}

Cube Cube::L_prime() const {
    uint8_t temp = 0;
    Cube newCube = *this;
    
    // corner
    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, get(newCube.down, TOP_LEFT));
    set(newCube.down, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.up, BOTTOM_LEFT);
    set(newCube.up, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    // edge
    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, temp);

    temp = get(newCube.up, MIDDLE_LEFT);
    set(newCube.up, MIDDLE_LEFT, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, get(newCube.down, MIDDLE_LEFT));
    set(newCube.down, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    return newCube;
}

Cube Cube::L2() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, TOP_RIGHT);
    set(newCube.left, TOP_RIGHT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.down, TOP_LEFT));
    set(newCube.down, TOP_LEFT, temp);

    temp = get(newCube.up, BOTTOM_LEFT);
    set(newCube.up, BOTTOM_LEFT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, temp);

    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.front, BOTTOM_LEFT);
    set(newCube.front, BOTTOM_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    // edges
    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, MIDDLE_LEFT);
    set(newCube.left, MIDDLE_LEFT, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, MIDDLE_LEFT);
    set(newCube.up, MIDDLE_LEFT, get(newCube.down, MIDDLE_LEFT));
    set(newCube.down, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    return newCube;
}

Cube Cube::l() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, temp);

    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, get(newCube.down, TOP_LEFT));
    set(newCube.down, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, temp);

    temp = get(newCube.up, BOTTOM_LEFT);
    set(newCube.up, BOTTOM_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, MIDDLE_LEFT);
    set(newCube.up, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.down, MIDDLE_LEFT));
    set(newCube.down, MIDDLE_LEFT, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, temp);

    temp = get(newCube.up, TOP_MIDDLE);
    set(newCube.up, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.down, TOP_MIDDLE));
    set(newCube.down, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, temp);

    temp = get(newCube.up, BOTTOM_MIDDLE);
    set(newCube.up, BOTTOM_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, get(newCube.down, BOTTOM_MIDDLE));
    set(newCube.down, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, temp);

    // centers
    temp = get(newCube.up, CENTER);
    set(newCube.up, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, get(newCube.down, CENTER));
    set(newCube.down, CENTER, get(newCube.front, CENTER));
    set(newCube.front, CENTER, temp);

    return newCube;
}

Cube Cube::l_prime() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, get(newCube.down, TOP_LEFT));
    set(newCube.down, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.up, BOTTOM_LEFT);
    set(newCube.up, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    // edge
    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, temp);

    temp = get(newCube.up, MIDDLE_LEFT);
    set(newCube.up, MIDDLE_LEFT, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, get(newCube.down, MIDDLE_LEFT));
    set(newCube.down, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, TOP_MIDDLE);
    set(newCube.up, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, get(newCube.down, TOP_MIDDLE));
    set(newCube.down, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.up, BOTTOM_MIDDLE);
    set(newCube.up, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.down, BOTTOM_MIDDLE));
    set(newCube.down, BOTTOM_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.up, CENTER);
    set(newCube.up, CENTER, get(newCube.front, CENTER));
    set(newCube.front, CENTER, get(newCube.down, CENTER));
    set(newCube.down, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, temp);

    return newCube;
}

Cube Cube::l2() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, TOP_RIGHT);
    set(newCube.left, TOP_RIGHT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.down, TOP_LEFT));
    set(newCube.down, TOP_LEFT, temp);

    temp = get(newCube.up, BOTTOM_LEFT);
    set(newCube.up, BOTTOM_LEFT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, temp);

    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.front, BOTTOM_LEFT);
    set(newCube.front, BOTTOM_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    // edges
    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, MIDDLE_LEFT);
    set(newCube.left, MIDDLE_LEFT, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, MIDDLE_LEFT);
    set(newCube.up, MIDDLE_LEFT, get(newCube.down, MIDDLE_LEFT));
    set(newCube.down, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, TOP_MIDDLE);
    set(newCube.up, TOP_MIDDLE, get(newCube.down, TOP_MIDDLE));
    set(newCube.down, TOP_MIDDLE, temp);

    temp = get(newCube.up, BOTTOM_MIDDLE);
    set(newCube.up, BOTTOM_MIDDLE, get(newCube.down, BOTTOM_MIDDLE));
    set(newCube.down, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, BOTTOM_MIDDLE);
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.up, CENTER);
    set(newCube.up, CENTER, get(newCube.down, CENTER));
    set(newCube.down, CENTER, temp);

    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, temp);

    return newCube;
}
