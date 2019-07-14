#include <gtest/gtest.h>

extern int add(int a, int b);

TEST(testCase, test0)
{
    EXPECT_EQ(add(2, 3), 5);
}

TEST(testCase, test1)
{
    EXPECT_EQ(add(2, 2), 4);
}

TEST(testCaseAnother, test1)
{
    EXPECT_EQ(add(-2, 2), 0);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}