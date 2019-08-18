#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef int ArrayType;

typedef struct
{
    int a;
    int b;
} ArrayType;

typedef struct
{
    int maxX;
    int maxY;
    ArrayType **content;
} Array;

Array g_myA;

Array g_myA1;

void ArrayInit(int sizeX, int sizeY)
{
    g_myA.maxX = sizeX;
    g_myA.maxY = sizeY;

    g_myA.content = (ArrayType **)malloc(sizeof(ArrayType *) * sizeX);

    ArrayType *temp = (ArrayType *)malloc(sizeof(ArrayType) * sizeX * sizeY);
    if (temp == NULL)
    {
        return;
    }
    memset(temp, 0, sizeof(ArrayType) * sizeX * sizeY);

    for (size_t i = 0; i < sizeX; i++)
    {
        g_myA.content[i] = temp + i * sizeY;
    }

    printf("content: 0x%p\n", g_myA.content);
}

void ArrayInit_1(int sizeX, int sizeY)
{
    g_myA1.maxX = sizeX;
    g_myA1.maxY = sizeY;

    g_myA1.content = (ArrayType **)malloc(sizeof(ArrayType *) * sizeX);

    for (size_t i = 0; i < sizeX; i++)
    {
        g_myA1.content[i] = (ArrayType *)malloc(sizeof(ArrayType) * sizeY);
    }
}

int main()
{
    int a = 3;
    int b = 4;
    ArrayInit(a, b);
    ArrayInit_1(a, b);
    return 0;
}
