#include "stdlib.h"

/*
* Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
*/

int g_num = 0;

void MyFind(int *nums, int numSize, int S) {
    if (numSize == 0)
    {
        if (S == 0)
        {
            g_num++;
        }
        return;
    }

    MyFind(nums + 1, numSize - 1, S - nums[0]);
    MyFind(nums + 1, numSize - 1, S + nums[0]);
}

int findTargetSumWays(int* nums, int numsSize, int S){
    g_num = 0;
    MyFind(nums, numsSize, S);

    return g_num;
}