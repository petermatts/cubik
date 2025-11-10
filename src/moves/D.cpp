#include "cube.hpp"

Cube Cube::D() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.down, TOP_LEFT);
    set(newCube.down, TOP_LEFT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, get(newCube.down, TOP_RIGHT));
    set(newCube.down, TOP_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_RIGHT);
    set(newCube.back, BOTTOM_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_LEFT);
    set(newCube.back, BOTTOM_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.down, TOP_MIDDLE);
    set(newCube.down, TOP_MIDDLE, get(newCube.down, MIDDLE_LEFT));
    set(newCube.down, MIDDLE_LEFT, get(newCube.down, BOTTOM_MIDDLE));
    set(newCube.down, BOTTOM_MIDDLE, get(newCube.down, MIDDLE_RIGHT));
    set(newCube.down, MIDDLE_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_MIDDLE);
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, temp);

    return newCube;
}

Cube Cube::D_prime() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.down, TOP_LEFT);
    set(newCube.down, TOP_LEFT, get(newCube.down, TOP_RIGHT));
    set(newCube.down, TOP_RIGHT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, temp);

    temp = get(newCube.back, BOTTOM_RIGHT);
    set(newCube.back, BOTTOM_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_LEFT);
    set(newCube.back, BOTTOM_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.down, TOP_MIDDLE);
    set(newCube.down, TOP_MIDDLE, get(newCube.down, MIDDLE_RIGHT));
    set(newCube.down, MIDDLE_RIGHT, get(newCube.down, BOTTOM_MIDDLE));
    set(newCube.down, BOTTOM_MIDDLE, get(newCube.down, MIDDLE_LEFT));
    set(newCube.down, MIDDLE_LEFT, temp);

    temp = get(newCube.back, BOTTOM_MIDDLE);
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    return newCube;
}

Cube Cube::D2() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.down, TOP_LEFT);
    set(newCube.down, TOP_LEFT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, temp);

    temp = get(newCube.down, TOP_RIGHT);
    set(newCube.down, TOP_RIGHT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, temp);

    temp = get(newCube.front, BOTTOM_LEFT);
    set(newCube.front, BOTTOM_LEFT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.front, BOTTOM_RIGHT);
    set(newCube.front, BOTTOM_RIGHT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, BOTTOM_LEFT);
    set(newCube.left, BOTTOM_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.left, BOTTOM_RIGHT);
    set(newCube.left, BOTTOM_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    // edges
    temp = get(newCube.down, TOP_MIDDLE);
    set(newCube.down, TOP_MIDDLE, get(newCube.down, BOTTOM_MIDDLE));
    set(newCube.down, BOTTOM_MIDDLE, temp);

    temp = get(newCube.down, MIDDLE_LEFT);
    set(newCube.down, MIDDLE_LEFT, get(newCube.down, MIDDLE_RIGHT));
    set(newCube.down, MIDDLE_RIGHT, temp);

    temp = get(newCube.front, BOTTOM_MIDDLE);
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, BOTTOM_MIDDLE);
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    return newCube;
}

Cube Cube::d() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.down, TOP_LEFT);
    set(newCube.down, TOP_LEFT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, get(newCube.down, TOP_RIGHT));
    set(newCube.down, TOP_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_RIGHT);
    set(newCube.back, BOTTOM_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_LEFT);
    set(newCube.back, BOTTOM_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.down, TOP_MIDDLE);
    set(newCube.down, TOP_MIDDLE, get(newCube.down, MIDDLE_LEFT));
    set(newCube.down, MIDDLE_LEFT, get(newCube.down, BOTTOM_MIDDLE));
    set(newCube.down, BOTTOM_MIDDLE, get(newCube.down, MIDDLE_RIGHT));
    set(newCube.down, MIDDLE_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_MIDDLE);
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    // centers
    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::d_prime() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.down, TOP_LEFT);
    set(newCube.down, TOP_LEFT, get(newCube.down, TOP_RIGHT));
    set(newCube.down, TOP_RIGHT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, temp);

    temp = get(newCube.back, BOTTOM_RIGHT);
    set(newCube.back, BOTTOM_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_LEFT);
    set(newCube.back, BOTTOM_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.down, TOP_MIDDLE);
    set(newCube.down, TOP_MIDDLE, get(newCube.down, MIDDLE_RIGHT));
    set(newCube.down, MIDDLE_RIGHT, get(newCube.down, BOTTOM_MIDDLE));
    set(newCube.down, BOTTOM_MIDDLE, get(newCube.down, MIDDLE_LEFT));
    set(newCube.down, MIDDLE_LEFT, temp);

    temp = get(newCube.back, BOTTOM_MIDDLE);
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    // centers
    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, temp);

    return newCube;
}

Cube Cube::d2() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.down, TOP_LEFT);
    set(newCube.down, TOP_LEFT, get(newCube.down, BOTTOM_RIGHT));
    set(newCube.down, BOTTOM_RIGHT, temp);

    temp = get(newCube.down, TOP_RIGHT);
    set(newCube.down, TOP_RIGHT, get(newCube.down, BOTTOM_LEFT));
    set(newCube.down, BOTTOM_LEFT, temp);

    temp = get(newCube.front, BOTTOM_LEFT);
    set(newCube.front, BOTTOM_LEFT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.front, BOTTOM_RIGHT);
    set(newCube.front, BOTTOM_RIGHT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, BOTTOM_LEFT);
    set(newCube.left, BOTTOM_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.left, BOTTOM_RIGHT);
    set(newCube.left, BOTTOM_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    // edges
    temp = get(newCube.down, TOP_MIDDLE);
    set(newCube.down, TOP_MIDDLE, get(newCube.down, BOTTOM_MIDDLE));
    set(newCube.down, BOTTOM_MIDDLE, temp);

    temp = get(newCube.down, MIDDLE_LEFT);
    set(newCube.down, MIDDLE_LEFT, get(newCube.down, MIDDLE_RIGHT));
    set(newCube.down, MIDDLE_RIGHT, temp);

    temp = get(newCube.front, BOTTOM_MIDDLE);
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, BOTTOM_MIDDLE);
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.left, MIDDLE_LEFT);
    set(newCube.left, MIDDLE_LEFT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.left, MIDDLE_RIGHT);
    set(newCube.left, MIDDLE_RIGHT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    // centers
    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, temp);

    temp = get(newCube.left, CENTER);
    set(newCube.left, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}
