#include <stdio.h>
#include <stdlib.h>
#include <gtest/gtest.h>

#define M 3
#define N 2

int cmp(const void *a, const void *b)
{
    int *p1 = (int*)a;
    int *p2 = (int*)b;
    for (int i = 0; i < N; ++i) {
        if (p1[i] != p2[i]) {
            return p2[i] - p1[i];
        }
    }

    return 0;
}

void mySort(int (*array)[N])
{
    qsort(array, M, sizeof(int) * N, cmp);
}


TEST(testCase, test0)
{
    int array[M][N] = {{1, 4}, {3, 2}, {3, 3}};

    mySort(array);

    EXPECT_EQ(array[0][0], 3);
    EXPECT_EQ(array[0][1], 3);
}