#include "game/Game.hpp"

#include <algorithm>

#include "board/ConstBoardValues.hpp"
#include "game_objects/Fruit.hpp"
#include "game_objects/Tail.hpp"
#include "game_objects/Snake.hpp"


namespace game
{
Game::Game()
    : fruitXPosGenerator_(0, (board::BOARD_WIDTH - board::BOX_SIZE) / board::BOX_SIZE)
    , fruitYPosGenerator_(0, (board::BOARD_HEIGHT - board::BOX_SIZE) / board::BOX_SIZE)
{}

void Game::newGame()
{
    if (snake_)
    {
        snake_.reset();
        tailsList_.clear();
    }
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

bool Game::isSnakeOutsideBoard()
{
    auto posX = snake_->getPosition().x_;
    auto posY = snake_->getPosition().y_;

    if (posX < 0 || posX > board::BOARD_WIDTH - board::BOX_SIZE
            || posY < 0 || posY > board::BOARD_HEIGHT - board::BOX_SIZE)
    {
        return true;
    }
    return false;
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

        trimTailsLifeSpan();
    moveSnake();
    if (isSnakeBittingHisTail() || isSnakeOutsideBoard())
    {
        gameOver();
        return;
    }

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

const std::list<game_objects::TailPtr>& Game::getTails()
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

void Game::spawnFruit()
{
    if (!fruit_)
    {
        auto posX = fruitXPosGenerator_.generate() * board::BOX_SIZE;
        auto posY = fruitYPosGenerator_.generate() * board::BOX_SIZE;
        fruit_ = game_objects::Fruit::create({posX, posY});
    }
}

std::optional<board::Coordinates> Game::getFruitPosition()
{
    if (!fruit_)
    {
        return std::nullopt;
    }
    return fruit_->getPosition();
}

} // namespace game
