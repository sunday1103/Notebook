#include <stdio.h>
char buffer[6] = {0};

char *mystring()
{
    const char *s = "Hello world";
    for (int i = 0; i < (sizeof(buffer) - 1); i++)
    {
        buffer[i] = *(s + i);
    }
    return buffer;
}
int main(int args, char **argv)
{
    printf("%s\n", mystring());
    if (0 == '\0')
    {
        printf("YES\n");
    }

    return 0;
}
