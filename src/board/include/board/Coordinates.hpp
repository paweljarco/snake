#pragma once

#include <cstdint>

namespace board {
class  Coordinates {
public:
    Coordinates(uint32_t x, uint32_t y);
    ~Coordinates() = default;

    uint32_t getX() const;
    uint32_t getY() const;
    Coordinates getCoordsIncreaseX(uint32_t value) const;
    Coordinates getCoordsIncreaseY(uint32_t value) const;
    Coordinates getCoordsDecreaseX(uint32_t value) const;
    Coordinates getCoordsDecreaseY(uint32_t value) const;
    bool operator==(const Coordinates& rhs);


private:
    uint32_t x_;
    uint32_t y_;
};

enum  Direction {
    LEFT = 0,
    UP = 1,
    RIGHT = 2,
    DOWN = 3
};

}  // namespace board
