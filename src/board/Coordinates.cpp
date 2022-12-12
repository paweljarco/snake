#include "board/Coordinates.hpp"

namespace board
{
Coordinates::Coordinates(uint32_t x, uint32_t y)
    : x_(x)
    , y_(y)
{}

uint32_t Coordinates::getX() const
{
    return x_;
}

uint32_t Coordinates::getY() const
{
    return y_;
}

Coordinates Coordinates::getCoordsIncreaseX(uint32_t value) const
{
    return Coordinates(x_ + value, y_);
}

Coordinates Coordinates::getCoordsIncreaseY(uint32_t value) const
{
    return Coordinates(x_, y_ + value);
}

Coordinates Coordinates::getCoordsDecreaseX(uint32_t value) const
{
    return Coordinates(x_ - value, y_);
}

Coordinates Coordinates::getCoordsDecreaseY(uint32_t value) const
{
    return Coordinates(x_, y_ - value);
}

bool Coordinates::operator==(const Coordinates& rhs)
{
    return x_ == rhs.getX() && y_ == rhs.getY();
}

} // namespace board
