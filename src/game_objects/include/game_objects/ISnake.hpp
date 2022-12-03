#pragma once

#include "board/Coordinates.hpp"

class ISnake {
public:
    virtual ~ISnake() = default;

    virtual board::Coordinates getPosition() const = 0;
    virtual void move() = 0;
    virtual void turnClockwise() = 0;
    virtual void turnCounterClockwise() = 0;
};

