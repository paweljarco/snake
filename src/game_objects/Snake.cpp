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
        position_ = position_.getCoordsDecreaseX(board::BOX_SIZE);
    if (direction_ == board::Direction::UP)
        position_ = position_.getCoordsIncreaseY(board::BOX_SIZE);
    if (direction_ == board::Direction::RIGHT)
        position_ = position_.getCoordsIncreaseX(board::BOX_SIZE);
    if (direction_ == board::Direction::DOWN)
        position_ = position_.getCoordsDecreaseY(board::BOX_SIZE);
}

void Snake::turnClockwise()
{
    direction_ = static_cast<board::Direction>((static_cast<int>(direction_) + 1 + 4) % 4);
}

void Snake::turnCounterClockwise()
{
    direction_= static_cast<board::Direction>((static_cast<int>(direction_) - 1 + 4) % 4);
}

} // namespace game_objects
