#pragma once

#include <memory>

namespace board
{
class Coordinates;
} // namespace board

namespace game_objects
{
constexpr unsigned int END_OF_LIFE = 0;

class IObject
{
public:
    virtual ~IObject() = default;
    virtual board::Coordinates& getPosition() = 0;
    virtual bool isAlive() = 0;
    virtual void trimLife() = 0;
};

using IObjectPtr = std::unique_ptr<IObject>;

} // namespace game_objects
