#include "game_objects/Tail.hpp"

namespace game_objects
{
Tail::Tail(const board::Coordinates& coords, unsigned int lifeSan)
    : position_(coords)
    , lifeSpan_(lifeSan)
{}

board::Coordinates& Tail::getPosition()
{
    return position_;
}

bool Tail::isAlive()
{
    return lifeSpan_ > END_OF_LIFE;
}

void Tail::trimLife()
{
    lifeSpan_--;
}

} // namespace game_objects
