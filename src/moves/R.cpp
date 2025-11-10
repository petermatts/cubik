#include "cube.hpp"

Cube Cube::R() const {
    uint8_t temp = 0;
    Cube newCube = *this;
    
    // corner
    temp = get(newCube.right, TOP_LEFT);
    set(newCube.right, TOP_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    temp = get(newCube.up, TOP_RIGHT);
    set(newCube.up, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.down, TOP_RIGHT));
    set(newCube.down, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.up, BOTTOM_RIGHT);
    set(newCube.up, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, temp);

    // edge
    temp = get(newCube.right, TOP_MIDDLE);
    set(newCube.right, TOP_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, MIDDLE_RIGHT);
    set(newCube.up, MIDDLE_RIGHT, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, get(newCube.down, MIDDLE_RIGHT));
    set(newCube.down, MIDDLE_RIGHT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    return newCube;
}

Cube Cube::R_prime() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.right, TOP_LEFT);
    set(newCube.right, TOP_LEFT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.up, TOP_RIGHT);
    set(newCube.up, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, get(newCube.down, TOP_RIGHT));
    set(newCube.down, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, temp);

    temp = get(newCube.up, BOTTOM_RIGHT);
    set(newCube.up, BOTTOM_RIGHT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, temp);

    // edge
    temp = get(newCube.right, TOP_MIDDLE);
    set(newCube.right, TOP_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.up, MIDDLE_RIGHT);
    set(newCube.up, MIDDLE_RIGHT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.down, MIDDLE_RIGHT));
    set(newCube.down, MIDDLE_RIGHT, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, temp);

    return newCube;
}

Cube Cube::R2() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.right, TOP_LEFT);
    set(newCube.right, TOP_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.right, TOP_RIGHT);
    set(newCube.right, TOP_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.up, TOP_RIGHT);
    set(newCube.up, TOP_RIGHT, get(newCube.down, TOP_RIGHT));
    set(newCube.down, TOP_RIGHT, temp);

    temp = get(newCube.up, BOTTOM_RIGHT);
    set(newCube.up, BOTTOM_RIGHT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, temp);

    temp = get(newCube.front, TOP_RIGHT);
    set(newCube.front, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.front, BOTTOM_RIGHT);
    set(newCube.front, BOTTOM_RIGHT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, temp);

    // edges
    temp = get(newCube.right, TOP_MIDDLE);
    set(newCube.right, TOP_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.right, MIDDLE_LEFT);
    set(newCube.right, MIDDLE_LEFT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, MIDDLE_RIGHT);
    set(newCube.up, MIDDLE_RIGHT, get(newCube.down, MIDDLE_RIGHT));
    set(newCube.down, MIDDLE_RIGHT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    return newCube;
}

Cube Cube::r() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.right, TOP_LEFT);
    set(newCube.right, TOP_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    temp = get(newCube.up, TOP_RIGHT);
    set(newCube.up, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.down, TOP_RIGHT));
    set(newCube.down, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.up, BOTTOM_RIGHT);
    set(newCube.up, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, temp);

    // edge
    temp = get(newCube.right, TOP_MIDDLE);
    set(newCube.right, TOP_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, MIDDLE_RIGHT);
    set(newCube.up, MIDDLE_RIGHT, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, get(newCube.down, MIDDLE_RIGHT));
    set(newCube.down, MIDDLE_RIGHT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

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

Cube Cube::r_prime() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.right, TOP_LEFT);
    set(newCube.right, TOP_LEFT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.up, TOP_RIGHT);
    set(newCube.up, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, get(newCube.down, TOP_RIGHT));
    set(newCube.down, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, temp);

    temp = get(newCube.up, BOTTOM_RIGHT);
    set(newCube.up, BOTTOM_RIGHT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, temp);

    // edge
    temp = get(newCube.right, TOP_MIDDLE);
    set(newCube.right, TOP_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.up, MIDDLE_RIGHT);
    set(newCube.up, MIDDLE_RIGHT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.down, MIDDLE_RIGHT));
    set(newCube.down, MIDDLE_RIGHT, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, temp);

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

Cube Cube::r2() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.right, TOP_LEFT);
    set(newCube.right, TOP_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.right, TOP_RIGHT);
    set(newCube.right, TOP_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.up, TOP_RIGHT);
    set(newCube.up, TOP_RIGHT, get(newCube.down, TOP_RIGHT));
    set(newCube.down, TOP_RIGHT, temp);

    temp = get(newCube.up, BOTTOM_RIGHT);
    set(newCube.up, BOTTOM_RIGHT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, temp);

    temp = get(newCube.front, TOP_RIGHT);
    set(newCube.front, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.front, BOTTOM_RIGHT);
    set(newCube.front, BOTTOM_RIGHT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, temp);

    // edges
    temp = get(newCube.right, TOP_MIDDLE);
    set(newCube.right, TOP_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.right, MIDDLE_LEFT);
    set(newCube.right, MIDDLE_LEFT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.up, MIDDLE_RIGHT);
    set(newCube.up, MIDDLE_RIGHT, get(newCube.down, MIDDLE_RIGHT));
    set(newCube.down, MIDDLE_RIGHT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

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
