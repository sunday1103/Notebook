```from gtest primer```

# 基本概念
一个测试程序的框架：
```
test program
    -test case 1
        -test1
            -ASSERT_*
            -EXPECT_*
        -test2
    -test case 2
        -test1
        -test3
    -test case 3
        -test4
```
1. 一个测试程序包含若干个测试套（test case）；
2. 一个测试套包含若干个测试用例（test）；
3. 一个测试用例包含若干个断言（assertion）。

下面是测试add程序的测试程序：
```C++
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
```

## 断言（assertion）
assertion包含两种断言：
- ASSERT_*
- EXPECT_*

参见：
https://github.com/google/googletest/blob/master/googletest/docs/Primer.md#assertions

`EXPECT_EQ(add(2, 3), 5);`就是一个断言。

## 测试用例（test）
测试用例和函数类似，由语句和assertion组成。


## 测试套（test case）
若干个功能类似的测试用例组成一个测试套。

```C++
TEST(testCase, test0)
{
    EXPECT_EQ(add(2, 3), 5);
}
```
就是一个测试用例，这个用例属于`testCase`这个测试套，名字叫test0。

## 测试固定装置（test fixtures）
如果想若干个测试用例共用一套测试配置，就可以使用测试固定装置，其实也就是派生于`::testing::Test`的类。

参见：
https://github.com/google/googletest/blob/master/googletest/docs/Primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests

# 例子

https://github.com/sunday1103/Notebook/tree/master/library/gtest/proj

```C++
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

```

运行结果：
```shell
huangyang@huangyang-desktop:~/Notebook$ cd library/gtest/proj/
huangyang@huangyang-desktop:~/Notebook/library/gtest/proj$ make
g++ *.cc -lgtest -lpthread
huangyang@huangyang-desktop:~/Notebook/library/gtest/proj$ ./a.out
[==========] Running 6 tests from 3 test cases.
[----------] Global test environment set-up.
[----------] 2 tests from testCase
[ RUN      ] testCase.test0
[       OK ] testCase.test0 (0 ms)
[ RUN      ] testCase.test1
[       OK ] testCase.test1 (0 ms)
[----------] 2 tests from testCase (0 ms total)

[----------] 1 test from testCaseAnother
[ RUN      ] testCaseAnother.test1
[       OK ] testCaseAnother.test1 (0 ms)
[----------] 1 test from testCaseAnother (0 ms total)

[----------] 3 tests from addTest
[ RUN      ] addTest.test0
enter SetUp
a is: 11
enter TearDown
a is: 11

[       OK ] addTest.test0 (0 ms)
[ RUN      ] addTest.test1
enter SetUp
a is: 11
enter TearDown
a is: 11

[       OK ] addTest.test1 (0 ms)
[ RUN      ] addTest.test2
enter SetUp
a is: 11
enter TearDown
a is: 11

[       OK ] addTest.test2 (0 ms)
[----------] 3 tests from addTest (0 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 3 test cases ran. (0 ms total)
[  PASSED  ] 6 tests.
huangyang@huangyang-desktop:~/Notebook/library/gtest/proj$
```