#include "game_objects/Fruit.hpp"

namespace game_objects
{
Fruit::Fruit(const board::Coordinates& coords)
    : position_{coords}
{}

board::Coordinates Fruit::getPosition(){
    return position_;
}

bool Fruit::isAlive(){
    return lifeSpan_ > 0;
}

void Fruit::trimLife(){
    lifeSpan_--;
}

} // namespace game_objects
