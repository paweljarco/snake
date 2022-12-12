#include "board/Coordinates.hpp"

namespace board
{
Coordinates::Coordinates(uint32_t x, uint32_t y)
    : x_(x)
    , y_(y)
{}

bool Coordinates::operator==(const Coordinates& rhs)
{
    return x_ == rhs.x_ && y_ == rhs.y_;
}

} // namespace board
