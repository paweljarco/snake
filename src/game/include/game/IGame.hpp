#pragma once

namespace game
{
class IGame
{
public:
    virtual ~IGame() = default;
    virtual bool checkForSnakeObjectCollision() = 0;
};
} // namespace game
