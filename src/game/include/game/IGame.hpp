#pragma once
#include <list>
#include <memory>
#include <optional>

#include "board/Coordinates.hpp"

namespace game_objects
{
class Tail;
using TailPtr = std::unique_ptr<Tail>;
} // namespace game_objects
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
    virtual const std::list<game_objects::TailPtr>& getTails() = 0;
    virtual void turn(board::Direction direction) = 0;
    virtual std::optional<board::Coordinates> getFruitPosition() = 0;

};
} // namespace game
