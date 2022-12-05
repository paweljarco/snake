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
    bool checkForSnakeObjectCollision() override;

private:


    std::unique_ptr<game_objects::Snake> snake_;
    std::list<game_objects::IObjectPtr> tailsList_;

};

} // namespace game
