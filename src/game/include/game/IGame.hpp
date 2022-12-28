#pragma once
#include <list>
#include "board/Coordinates.hpp"
#include "game_objects/IObject.hpp"

namespace game
{
class IGame
{
public:
    virtual ~IGame() = default;
    virtual void newGame() = 0;
    virtual void move() = 0;
    virtual bool isRunning() = 0;
    virtual const board::Coordinates& getSnakePosition() = 0;
    virtual const std::list<game_objects::IObjectPtr>& getTails() = 0;
    virtual void turn(board::Direction direction) = 0;

};
} // namespace game
