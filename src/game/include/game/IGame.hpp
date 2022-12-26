#pragma once

namespace game
{
class IGame
{
public:
    virtual ~IGame() = default;
    virtual void move() = 0;
    virtual bool isRunning() = 0;
};
} // namespace game
