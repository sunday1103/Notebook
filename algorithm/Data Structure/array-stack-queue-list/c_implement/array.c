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


void Process()
{
    g_myA.content[2][3].a = 100;
    g_myA.content[2][2].b = 99;

    for (size_t i = 0; i < g_myA1.maxX; i++)
    {
        for (size_t j = 0; j < g_myA1.maxY; j++)
        {
            g_myA1.content[i][j].a = i + 2 * j;
        }
    }
}

void Output()
{
    printf("%d\n", g_myA.content[0][1].a);
    printf("%d\n", g_myA.content[2][3].a);
    printf("%d\n", g_myA.content[2][2].b);
}

void PrintA()
{
    for (size_t i = 0; i < g_myA.maxX; i++)
    {
        for (size_t j = 0; j < g_myA.maxY; j++)
        {
            printf("(%d, %d), ", g_myA.content[i][j].a, g_myA.content[i][j].b);
        }
        printf("\n");
    }
}


void PrintA_1()
{
    for (size_t i = 0; i < g_myA1.maxX; i++)
    {
        for (size_t j = 0; j < g_myA1.maxY; j++)
        {
            printf("(%d, %d), ", g_myA1.content[i][j].a, g_myA1.content[i][j].b);
        }
        printf("\n");
    }
}

int main()
{
    int a = 3;
    int b = 4;
    ArrayInit(a, b);
    ArrayInit_1(a, b);
    Process();
    Output();
    return 0;
}
