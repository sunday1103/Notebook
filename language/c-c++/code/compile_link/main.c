#include <stdio.h>
#include "add.h"

int main()
{
    int a = 1;
    int b = 10;
    int c = add(a, b);
    printf("c = %d\n", c);
}