## Linux下使用Google test

### 安装Google test

```shell
git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cmake ..
make
sudu make install
```

以上命令会将gtest编译好，并将动态链接库放在`/usr/local/lib` 目录下：

```shell
huangyang@ubuntu:/usr/local/lib$ ls
libgmock.a       libgtest.a       pkgconfig  python3.5
libgmock_main.a  libgtest_main.a  python2.7
```

如上所示，四个.a文件是gtest的动态链接库，在编写gtest的时候只需要链接这些文件就可以使用gtest。

### 使用gtest

1. add程序

   **add.cc**

   ```c++
   #include <iostream>

   int add(int a, int b)
   {
       return a + b;
   }

   //int main()
   //{
   //    std::cout << add(3, 10);
   //}
   ```

2. 为add程序编写单元测试用例

   **testAdd.cc** 

   ```
   #include <gtest/gtest.h>

   extern int add(int a, int b);

   TEST(testCase, test0)
   {
       EXPECT_EQ(add(2, 3), 5);
   }

   int main(int argc, char **argv)
   {
   	testing::InitGoogleTest(&argc, argv);
   	return RUN_ALL_TESTS();
   }
   ```

3. 编译和链接程序

   ```shell
   huangyang@ubuntu:~/code$ g++ add.cc testAdd.cc -lgtest -lpthread
   huangyang@ubuntu:~/code$ ./a.out
   [==========] Running 1 test from 1 test case.
   [----------] Global test environment set-up.
   [----------] 1 test from testCase
   [ RUN      ] testCase.test0
   [       OK ] testCase.test0 (0 ms)
   [----------] 1 test from testCase (0 ms total)

   [----------] Global test environment tear-down
   [==========] 1 test from 1 test case ran. (0 ms total)
   [  PASSED  ] 1 test.
   ```

   使用

   `g++ add.cc testAdd.cc -lgtest -lpthread`

   编译和链接单元测试用例。

   -lgtest 是链接 libgtest.a库，另外也需要链接pthread。

   可以看到gtest单元测试用例正常的运行起来。

4. gtest_main.a有什么用？

   > But maybe you think that writing all those main() functions is too much work? We agree with you completely and that's why Google Test provides a basic implementation of main(). If it fits your needs, then just link your test with gtest_main library and you are good to go.

   可以不用写自己的main函数，链接 `libgtest_main.a`  就可以了。

   **testAdd.cc** 

   ```
   #include <gtest/gtest.h>

   extern int add(int a, int b);

   TEST(testCase, test0)
   {
       EXPECT_EQ(add(2, 3), 5);
   }
   ```

   可以不写main函数。

   编译命令为：

   `g++ add.cc testAdd.cc -lgtest -lgtest_main -lpthread`

   将libgtest_main.a链接进入程序。