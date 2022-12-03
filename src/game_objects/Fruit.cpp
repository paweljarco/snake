#include "game_objects/Fruit.hpp"

namespace game_objects
{
Fruit::Fruit(const board::Coordinates& coords)
    : position_{coords}
{}

board::Coordinates& Fruit::getPosition(){
    return position_;
}

} // namespace game_objects
