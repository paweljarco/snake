#include "game_objects/Fruit.hpp"

namespace game_objects
{
Fruit::Fruit(board::Coordinates& coords)
    : position_{coords}
    , lifeSpan_{20}
{}

std::unique_ptr<Fruit> create(board::Coordinates coords)
{
    return std::make_unique<Fruit>(coords);
}

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
