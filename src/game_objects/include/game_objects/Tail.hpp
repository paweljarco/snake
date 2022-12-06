#pragma once

#include "IObject.hpp"

#include "board/Coordinates.hpp"

namespace game_objects
{

class Tail : public IObject
{
public:
    static std::unique_ptr<Tail> create(const board::Coordinates& coords, unsigned int lifeSpan);
    Tail(const board::Coordinates& coords, unsigned int lifeSpan);
    ~Tail() = default;
    board::Coordinates& getPosition() override;
    bool isAlive() override;
    void trimLife() override;

private:
    board::Coordinates position_;
    unsigned int lifeSpan_;
};

} // namespace game_objects
