#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <array>
#include <cstddef>
#include <string>

// define colors
#define WHITE 0U
#define YELLOW 1U
#define GREEN 2U
#define BLUE 3U
#define RED 4U
#define ORANGE 5U

// Colors: WHITE=1 .. ORANGE=6
static const uint8_t COLORS[6] = {
    WHITE, YELLOW, GREEN, BLUE, RED, ORANGE
};

// define positions (within face)
#define TOP_LEFT 0U
#define TOP_MIDDLE 3U
#define TOP_RIGHT 6U
#define MIDDLE_LEFT 9U
#define CENTER 12U
#define MIDDLE_RIGHT 15U
#define BOTTOM_LEFT 18U
#define BOTTOM_MIDDLE 21U
#define BOTTOM_RIGHT 24U

// All sticker offsets on a face
static const uint8_t OFFSETS[9] = {
    TOP_LEFT, TOP_MIDDLE, TOP_RIGHT,
    MIDDLE_LEFT, CENTER, MIDDLE_RIGHT,
    BOTTOM_LEFT, BOTTOM_MIDDLE, BOTTOM_RIGHT
};


// clears, equivalent to 32 - position - 3
#define CLEAR_TOP_LEFT 29U
#define CLEAR_TOP_MIDDLE 26U
#define CLEAR_TOP_RIGHT 23U
#define CLEAR_MIDDLE_LEFT 20U
#define CLEAR_CENTER 17U
#define CLEAR_MIDDLE_RIGHT 14U
#define CLEAR_BOTTOM_LEFT 11U
#define CLEAR_BOTTOM_MIDDLE 8U
#define CLEAR_BOTTOM_RIGHT 5U

#define CLEAR 29U

// Face identifiers
#define UP     0U
#define FRONT  1U
#define RIGHT  2U
#define BACK   3U
#define LEFT   4U
#define DOWN   5U

// define solved faces
#define WHITE_FACE (WHITE << TOP_LEFT) + (WHITE << TOP_MIDDLE) + (WHITE << TOP_RIGHT) + (WHITE << MIDDLE_LEFT) + (WHITE << CENTER) + (WHITE << MIDDLE_RIGHT) + (WHITE << BOTTOM_LEFT) + (WHITE << BOTTOM_MIDDLE) + (WHITE << BOTTOM_RIGHT)
#define YELLOW_FACE (YELLOW << TOP_LEFT) + (YELLOW << TOP_MIDDLE) + (YELLOW << TOP_RIGHT) + (YELLOW << MIDDLE_LEFT) + (YELLOW << CENTER) + (YELLOW << MIDDLE_RIGHT) + (YELLOW << BOTTOM_LEFT) + (YELLOW << BOTTOM_MIDDLE) + (YELLOW << BOTTOM_RIGHT)
#define GREEN_FACE (GREEN << TOP_LEFT) + (GREEN << TOP_MIDDLE) + (GREEN << TOP_RIGHT) + (GREEN << MIDDLE_LEFT) + (GREEN << CENTER) + (GREEN << MIDDLE_RIGHT) + (GREEN << BOTTOM_LEFT) + (GREEN << BOTTOM_MIDDLE) + (GREEN << BOTTOM_RIGHT)
#define BLUE_FACE (BLUE << TOP_LEFT) + (BLUE << TOP_MIDDLE) + (BLUE << TOP_RIGHT) + (BLUE << MIDDLE_LEFT) + (BLUE << CENTER) + (BLUE << MIDDLE_RIGHT) + (BLUE << BOTTOM_LEFT) + (BLUE << BOTTOM_MIDDLE) + (BLUE << BOTTOM_RIGHT)
#define RED_FACE (RED << TOP_LEFT) + (RED << TOP_MIDDLE) + (RED << TOP_RIGHT) + (RED << MIDDLE_LEFT) + (RED << CENTER) + (RED << MIDDLE_RIGHT) + (RED << BOTTOM_LEFT) + (RED << BOTTOM_MIDDLE) + (RED << BOTTOM_RIGHT)
#define ORANGE_FACE (ORANGE << TOP_LEFT) + (ORANGE << TOP_MIDDLE) + (ORANGE << TOP_RIGHT) + (ORANGE << MIDDLE_LEFT) + (ORANGE << CENTER) + (ORANGE << MIDDLE_RIGHT) + (ORANGE << BOTTOM_LEFT) + (ORANGE << BOTTOM_MIDDLE) + (ORANGE << BOTTOM_RIGHT)

