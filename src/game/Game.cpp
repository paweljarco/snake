#include "game/Game.hpp"

#include <algorithm>

#include "game_objects/Tail.hpp"
#include "game_objects/Snake.hpp"


namespace game
{
Game::Game()
{
    snake_ = std::make_unique<game_objects::Snake>();

}
bool Game::checkForSnakeObjectCollision()
{
    return std::find_if(tailsList_.begin(), tailsList_.end(), [coords(&snake_->getPosition())](const auto& tail) {
        return tail->getPosition() == coords;
    }) != tailsList_.end();
}


} // namespace game
