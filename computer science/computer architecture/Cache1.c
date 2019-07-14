#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main(int argc, char **argv)
{
    int array[SIZE][SIZE] = {0};
    int i,j;

#if 1
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            array[i][j] = i + j;
        }
    }
#else
    for (j = 0; j < SIZE; ++j) {
        for (i = 0; i < SIZE; ++i) {
            array[i][j] = i + j;
        }
    }
#endif

    return 0;
}