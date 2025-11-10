#include "cube.hpp"

Cube Cube::U() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.up, BOTTOM_LEFT));
    set(newCube.up, BOTTOM_LEFT, get(newCube.up, BOTTOM_RIGHT));
    set(newCube.up, BOTTOM_RIGHT, get(newCube.up, TOP_RIGHT));
    set(newCube.up, TOP_RIGHT, temp);

    temp = get(newCube.back, TOP_RIGHT);
    set(newCube.back, TOP_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    // edge
    temp = get(newCube.up, TOP_MIDDLE);
    set(newCube.up, TOP_MIDDLE, get(newCube.up, MIDDLE_LEFT));
    set(newCube.up, MIDDLE_LEFT, get(newCube.up, BOTTOM_MIDDLE));
    set(newCube.up, BOTTOM_MIDDLE, get(newCube.up, MIDDLE_RIGHT));
    set(newCube.up, MIDDLE_RIGHT, temp);

    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    return newCube;
}

Cube Cube::U_prime() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.up, TOP_RIGHT));
    set(newCube.up, TOP_RIGHT, get(newCube.up, BOTTOM_RIGHT));
    set(newCube.up, BOTTOM_RIGHT, get(newCube.up, BOTTOM_LEFT));
    set(newCube.up, BOTTOM_LEFT, temp);

    temp = get(newCube.back, TOP_RIGHT);
    set(newCube.back, TOP_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, temp);

    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, temp);

    // edge
    temp = get(newCube.up, TOP_MIDDLE);
    set(newCube.up, TOP_MIDDLE, get(newCube.up, MIDDLE_RIGHT));
    set(newCube.up, MIDDLE_RIGHT, get(newCube.up, BOTTOM_MIDDLE));
    set(newCube.up, BOTTOM_MIDDLE, get(newCube.up, MIDDLE_LEFT));
    set(newCube.up, MIDDLE_LEFT, temp);

    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, temp);

    return newCube;
}

Cube Cube::U2() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.up, BOTTOM_RIGHT));
    set(newCube.up, BOTTOM_RIGHT, temp);

    temp = get(newCube.up, TOP_RIGHT);
    set(newCube.up, TOP_RIGHT, get(newCube.up, BOTTOM_LEFT));
    set(newCube.up, BOTTOM_LEFT, temp);

    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, temp);

    temp = get(newCube.front, TOP_RIGHT);
    set(newCube.front, TOP_RIGHT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    temp = get(newCube.left, TOP_RIGHT);
    set(newCube.left, TOP_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    // edges
    temp = get(newCube.up, TOP_MIDDLE);
    set(newCube.up, TOP_MIDDLE, get(newCube.up, BOTTOM_MIDDLE));
    set(newCube.up, BOTTOM_MIDDLE, temp);

    temp = get(newCube.up, MIDDLE_LEFT);
    set(newCube.up, MIDDLE_LEFT, get(newCube.up, MIDDLE_RIGHT));
    set(newCube.up, MIDDLE_RIGHT, temp);

    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, temp);

    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    return newCube;
}

Cube Cube::u() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.up, BOTTOM_LEFT));
    set(newCube.up, BOTTOM_LEFT, get(newCube.up, BOTTOM_RIGHT));
    set(newCube.up, BOTTOM_RIGHT, get(newCube.up, TOP_RIGHT));
    set(newCube.up, TOP_RIGHT, temp);

    temp = get(newCube.back, TOP_RIGHT);
    set(newCube.back, TOP_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    // edge
    temp = get(newCube.up, TOP_MIDDLE);
    set(newCube.up, TOP_MIDDLE, get(newCube.up, MIDDLE_LEFT));
    set(newCube.up, MIDDLE_LEFT, get(newCube.up, BOTTOM_MIDDLE));
    set(newCube.up, BOTTOM_MIDDLE, get(newCube.up, MIDDLE_RIGHT));
    set(newCube.up, MIDDLE_RIGHT, temp);

    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

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

Cube Cube::u_prime() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.up, TOP_RIGHT));
    set(newCube.up, TOP_RIGHT, get(newCube.up, BOTTOM_RIGHT));
    set(newCube.up, BOTTOM_RIGHT, get(newCube.up, BOTTOM_LEFT));
    set(newCube.up, BOTTOM_LEFT, temp);

    temp = get(newCube.back, TOP_RIGHT);
    set(newCube.back, TOP_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, temp);

    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, temp);

    // edge
    temp = get(newCube.up, TOP_MIDDLE);
    set(newCube.up, TOP_MIDDLE, get(newCube.up, MIDDLE_RIGHT));
    set(newCube.up, MIDDLE_RIGHT, get(newCube.up, BOTTOM_MIDDLE));
    set(newCube.up, BOTTOM_MIDDLE, get(newCube.up, MIDDLE_LEFT));
    set(newCube.up, MIDDLE_LEFT, temp);

    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, temp);

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

Cube Cube::u2() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.up, TOP_LEFT);
    set(newCube.up, TOP_LEFT, get(newCube.up, BOTTOM_RIGHT));
    set(newCube.up, BOTTOM_RIGHT, temp);

    temp = get(newCube.up, TOP_RIGHT);
    set(newCube.up, TOP_RIGHT, get(newCube.up, BOTTOM_LEFT));
    set(newCube.up, BOTTOM_LEFT, temp);

    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, temp);

    temp = get(newCube.front, TOP_RIGHT);
    set(newCube.front, TOP_RIGHT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    temp = get(newCube.left, TOP_RIGHT);
    set(newCube.left, TOP_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    // edges
    temp = get(newCube.up, TOP_MIDDLE);
    set(newCube.up, TOP_MIDDLE, get(newCube.up, BOTTOM_MIDDLE));
    set(newCube.up, BOTTOM_MIDDLE, temp);

    temp = get(newCube.up, MIDDLE_LEFT);
    set(newCube.up, MIDDLE_LEFT, get(newCube.up, MIDDLE_RIGHT));
    set(newCube.up, MIDDLE_RIGHT, temp);

    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, temp);

    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

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
