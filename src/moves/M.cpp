#include "cube.hpp"

Cube Cube::M() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // edges
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

Cube Cube::M2() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // edges
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

Cube Cube::M_prime() const {
    uint8_t temp = 0;
    Cube newCube = *this;

    // edges
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
