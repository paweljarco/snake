#include "game/Game.hpp"

#include <algorithm>

#include "board/ConstBoardValues.hpp"
#include "game_objects/Tail.hpp"
#include "game_objects/Snake.hpp"

namespace
{
constexpr int MAX_LIFE = 6;
}

namespace game
{
Game::Game()
{
    snake_ = std::make_unique<game_objects::Snake>();
    createTail();

}
bool Game::checkForSnakeObjectCollision()
{
    return std::find_if(tailsList_.begin(), tailsList_.end(), [coords(snake_->getPosition())](auto& tail) {
        return tail->getPosition() == coords;
    }) != tailsList_.end();
}

void Game::createTail()
{
    for (int i = 1; i <= 5; i++)
    {
        tailsList_.emplace_back(game_objects::Tail::create(snake_->getPosition().getCoordsIncreaseX(i * board::BOX_SIZE), MAX_LIFE - i));
    }
}

} // namespace game
