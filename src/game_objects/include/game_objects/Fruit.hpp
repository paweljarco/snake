#pragma once

#include "board/Coordinates.hpp"
#include "game_objects/IFruit.hpp"

namespace game_objects
{
class Fruit : public IFruit
{
public:
    Fruit(const board::Coordinates& coords);
    board::Coordinates& getPosition() override;

private:
    board::Coordinates position_;
};
} // namespace game_objectse
