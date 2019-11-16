#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "calc.h"

using ::testing::AtLeast; 

class CalcMock: public Calc {
public:
    MOCK_METHOD(int, multi, (int, int), ());
    CalcMock(int a): Calc(a) {}
};

TEST(testMock, test1)
{
    CalcMock calcMock0(3);
    EXPECT_CALL(calcMock0, multi) 
      .Times(AtLeast(1));

    EXPECT_EQ(calcMock0.add(2, 2), 4);
    EXPECT_EQ(calcMock0.specficMulti(1,2), 2);
    /*
    testAdd_mock.cc:17: Failure
    Actual function call count doesn't match EXPECT_CALL(calcMock0, multi)...
         Expected: to be called at least once
           Actual: never called - unsatisfied and active
    calcMock0是mock对象，对该对象进行调用，如果某个方法被mock，那么就不会真正的被执行。
    */
}