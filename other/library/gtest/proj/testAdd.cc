#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "calc.h"

TEST(testCase, test0)
{
    Calc calc0(1);
    EXPECT_EQ(calc0.add(2, 3), 5);
}

TEST(testCase, test1)
{
    Calc calc0(1);
    EXPECT_EQ(calc0.add(2, 2), 4);
}

TEST(testCaseAnother, test1)
{
    Calc calc0(1);
    EXPECT_EQ(calc0.add(-2, 2), 0);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}