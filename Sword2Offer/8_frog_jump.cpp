#include "gtest/gtest.h"

int FrogJump(int number)
{
    if (number > 2)
    {
        return FrogJump(number - 2) + FrogJump(number - 1);
    }
    else if (number == 1)
    {
        return 1;
    }
    else if (number == 2)
    {
        return 2;
    }
    return 0;
}

int FrogJumpOpt(int number)
{
    int pre1, pre2;
    if (number <= 0)
    {
        return 0;
    }
    else if (number == 1)
    {
        return 1;
    }
    else if (number == 2)
    {
        return 2;
    }

    pre1 = 2;
    pre2 = 1;
    int result;
    for (int i = 3; i <= number; i++)
    {
        result = pre1 + pre2;
        pre2 = pre1;
        pre1 = result;
    }

    return result;
}


TEST(FrogJumpTest, FrogJump)
{
    EXPECT_EQ(FrogJump(-1), 0);
    EXPECT_EQ(FrogJump(0), 0);
    EXPECT_EQ(FrogJump(1), 1);
    EXPECT_EQ(FrogJump(2), 2);
    EXPECT_EQ(FrogJump(3), 3);
    EXPECT_EQ(FrogJump(4), 5);
    EXPECT_EQ(FrogJump(5), 8);
}

TEST(FrogJumpOptTest, FrogJumpOpt)
{
    EXPECT_EQ(FrogJumpOpt(-1), 0);
    EXPECT_EQ(FrogJumpOpt(0), 0);
    EXPECT_EQ(FrogJumpOpt(1), 1);
    EXPECT_EQ(FrogJumpOpt(2), 2);
    EXPECT_EQ(FrogJumpOpt(3), 3);
    EXPECT_EQ(FrogJumpOpt(4), 5);
    EXPECT_EQ(FrogJumpOpt(5), 8);
}