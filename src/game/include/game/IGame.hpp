#pragma once
#include <list>
#include "game_objects/IObject.hpp"

namespace board
{
class Coordinates;
} // namespace board

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

};
} // namespace game
