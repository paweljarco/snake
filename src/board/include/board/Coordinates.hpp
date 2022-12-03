#pragma once

#include <cstdint>

namespace board {
struct Coordinates {

    uint32_t x;
    uint32_t y;
};

enum  Direction {
    LEFT = 0,
    UP = 1,
    RIGHT = 2,
    DOWN = 3
};

}  // namespace board
