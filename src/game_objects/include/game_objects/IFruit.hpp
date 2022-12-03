#pragma once

namespace board
{
class Coordinates;
} // namespace board

namespace game_objects
{
class IFruit
{
public:
    virtual ~IFruit() = default;
    virtual board::Coordinates& getPosition() = 0;
};

} // namespace game_objects
