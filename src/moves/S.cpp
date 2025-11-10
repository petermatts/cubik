#include "cube.hpp"

Cube Cube::S() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // edges
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

Cube Cube::S_prime() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // edges
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

Cube Cube::S2() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // edges
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
