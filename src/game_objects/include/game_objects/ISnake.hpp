#pragma once

namespace board
{
class Coordinates;
} // namespace board

class ISnake {
public:
    virtual ~ISnake() = default;

    virtual board::Coordinates& getPosition() const = 0;
    virtual void move() = 0;
    virtual void turnClockwise() = 0;
    virtual void turnCounterClockwise() = 0;
};

