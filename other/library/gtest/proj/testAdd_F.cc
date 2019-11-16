#include <gtest/gtest.h>
#include <iostream>
#include "calc.h"

class addTest : public ::testing::Test {
 protected:
    addTest(): calc0(2)
    {
    }

    virtual void SetUp() 
    {
        std::cout << "enter SetUp" << std::endl;
    }

    virtual void TearDown() 
    {
        std::cout << "enter TearDown" << std::endl;
        std::cout << std::endl;
    }

    Calc calc0;
};

TEST_F(addTest, test0)
{
    EXPECT_EQ(calc0.add(2, 3), 5);
}

TEST_F(addTest, test1)
{
    EXPECT_EQ(calc0.add(2, 2), 4);
}

TEST_F(addTest, test2)
{
    EXPECT_EQ(calc0.add(2, 22), 24);
}



