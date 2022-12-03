#include <gtest/gtest.h>

#include "game_objects/Snake.hpp"

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
    EXPECT_EQ(sut_->getPosition().x, board::BEGINNING_POSITION.x);
    EXPECT_EQ(sut_->getPosition().y, board::BEGINNING_POSITION.y);
}


TEST_F(SnakeTests, MoveShouldSubstractStepFromXCoordsAtStart)
{
    sut_->move();
    EXPECT_EQ(sut_->getPosition().x, board::BEGINNING_POSITION.x - board::STEP);
    EXPECT_EQ(sut_->getPosition().y, board::BEGINNING_POSITION.y);
}

TEST_F(SnakeTests, AfterTurnRightAndMoveShouldAddStepToYCoords)
{
    sut_->turnClockwise();
    sut_->move();
    EXPECT_EQ(sut_->getPosition().x, board::BEGINNING_POSITION.x);
    EXPECT_EQ(sut_->getPosition().y, board::BEGINNING_POSITION.y + board::STEP);
}

TEST_F(SnakeTests, AfterTwiceTurnRightAndMoveShouldAddStepToXCoords)
{
    sut_->turnClockwise();
    sut_->turnClockwise();
    sut_->move();
    EXPECT_EQ(sut_->getPosition().x, board::BEGINNING_POSITION.x + board::STEP);
    EXPECT_EQ(sut_->getPosition().y, board::BEGINNING_POSITION.y);
}

TEST_F(SnakeTests, After3TimesTurnRightAndMoveShouldSubstractStepFromYCoords)
{
    sut_->turnClockwise();
    sut_->turnClockwise();
    sut_->turnClockwise();
    sut_->move();
    EXPECT_EQ(sut_->getPosition().x, board::BEGINNING_POSITION.x);
    EXPECT_EQ(sut_->getPosition().y, board::BEGINNING_POSITION.y - board::STEP);
}

TEST_F(SnakeTests, AfterTurnLeftAndMoveShouldSubstractStepFromYCoords)
{
    sut_->turnCounterClockwise();
    sut_->move();
    EXPECT_EQ(sut_->getPosition().x, board::BEGINNING_POSITION.x);
    EXPECT_EQ(sut_->getPosition().y, board::BEGINNING_POSITION.y - board::STEP);
}
