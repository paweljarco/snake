#include "game/Game.hpp"

#include <algorithm>

#include "board/ConstBoardValues.hpp"
#include "game_objects/Tail.hpp"
#include "game_objects/Snake.hpp"


namespace game
{
Game::Game()
{
    snake_ = std::make_unique<game_objects::Snake>();
    createTail();
    isRunning_= true;

}
bool Game::isSnakeBittingHisTail()
{
    return std::find_if(tailsList_.begin(), tailsList_.end(), [coords(snake_->getPosition())](const auto& tail) {
        return tail->getPosition() == coords;
    }) != tailsList_.end();
}

void Game::createTail()
{
    auto initialPosition = snake_->getPosition();
    for (auto i = 5; i >= 5; i--)
    {
        initialPosition.x_ -= board::BOX_SIZE;
        tailsList_.push_back(game_objects::Tail::create(initialPosition, i));
    }
}

void Game::move()
{
    if (isSnakeBittingHisTail())
    {
        gameOver();
    }

    moveSnake();
}

void Game::moveSnake()
{
    if(!tailsList_.back()->isAlive())
    {
        tailsList_.pop_back();
    }
    auto newTailLifeSpan = tailsList_.size() + 1;
    tailsList_.push_front(game_objects::Tail::create(snake_->getPosition(), newTailLifeSpan));
    snake_->turnClockwise(); // to be modify
    snake_->move();
}

void Game::gameOver()
{
    isRunning_ = false;
}

bool Game::isRunning()
{
    return isRunning_;
}

void Game::trimTailsLifeSpan()
{
    for (auto& tail : tailsList_)
    {
        tail->trimLife();
    }
}

} // namespace game
