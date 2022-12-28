#pragma once

#include <cstdint>

namespace board {
struct Coordinates {
    Coordinates(uint32_t x, uint32_t y);
    ~Coordinates() = default;

    bool operator==(const Coordinates& rhs);
    uint32_t x_;
    uint32_t y_;
};

enum  Direction {
    LEFT = 0,
    DOWN = 1,
    RIGHT = 2,
    UP = 3
};

}  // namespace board
