#include <cassert>
#include <cstdint>
#include <string>

#include "common.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

bool __USE_EMOJI = true;

string getColor(uint32_t num) {
    if (__USE_EMOJI) {
        #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        #endif
    
        if (num == WHITE)
            return "⬜";
        else if (num == YELLOW)
            return "🟨";
        else if (num == GREEN)
            return "🟩";
        else if (num == BLUE)
            return "🟦";
        else if (num == RED)
            return "🟥";
        else if (num == ORANGE)
            return "🟧";
        else
            // cout << num << endl;
            return "⬛";
    } else {
        if (num == WHITE)
            return "W";
        else if (num == YELLOW)
            return "Y";
        else if (num == GREEN)
            return "G";
        else if (num == BLUE)
            return "B";
        else if (num == RED)
            return "R";
        else if (num == ORANGE)
            return "O";
        else
            // cout << num << endl;
            return "?";
    }
}

uint8_t get(uint32_t num, uint8_t from) {
    return static_cast<uint8_t>((num << (32-from-3)) >> CLEAR); 
}

void set(uint32_t &num, int to, uint8_t set_val) {
    assert(set_val < 8);
    num &= ~(7 << to);
    num |= (set_val << to);
}
