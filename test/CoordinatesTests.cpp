#include "board/Coordinates.hpp"

#include <gtest/gtest.h>

struct CoordinatesTests : public ::testing::Test
{
    void SetUp() override
    {
        sut_ = std::make_unique<board::Coordinates>(100,100);
    }

    std::unique_ptr<board::Coordinates> sut_;
};

TEST_F(CoordinatesTests, ShouldAdd20ToXCoord)
{
    sut_->increaseX(20);
    int expectedXValue = 120;
    EXPECT_EQ(sut_->getX(), expectedXValue);
}
