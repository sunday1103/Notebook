#include <stdio.h>
#include <string.h>

/* һ������Ԫ�ر�ʾ4��ʮ����λ��������������Ƶ� */
#define BIGINT_RADIX 10000
#define RADIX_LEN 4
#define MAX_LEN (200 / RADIX_LEN + 1) /* ���������λ�� */

char a[MAX_LEN * RADIX_LEN], b[MAX_LEN * RADIX_LEN];
int x[MAX_LEN], y[MAX_LEN], z[MAX_LEN + 1];

/**
 * @brief ��ӡ������.
 * @param[in] x ���������������ʾ����λ�ڵ͵�ַ
 * @param[in] n ����x�ĳ���
 * @return ��
 */
void bigint_print(const int x[], const int n)
{
    int i;
    int start_output = 0; /* ��������ǰ��0 */
    for (i = n - 1; i >= 0; --i)
    {
        if (start_output)
        { /* ��������0�Ѿ�������������� */
            printf("%04d", x[i]);
        }
        else if (x[i] > 0)
        {
            printf("%d", x[i]);
            start_output = 1; /* ������һ����0��ֵ����˵�������0�Ѿ������� */
        }
    }

    if (!start_output)
        printf("0"); /* ��xȫΪ0ʱ */
}

/**
 * @brief ��������ַ���ת��Ϊ������.
 * @param[in] s ������ַ���
 * @param[out] x ���������������ʾ����λ�ڵ͵�ַ
 * @return ��
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
 * @brief �������ӷ�
 * @param[in] x x
 * @param[in] y y
 * @param[out] z z=x+y
 * @return ��
 */
void bigint_add(const int x[], const int y[], int z[])
{
    int i;
    for (i = 0; i < MAX_LEN + 1; i++)
        z[i] = 0;

    for (i = 0; i < MAX_LEN; i++)
    { /* ��λ��� */
        z[i] += x[i] + y[i];
        if (z[i] >= BIGINT_RADIX)
        { /* ���Ƿ�Ҫ��λ */
            z[i] -= BIGINT_RADIX;
            z[i + 1]++; /* ��λ */
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
