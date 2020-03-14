#include <stdio.h>
#include <stdlib.h>
#include <gtest/gtest.h>

void array_1(int *a, int size)
{
    // a指向数组的第一个元素
    printf("1D addr in func: %p\n", a);
}

TEST(testcase, arrayArg1d)
{
    int array[3] = {1,2,3};
    printf("1D array addr %p\n", array);
    array_1(array, 3);
}

void array_2(int (*a)[2], int size)
{
    // a指向数组的第一个元素
    printf("2D addr in func: %p\n", a);
    printf("value %d %d\n", *(*a), a[1][1]);
}

TEST(testcase, arrayArg2d)
{
    int array[3][2] = {{1,2} ,{2,4} ,{3,1}};
    printf("2D array addr %p\n", array);
    array_2(array, 3);
}

void array_point(int **a, int size, int size1)
{
    // a指向数组的第一个元素
    printf("first value %p %d\n", *a, *(*a));
}

TEST(testcase, arrayArg2dPoint)
{
    int **array = (int **)malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; ++i) {
        array[i] = (int *)malloc(sizeof(int) * 2);
    }

    array[0][0] = 1;
    array[0][1] = 2;
    array[1][0] = 2;
    array[1][1] = 4;
    array[2][0] = 3;
    array[2][1] = 1;

    array_point(array, 3, 2);
}

typedef struct {
    int x;
    int y;
}Node;

int cmpStruct(const void *a, const void *b)
{
    int distance1 = ((Node *)a)->x * ((Node *)a)->x + ((Node *)a)->y * ((Node *)a)->y;
    int distance2 = ((Node *)b)->x * ((Node *)b)->x + ((Node *)b)->y * ((Node *)b)->y;

    return distance1 - distance2;
}

void structSort(Node *array, int size)
{
    qsort(array, size, sizeof(Node), cmpStruct);
}

TEST(testCase, structSort0)
{
    Node array[3] = {{3,2}, {1,4}, {2,2}};
    structSort(array, sizeof(array) / sizeof(Node));

    EXPECT_EQ(array[0].x, 2);
}


#define M 3
#define N 2

int cmp(const void *a, const void *b)
{
    for (int i = 0; i < N; ++i) {
        if (((int *)a)[i] != ((int *)b)[i]) {
            return ((int *)b)[i] - ((int *)a)[i];
        }
    }

    return 0;
}

void mySort(int (*array)[N], int size)
{
    qsort(array, size, sizeof(int) * N, cmp);
}


TEST(testCase, test0)
{
    int array[M][N] = {{1, 4}, {3, 2}, {3, 3}};

    mySort(array, M);

    EXPECT_EQ(array[0][0], 3);
    EXPECT_EQ(array[0][1], 3);
}


int cmp2DPoint(const void *a, const void *b)
{
    for (int i = 0; i < 2; ++i) {
        if ((*(int **)a)[i] != (*(int **)b)[i]) {
            return (*(int **)b)[i] - (*(int **)a)[i];
        }
    }

    return 0;
}

void mysort2DPoint(int **array, int size, int size1)
{
    qsort(array, size, sizeof(int *), cmp2DPoint);
}

TEST(testcase, testSort2DPoint)
{
    int **array = (int **)malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; ++i) {
        array[i] = (int *)malloc(sizeof(int) * 2);
    }

    array[0][0] = 1;
    array[0][1] = 2;
    array[1][0] = 2;
    array[1][1] = 4;
    array[2][0] = 3;
    array[2][1] = 1;

    mysort2DPoint(array, 3, 2);

    EXPECT_EQ(array[0][0], 3);
    EXPECT_EQ(array[0][1], 1);
}