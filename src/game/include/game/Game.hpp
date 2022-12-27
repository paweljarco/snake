#pragma once

#include "IGame.hpp"

#include <memory>
#include <list>

namespace game_objects
{
class IObject;
class Snake;
using IObjectPtr = std::unique_ptr<IObject>;
} // namespace game_objects

namespace game
{
class Game : public IGame
{
public:
    Game();
    ~Game() = default;
    void newGame() override;
    void move() override;
    bool isRunning() override;
    const board::Coordinates& getSnakePosition() override;
    const std::list<game_objects::IObjectPtr>& getTails() override;

private:
    void createTail();
    bool isSnakeBittingHisTail();
    void gameOver();
    void moveSnake();
    void trimTailsLifeSpan();

    std::unique_ptr<game_objects::Snake> snake_;
    std::list<game_objects::IObjectPtr> tailsList_;
    bool isRunning_;

};

} // namespace game
