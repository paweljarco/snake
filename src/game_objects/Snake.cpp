#include "game_objects/Snake.hpp"

#include "board/ConstBoardValues.hpp"

namespace game_objects
{
Snake::Snake()
    : position_{board::BEGINNING_POSITION}
    , direction_{board::Direction::LEFT}
{}

board::Coordinates& Snake::getPosition()
{
    return position_;
}

void Snake::move()
{
    if (direction_ == board::Direction::LEFT)
        position_.x_ -= board::BOX_SIZE;
    if (direction_ == board::Direction::UP)
        position_.y_ -= board::BOX_SIZE;
    if (direction_ == board::Direction::RIGHT)
        position_.x_ += board::BOX_SIZE;
    if (direction_ == board::Direction::DOWN)
        position_.y_ += board::BOX_SIZE;
}

board::Direction Snake::getDirection()
{
    return direction_;
}

void Snake::setDirection(board::Direction direction)
{
    direction_ = direction;
}

} // namespace game_objects
