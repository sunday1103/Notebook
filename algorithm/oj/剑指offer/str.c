#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "hello";
    char str2[] = "hello";

    const char *str3 = "hello";
    const char *str4 = "hello";

    printf("compare1: %d \n", str1 == str2);
    printf("compare2: %d \n", str3 == str3);

    printf("str3[1] is %c \n", str3[1]);
    //str3[1] = 'r';
    printf("str3[1] is %c \n", str3[1]);
    return 0;
}
