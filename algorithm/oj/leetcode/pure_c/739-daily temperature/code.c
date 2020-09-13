#include "stdio.h"
#include "stdlib.h"

#define MAX_NUM 20
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *dailyTemperatures(int *T, int TSize, int *returnSize)
{
    *returnSize = TSize;
    int *returnArray = (int *)malloc(TSize * sizeof(int));
    if (returnArray == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    // [0] 元素值，[1] 元素位置
    int stack[MAX_NUM][2] = {{T[0], 0}};
    int top = 1;

    for (int i = 1; i < TSize; i++)
    {
        for (int j = top - 1; j >= 0; j--)
        {
            if (stack[j][0] >= T[i])
            {
                break;
            }

            returnArray[stack[j][1]] = i - stack[j][1];
            top = top - 1;
        }

        stack[top][0] = T[i];
        stack[top][1] = i;
        top = top + 1;
    }

    for (int i = 0; i < top; i++)
    {
        returnArray[stack[i][1]] = 0;
    }
    
    
    return returnArray;
}


int main()
{
    int TSize = 8;
    int *T = (int*)malloc(TSize*sizeof(int));
    int T1[8] = {73, 74, 75, 71, 69, 72, 76, 31};
    for (size_t i = 0; i < TSize; i++)
    {
        T[i] = T1[i];
    }
    
    int rSize;
    dailyTemperatures(T, TSize, &rSize);

    return 0;
}