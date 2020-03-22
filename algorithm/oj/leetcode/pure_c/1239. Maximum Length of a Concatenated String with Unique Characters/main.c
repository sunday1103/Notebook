#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD_LEN 26

int isStrInMap(char *s, int *map)
{
    for (int i = 0; i < strlen(s); ++i) {
        if (map[s[i] - 'a']) {
            return 1;
        }
    }

    return 0;
}

int isStrValid(char *s)
{
    int usedMap[WORD_LEN] = {0};
    for (int i = 0; i < strlen((s)); ++i) {
        if (usedMap[s[i] - 'a']) {
            return 0;
        }
        usedMap[s[i] - 'a'] = 1;
    }
    return 1;
}

int g_maxLen = 0;

void maxLenWithMap(char ** arr, int arrSize, int *map, int curSize, int curIndex)
{
    if (curIndex == arrSize) {
        return;
    }

    // 未选中的处理
    maxLenWithMap(arr, arrSize, map, curSize, curIndex + 1);

    // 选中的处理
    // 只有和前面的不重复，才进行后续动作
    if (isStrValid(arr[curIndex]) && isStrInMap(arr[curIndex], map) == 0) {
        int len = curSize;
        int usedMap[WORD_LEN] = {0};
        memcpy(usedMap, map, sizeof(int) * WORD_LEN);
        for (int i = 0; i < strlen(arr[curIndex]); ++i) {
            if (usedMap[arr[curIndex][i] - 'a'] == 0) {
                usedMap[arr[curIndex][i] - 'a'] = 1;
                len++;
            }
        }
        if (len > g_maxLen) {
            g_maxLen = len;
        }
        maxLenWithMap(arr, arrSize, usedMap, len, curIndex + 1);
    }
}

int maxLength(char ** arr, int arrSize)
{
    int usedMap[WORD_LEN] = {0};
    g_maxLen = 0;
    int curLen = 0;
    maxLenWithMap(arr, arrSize, usedMap, curLen, 0);
    return g_maxLen;
}

int main() {
    char *arr[] = {"cha","r","act","ers"};
    maxLength(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}
