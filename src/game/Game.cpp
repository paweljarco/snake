#include "game/Game.hpp"

#include <algorithm>

#include "game_objects/Tail.hpp"
#include "game_objects/Snake.hpp"


namespace game
{
Game::Game()
{
    snake_ = std::make_unique<game_objects::Snake>();
    createTail();

}
bool Game::checkForSnakeObjectCollision()
{
    return std::find_if(tailsList_.begin(), tailsList_.end(), [coords(&snake_->getPosition())](const auto& tail) {
        return tail->getPosition() == coords;
    }) != tailsList_.end();
}

void Game::createTail()
{
    for (int i = 1; i <= 5; i++)
    {
        game_objects::Tail::create()
    }
}

} // namespace game
