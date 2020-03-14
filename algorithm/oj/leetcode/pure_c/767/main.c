#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return ((int *)b)[0] - ((int *)a)[0];
}

void insertChar(char *result, int size, char c, int num)
{
    char *result1 = (int *)malloc(size);
    memset(result1, 0, size);
    int len = 0;
    int i;
    for (i = 0; i < num; ++i) {
        result1[len] = c;
        result1[len+1] = result[i];
        len += 2;
    }

    for (int j = i; j < strlen(result); ++j) {
        result1[len] = result[j];
        len++;
    }
    memset(result, 0, size);
    memcpy(result, result1, size);
}

char * reorganizeString(char * S){
    char *s = S;
    // 26个字母，每个字母：【计数，字母】
    int chars[26][2] = {0};
    for (int i = 0; i < 26; ++i) {
        chars[i][1] = 'a' + i;
    }
    while (*s != '\0') {
        chars[*s - 'a'][0] ++;
        s++;
    }

    char *result = (char *)malloc(strlen(S) + 1);
    memset(result, 0, strlen(S) + 1);

    // 对计数进行排序
    qsort(chars, 26, sizeof(int) * 2, cmp);

    for (int i = 0; i < chars[0][0] - 1; ++i) {
        int len = strlen(result);
        result[len] = chars[0][1];
        int findK = -1;
        for (int k = 0 + 1; k < 26; ++k) {
            if (chars[k][0] != 0) {
                findK = k;
                break;
            }
        }
        if (findK == -1) {
            return "\0";
        }
        result[len + 1] = chars[findK][1];
        chars[findK][0]--;
    }
    int len = strlen(result);
    result[len] = chars[0][1];
    len++;

    for (int j = 1; j < 26; ++j) {
        if (chars[j][0] != 0) {
            insertChar(result, strlen(S) + 1, chars[j][1], chars[j][0]);
        }
    }

    return result;
}

int main() {
    char *r = reorganizeString("bfrbs");
    for (int i = 0; i < strlen(r); ++i) {
        if (r[i] == r[i+1]) {
            break;
        }
    }
    return 0;
}
