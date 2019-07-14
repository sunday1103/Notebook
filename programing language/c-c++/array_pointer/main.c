#include <stdio.h>

int main()
{
    char a[] = "abcdefg";
    char *p = "abcdefg";
    printf("a[3] is %c, p[3] is %c.\n", a[3], p[3]);
    printf("*(a+3) is %c, *(p+3) is %c.\n", *(a + 3), *(p + 3));
    // what the difference of above a and p,
    // a[3] use the address of a, its value is known
    // p[3] use the value of p, its value must use extra instrument to obtain it.

    //p[2] = 'f'; //fault, it can't be changed.
}