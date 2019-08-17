/*
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <stdlib.h>
#include <stdio.h>

int compare(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int find(int* nums, int numsSize, int v, int loc)
{
    for (size_t i = 0; i < numsSize; i++)
    {
        if (i == loc)
        {
            continue;
        }
        
        if (nums[i] == v)
        {
            return i;
        }
    }

    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *numsbak = (int*)malloc(sizeof(int) * numsSize);
    memcpy(numsbak, nums, sizeof(int) * numsSize);

    qsort(nums, numsSize, sizeof(int), (int (*)(const void* p1, const void* p2))compare);
    int i = 0;
    int j = numsSize - 1;
    int *p = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;

    while (i != j) {
        if(nums[i] + nums[j] == target) {
            p[0] = find(numsbak, numsSize, nums[i], -1);
            p[1] = find(numsbak, numsSize, nums[j], p[0]);
            break;
        }

        if (nums[i] + nums[j] > target)
        {
            j--;
        }
        
        if (nums[i] + nums[j] < target)
        {
            i++;
        }
    }
    free(numsbak);
    if (p[0] >= p[1])
    {
        int temp = p[1];
        p[1] = p[0];
        p[0] = temp;
    }
    
    return p;
}

int main()
{
    int nums[3] = {3,2,3};
    int returnSize;
    int *p = twoSum(nums, 3, 6, &returnSize);
    printf("%d, %d\n", p[0], p[1]);
    free(p);
}