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

void Coordinates::increaseX(uint32_t value)
{
    x_+= value;
}

void Coordinates::increaseY(uint32_t value)
{
    y_+= value;
}

void Coordinates::decreaseX(uint32_t value)
{
    x_-= value;
}

void Coordinates::decreaseY(uint32_t value)
{
    y_-= value;
}

bool Coordinates::operator==(const Coordinates& rhs)
{
    return x_ == rhs.getX() && y_ == rhs.getY();
}

bool Coordinates::operator==(Coordinates& rhs)
{
    return x_ == rhs.getX() && y_ == rhs.getY();
}

} // namespace board
