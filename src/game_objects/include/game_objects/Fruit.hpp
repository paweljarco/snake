#pragma once

#include "game_objects/IObject.hpp"

#include <memory>

#include "board/Coordinates.hpp"

namespace game_objects
{

class Fruit : public IObject
{
public:
    static std::unique_ptr<Fruit> create(board::Coordinates coords);
    Fruit(board::Coordinates& coords);
    board::Coordinates getPosition() override;
    bool isAlive() override;
    void trimLife() override;


private:
    const board::Coordinates position_;
    unsigned int lifeSpan_;
};

} // namespace game_objectse
