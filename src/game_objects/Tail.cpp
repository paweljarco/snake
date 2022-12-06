#include "game_objects/Tail.hpp"

namespace game_objects
{
std::unique_ptr<Tail> Tail::create(const board::Coordinates& coords, unsigned int lifeSpan)
{
    return std::make_unique<Tail>(coords, lifeSpan);
}

Tail::Tail(const board::Coordinates& coords, unsigned int lifeSpan)
    : position_(coords)
    , lifeSpan_(lifeSpan)
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
