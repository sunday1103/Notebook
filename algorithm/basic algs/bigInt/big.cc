#include <stdio.h>
#include <string.h>

/* 一个数组元素表示4个十进制位，即数组是万进制的 */
#define BIGINT_RADIX 10000
#define RADIX_LEN 4
#define MAX_LEN (200 / RADIX_LEN + 1) /* 整数的最大位数 */

char a[MAX_LEN * RADIX_LEN], b[MAX_LEN * RADIX_LEN];
int x[MAX_LEN], y[MAX_LEN], z[MAX_LEN + 1];

/**
 * @brief 打印大整数.
 * @param[in] x 大整数，用数组表示，低位在低地址
 * @param[in] n 数组x的长度
 * @return 无
 */
void bigint_print(const int x[], const int n)
{
    int i;
    int start_output = 0; /* 用于跳过前导0 */
    for (i = n - 1; i >= 0; --i)
    {
        if (start_output)
        { /* 如果多余的0已经都跳过，则输出 */
            printf("%04d", x[i]);
        }
        else if (x[i] > 0)
        {
            printf("%d", x[i]);
            start_output = 1; /* 碰到第一个非0的值，就说明多余的0已经都跳过 */
        }
    }

    if (!start_output)
        printf("0"); /* 当x全为0时 */
}

/**
 * @brief 将输入的字符串转化为大整数.
 * @param[in] s 输入的字符串
 * @param[out] x 大整数，用数组表示，低位在低地址
 * @return 无
 */
void bigint_input(const char s[], int x[])
{
    int i, j = 0;
    const int len = strlen(s);
    for (i = 0; i < MAX_LEN; i++)
        x[i] = 0;

    // for (i = len - 1; i >= 0; i--) a[j++] = s[i] - '0';
    for (i = len; i > 0; i -= RADIX_LEN)
    { /* [i-RADIX_LEN, i) */
        int temp = 0;
        int k;
        const int low = i - RADIX_LEN > 0 ? i - RADIX_LEN : 0;
        for (k = low; k < i; k++)
        {
            temp = temp * 10 + s[k] - '0';
        }

        x[j++] = temp;
    }
}

/**
 * @brief 大整数加法
 * @param[in] x x
 * @param[in] y y
 * @param[out] z z=x+y
 * @return 无
 */
void bigint_add(const int x[], const int y[], int z[])
{
    int i;
    for (i = 0; i < MAX_LEN + 1; i++)
        z[i] = 0;

    for (i = 0; i < MAX_LEN; i++)
    { /* 逐位相加 */
        z[i] += x[i] + y[i];
        if (z[i] >= BIGINT_RADIX)
        { /* 看是否要进位 */
            z[i] -= BIGINT_RADIX;
            z[i + 1]++; /* 进位 */
        }
    }
}

int main()
{
    scanf("%s%s", a, b);

    bigint_input(a, x);
    bigint_input(b, y);

    bigint_add(x, y, z);
    bigint_print(z, MAX_LEN + 1);
    printf("\n");
    return 0;
}
