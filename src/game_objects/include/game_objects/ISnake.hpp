#pragma once

#include "board/Coordinates.hpp"

class ISnake {
public:
    virtual ~ISnake() = default;

    virtual board::Coordinates& getPosition() = 0;
    virtual void move() = 0;
    virtual board::Direction getDirection() = 0;
    virtual void setDirection(board::Direction direction) = 0;
};

