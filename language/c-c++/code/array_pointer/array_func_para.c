#include "stdio.h"

int func(int *a)
{
    printf("----\n");
    printf("&a =%p \n", &a);
    printf("a =%p \n----\n", a);
    return 0;
}

int main()
{
    int a[10] = {1, 2};
    int b = 10;
    int *c = (int *)a;
    printf("&a =%p \n", &a);
    printf("a =%p \n", a);
    printf("&b =%p \n", &b);
    printf("c =%p \n", c);
    func(a);
    func(c);
    return 0;
}