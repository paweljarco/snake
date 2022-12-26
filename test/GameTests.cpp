#include "game/Game.hpp"

#include <gtest/gtest.h>

#include "game_objects/Fruit.hpp"
#include "game_objects/Snake.hpp"

struct GameTests : public ::testing::Test
{
    void SetUp()
    {
        sut_ = std::make_unique<game::Game>();
    }

    std::unique_ptr<game::IGame> sut_;
};

TEST_F(GameTests, ShouldReturnTrueWhenSnakeIsNotOverTail)
{
    EXPECT_TRUE(sut_->isRunning());
}

TEST_F(GameTests, ShouldBiteHisTailAfterTurningRight3TimeInRow)
{

    EXPECT_FALSE(sut_->isRunning());
}
