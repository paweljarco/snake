#pragma once

#include <cstdint>

namespace board {
class  Coordinates {
public:
    Coordinates(uint32_t x, uint32_t y);
    ~Coordinates() = default;

    uint32_t getX() const;
    uint32_t getY() const;
    void increaseX(uint32_t value);
    void increaseY(uint32_t value);
    void decreaseX(uint32_t value);
    void decreaseY(uint32_t value);
    bool operator==(const Coordinates& rhs);
    bool operator==(Coordinates& rhs);


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
