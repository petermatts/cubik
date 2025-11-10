#include "cube.hpp"

Cube Cube::B() const {
    uint8_t temp = 0;
    Cube newCube = *this;
    
    // corner
    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    temp = get(newCube.up, TOP_RIGHT);
    set(newCube.up, TOP_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, temp);

    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, TOP_MIDDLE);
    set(newCube.up, TOP_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, get(newCube.down, BOTTOM_MIDDLE));
    set(newCube.down, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, temp);

    return newCube;
}

Cube Cube::B_prime() const {
    uint8_t temp = 0;
    Cube newCube = *this;
    
    // corner
    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.up, TOP_RIGHT);
    set(newCube.up, TOP_RIGHT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    // edge
    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    temp = get(newCube.up, TOP_MIDDLE);
    set(newCube.up, TOP_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, get(newCube.down, BOTTOM_MIDDLE));
    set(newCube.down, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    return newCube;
}

Cube Cube::B2() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, TOP_RIGHT);
    set(newCube.back, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, temp);

    temp = get(newCube.up, TOP_RIGHT);
    set(newCube.up, TOP_RIGHT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, temp);

    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, BOTTOM_LEFT);
    set(newCube.left, BOTTOM_LEFT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    // edges
    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.back, MIDDLE_LEFT);
    set(newCube.back, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, TOP_MIDDLE);
    set(newCube.up, TOP_MIDDLE, get(newCube.down, BOTTOM_MIDDLE));
    set(newCube.down, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, MIDDLE_LEFT);
    set(newCube.left, MIDDLE_LEFT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    return newCube;
}

Cube Cube::b() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    temp = get(newCube.up, TOP_RIGHT);
    set(newCube.up, TOP_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, temp);

    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, TOP_MIDDLE);
    set(newCube.up, TOP_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, get(newCube.down, BOTTOM_MIDDLE));
    set(newCube.down, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, temp);

    temp = get(newCube.up, MIDDLE_LEFT);
    set(newCube.up, MIDDLE_LEFT, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, get(newCube.down, MIDDLE_RIGHT));
    set(newCube.down, MIDDLE_RIGHT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, temp);

    temp = get(newCube.up, MIDDLE_RIGHT);
    set(newCube.up, MIDDLE_RIGHT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.down, MIDDLE_LEFT));
    set(newCube.down, MIDDLE_LEFT, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.up, CENTER);
    set(newCube.up, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, get(newCube.down, CENTER));
    set(newCube.down, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, temp);

    return newCube;
}

Cube Cube::b_prime() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.up, TOP_RIGHT);
    set(newCube.up, TOP_RIGHT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    // edge
    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    temp = get(newCube.up, TOP_MIDDLE);
    set(newCube.up, TOP_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, get(newCube.down, BOTTOM_MIDDLE));
    set(newCube.down, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, MIDDLE_LEFT);
    set(newCube.up, MIDDLE_LEFT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.down, MIDDLE_RIGHT));
    set(newCube.down, MIDDLE_RIGHT, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    temp = get(newCube.up, MIDDLE_RIGHT);
    set(newCube.up, MIDDLE_RIGHT, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, get(newCube.down, MIDDLE_LEFT));
    set(newCube.down, MIDDLE_LEFT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    // centers
    temp = get(newCube.up, CENTER);
    set(newCube.up, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, get(newCube.down, CENTER));
    set(newCube.down, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::b2() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, TOP_RIGHT);
    set(newCube.back, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, temp);

    temp = get(newCube.up, TOP_RIGHT);
    set(newCube.up, TOP_RIGHT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, temp);

    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, BOTTOM_LEFT);
    set(newCube.left, BOTTOM_LEFT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    // edges
    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.back, MIDDLE_LEFT);
    set(newCube.back, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, TOP_MIDDLE);
    set(newCube.up, TOP_MIDDLE, get(newCube.down, BOTTOM_MIDDLE));
    set(newCube.down, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, MIDDLE_LEFT);
    set(newCube.left, MIDDLE_LEFT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, MIDDLE_LEFT);
    set(newCube.up, MIDDLE_LEFT, get(newCube.down, MIDDLE_RIGHT));
    set(newCube.down, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, MIDDLE_RIGHT);
    set(newCube.up, MIDDLE_RIGHT, get(newCube.down, MIDDLE_LEFT));
    set(newCube.down, MIDDLE_LEFT, temp);

    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, BOTTOM_MIDDLE);
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.up, CENTER);
    set(newCube.up, CENTER, get(newCube.down, CENTER));
    set(newCube.down, CENTER, temp);

    temp = get(newCube.left, CENTER);
    set(newCube.left, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}