// define faces with invalid color (?) for debugging
// #define WHITE_FACE (7 << TOP_LEFT) + (7 << TOP_MIDDLE) + (WHITE << TOP_RIGHT) + (WHITE << MIDDLE_LEFT) + (WHITE << CENTER) + (WHITE << MIDDLE_RIGHT) + (WHITE << BOTTOM_LEFT) + (WHITE << BOTTOM_MIDDLE) + (WHITE << BOTTOM_RIGHT)
// #define YELLOW_FACE (7 << TOP_LEFT) + (7 << TOP_MIDDLE) + (YELLOW << TOP_RIGHT) + (YELLOW << MIDDLE_LEFT) + (YELLOW << CENTER) + (YELLOW << MIDDLE_RIGHT) + (YELLOW << BOTTOM_LEFT) + (YELLOW << BOTTOM_MIDDLE) + (YELLOW << BOTTOM_RIGHT)
// #define GREEN_FACE (7 << TOP_LEFT) + (7 << TOP_MIDDLE) + (GREEN << TOP_RIGHT) + (GREEN << MIDDLE_LEFT) + (GREEN << CENTER) + (GREEN << MIDDLE_RIGHT) + (GREEN << BOTTOM_LEFT) + (GREEN << BOTTOM_MIDDLE) + (GREEN << BOTTOM_RIGHT)
// #define BLUE_FACE (7 << TOP_LEFT) + (7 << TOP_MIDDLE) + (BLUE << TOP_RIGHT) + (BLUE << MIDDLE_LEFT) + (BLUE << CENTER) + (BLUE << MIDDLE_RIGHT) + (BLUE << BOTTOM_LEFT) + (BLUE << BOTTOM_MIDDLE) + (BLUE << BOTTOM_RIGHT)
// #define RED_FACE (7 << TOP_LEFT) + (7 << TOP_MIDDLE) + (RED << TOP_RIGHT) + (RED << MIDDLE_LEFT) + (RED << CENTER) + (RED << MIDDLE_RIGHT) + (RED << BOTTOM_LEFT) + (RED << BOTTOM_MIDDLE) + (RED << BOTTOM_RIGHT)
// #define ORANGE_FACE (7 << TOP_LEFT) + (7 << TOP_MIDDLE) + (ORANGE << TOP_RIGHT) + (ORANGE << MIDDLE_LEFT) + (ORANGE << CENTER) + (ORANGE << MIDDLE_RIGHT) + (ORANGE << BOTTOM_LEFT) + (ORANGE << BOTTOM_MIDDLE) + (ORANGE << BOTTOM_RIGHT)

struct StickerPos {
    uint8_t face;
    uint8_t pos;
};

// Corner cubies: index -> 3 sticker positions
static const StickerPos CORNER_STICKERS[8][3] = {
    { {UP, BOTTOM_RIGHT}, {RIGHT, TOP_LEFT}, {FRONT, TOP_RIGHT} }, // 0: UFR
    { {UP, TOP_RIGHT}, {BACK, TOP_LEFT}, {RIGHT, TOP_RIGHT} }, // 1: URB
    { {UP, TOP_LEFT}, {LEFT, TOP_LEFT}, {BACK, TOP_RIGHT} }, // 2: UBL
    { {UP, BOTTOM_LEFT}, {FRONT, TOP_LEFT}, {LEFT, TOP_RIGHT} }, // 3: ULF
    { {DOWN, TOP_RIGHT}, {FRONT, BOTTOM_RIGHT}, {RIGHT, BOTTOM_LEFT} }, // 4: DFR
    { {DOWN, BOTTOM_RIGHT}, {RIGHT, BOTTOM_RIGHT}, {BACK, BOTTOM_LEFT} }, // 5: DRB
    { {DOWN, BOTTOM_LEFT}, {BACK, BOTTOM_RIGHT}, {LEFT, BOTTOM_LEFT} }, // 6: DBL
    { {DOWN, TOP_LEFT}, {LEFT, BOTTOM_RIGHT}, {FRONT, BOTTOM_LEFT} } // 7: DLF
};

