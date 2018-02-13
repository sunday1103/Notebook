#include <gtest/gtest.h>
#include <iostream>

extern int add(int a, int b);

class addTest : public ::testing::Test {
 protected:
    addTest()
    {
        a = 10;
    }

    virtual void SetUp() 
    {
        a++;
        std::cout << "enter SetUp" << std::endl;
        std::cout << "a is: "<< a << std::endl;
    }

    virtual void TearDown() 
    {
        std::cout << "enter TearDown" << std::endl;
        std::cout << "a is: "<< a << std::endl;
        std::cout << std::endl;
    }

  int a;
};

TEST_F(addTest, test0)
{
    EXPECT_EQ(add(2, 3), 5);
}

TEST_F(addTest, test1)
{
    EXPECT_EQ(add(2, 2), 4);
}

TEST_F(addTest, test2)
{
    EXPECT_EQ(add(2, 22), 24);
}



