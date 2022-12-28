#include "game/Game.hpp"

#include <algorithm>

#include "board/ConstBoardValues.hpp"
#include "game_objects/Tail.hpp"
#include "game_objects/Snake.hpp"


namespace game
{
Game::Game()
{}

void Game::newGame()
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
    for (auto i = 5; i >= 1; i--)
    {
        initialPosition.x_ += board::BOX_SIZE;
        tailsList_.push_back(game_objects::Tail::create(initialPosition, i));
    }
}

void Game::move()
{
    if (isSnakeBittingHisTail())
    {
        gameOver();
    }

    trimTailsLifeSpan();
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
    snake_->move();
}

void Game::gameOver()
{
    isRunning_ = false;
    snake_.reset();
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

const board::Coordinates& Game::getSnakePosition()
{
    return snake_->getPosition();
}

const std::list<game_objects::IObjectPtr>& Game::getTails()
{
    return tailsList_;
}

void Game::turn(board::Direction direction)
{
    switch (direction) {
    case board::Direction::DOWN:
        turnDownHandler();
        break;
    case board::Direction::UP:
        turnUpHandler();
        break;
    case board::Direction::LEFT:
        turnLeftHandler();
        break;
    case board::Direction::RIGHT:
        turnRightHandler();
        break;
    default:
        return;
    }
}

void Game::turnUpHandler()
{
    switch (snake_->getDirection()) {
    case board::Direction::LEFT:
    case board::Direction::RIGHT:
        snake_->setDirection(board::Direction::UP);
        break;
    default:
        return;
    }
}

void Game::turnDownHandler()
{
    switch (snake_->getDirection()) {
    case board::Direction::LEFT:
    case board::Direction::RIGHT:
        snake_->setDirection(board::Direction::DOWN);
        break;
    default:
        return;
    }
}

void Game::turnRightHandler()
{
    switch (snake_->getDirection()) {
    case board::Direction::UP:
    case board::Direction::DOWN:
        snake_->setDirection(board::Direction::RIGHT);
        break;
    default:
        return;
    }
}

void Game::turnLeftHandler()
{
    switch (snake_->getDirection()) {
    case board::Direction::UP:
    case board::Direction::DOWN:
        snake_->setDirection(board::Direction::LEFT);
        break;
    default:
        return;
    }
}

} // namespace game