static const uint8_t CORNERS[8][3] = {
    {WHITE, RED, GREEN},    // UFR
    {WHITE, BLUE, RED},   // URB
    {WHITE, ORANGE, BLUE}, // UBL
    {WHITE, GREEN, ORANGE},  // ULF
    {YELLOW, GREEN,  RED},   // DFR
    {YELLOW, RED,    BLUE},  // DRB
    {YELLOW, BLUE,   ORANGE},// DBL
    {YELLOW, ORANGE, GREEN}  // DLF
};

// Edge cubies: index -> 2 sticker positions
static const StickerPos EDGE_STICKERS[12][2] = {
    { {UP, BOTTOM_MIDDLE},    {FRONT, TOP_MIDDLE} },     // UF
    { {UP, MIDDLE_RIGHT},     {RIGHT, TOP_MIDDLE} },     // UR
    { {UP, TOP_MIDDLE},      {BACK, TOP_MIDDLE} },       // UB
    { {UP, MIDDLE_LEFT},    {LEFT, TOP_MIDDLE} },        // UL

    { {FRONT, MIDDLE_RIGHT}, {RIGHT, MIDDLE_LEFT} },     // FR
    { {BACK,  MIDDLE_LEFT}, {RIGHT, MIDDLE_RIGHT} },     // BR
    { {BACK,  MIDDLE_RIGHT},  {LEFT,  MIDDLE_LEFT} },    // BL
    { {FRONT, MIDDLE_LEFT},  {LEFT,  MIDDLE_RIGHT} },    // FL

    { {DOWN, TOP_MIDDLE}, {FRONT, BOTTOM_MIDDLE} },      // DF
    { {DOWN, MIDDLE_RIGHT},  {RIGHT, BOTTOM_MIDDLE} },   // DR
    { {DOWN, BOTTOM_MIDDLE},   {BACK,  BOTTOM_MIDDLE} }, // DB
    { {DOWN, MIDDLE_LEFT}, {LEFT,  BOTTOM_MIDDLE} }      // DL
};

static const uint8_t EDGES[12][2] = {
    {WHITE, GREEN},   // UF
    {WHITE, RED},     // UR
    {WHITE, BLUE},    // UB
    {WHITE, ORANGE},  // UL

    {GREEN,  RED},    // FR
    {BLUE,   RED},    // BR
    {BLUE,   ORANGE}, // BL
    {GREEN,  ORANGE}, // FL

    {YELLOW, GREEN},  // DF
    {YELLOW, RED},    // DR
    {YELLOW, BLUE},   // DB
    {YELLOW, ORANGE}  // DL
};

struct CornerCubie {
    uint8_t colors[3];      // which solved-corner this corresponds to (0–7)
    uint8_t orientation;    // orientation 0–2
    int id;
};

struct EdgeCubie {
    uint8_t colors[2];      // which solved-edge (0–11)
    uint8_t orientation;    // 0 or 1
    int id;
};


std::string getColor(uint8_t num);
uint8_t get(uint32_t num, uint8_t from);
void set(uint32_t &num, int to, uint8_t set_val);

template <typename T, std::size_t N>
bool array_circular_equal(const std::array<T, N> &a, const std::array<T, N> &b) {
    if constexpr (N == 0) return true;

    for (std::size_t shift = 0; shift < N; ++shift) {
        bool equal = true;
        for (std::size_t i = 0; i < N; ++i) {
            if (a[(i + shift) % N] != b[i]) {
                equal = false;
                break;
            }
        }
        if (equal) return true;
    }
    return false;
};

#pragma once
extern bool __USE_EMOJI;

inline void PRINT_EMOJIS(bool value) { __USE_EMOJI = value; }

#endif // COMMON_H
