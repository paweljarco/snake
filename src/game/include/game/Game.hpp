#pragma once

#include "IGame.hpp"

#include <random>

namespace game_objects
{
class Fruit;
class Snake;
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
    const std::list<game_objects::TailPtr>& getTails() override;
    void turn(board::Direction direction) override;
    std::optional<board::Coordinates> getFruitPosition() override;

private:
    void createTail();
    bool isSnakeBittingHisTail();
    bool isSnakeOutsideBoard();
    void gameOver();
    void moveSnake();
    void trimTailsLifeSpan();
    void turnUpHandler();
    void turnDownHandler();
    void turnLeftHandler();
    void turnRightHandler();
    void spawnFruit();
    bool isSnakeEatingFruit();

    std::unique_ptr<game_objects::Snake> snake_;
    std::list<game_objects::TailPtr> tailsList_;
    bool isRunning_;
    std::unique_ptr<game_objects::Fruit> fruit_;
};

} // namespace game
