#include "game/Game.hpp"

#include <gtest/gtest.h>

#include "game_objects/Fruit.hpp"
#include "game_objects/Snake.hpp"

struct GameTests : public ::testing::Test
{
    void SetUp() override
    {
        sut_ = std::make_unique<game::Game>();
        sut_->newGame();
    }

    std::unique_ptr<game::IGame> sut_;
};

TEST_F(GameTests, ShouldReturnTrueWhenSnakeIsNotOverTail)
{
    EXPECT_TRUE(sut_->isRunning());
}

TEST_F(GameTests, ShouldBiteHisTailAfterTurningRight4TimeInRow)
{
    sut_->move();
    sut_->move();
    sut_->move();
    sut_->move();
    EXPECT_FALSE(sut_->isRunning());
}

TEST_F(GameTests, ShouldReturnSize5After1Move)
{
    sut_->move();
    auto expectedSize = 5;
    EXPECT_EQ(sut_->getTails().size(), expectedSize);
}
