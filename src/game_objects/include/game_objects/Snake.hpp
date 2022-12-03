#pragma once

#include "ISnake.hpp"

#include "board/Coordinates.hpp"

namespace game_objects
{

class Snake : public ISnake {
public:
    Snake();
    ~Snake() = default;
    board::Coordinates getPosition() const override;
    void move() override;
    void turnClockwise() override;
    void turnCounterClockwise() override;

private:
    board::Coordinates position_;
    board::Direction direction_;
};

}  // namespace game_objects
