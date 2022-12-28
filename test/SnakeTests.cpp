#include "game_objects/Snake.hpp"

#include <gtest/gtest.h>

#include "board/ConstBoardValues.hpp"


struct SnakeTests : public ::testing::Test
{
    void SetUp()
    {
        sut_ = std::make_unique<game_objects::Snake>();
    }

        std::unique_ptr<game_objects::Snake> sut_;
};


TEST_F(SnakeTests, GetPositionShouldReturnBeginingPositionAtStart)
{
    EXPECT_EQ(sut_->getPosition().x_, board::BEGINNING_POSITION.x_);
    EXPECT_EQ(sut_->getPosition().y_, board::BEGINNING_POSITION.y_);
}


TEST_F(SnakeTests, MoveShouldSubstractStepFromXCoordsAtStart)
{
    sut_->move();
    EXPECT_EQ(sut_->getPosition().x_, board::BEGINNING_POSITION.x_ - board::BOX_SIZE);
    EXPECT_EQ(sut_->getPosition().y_, board::BEGINNING_POSITION.y_);
}

