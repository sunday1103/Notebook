#include "stdio.h"

#define OM_LOG(str, ...) printf(str, ##__VA_ARGS__)


int main()
{
    int a = 10;
    int b = 20;
    printf("%s, a=%d, b=%d\n", __FUNCTION__, a, b);
    OM_LOG("%s, a=%d, b=%d\n",__FUNCTION__, a, b);
    OM_LOG("just str\n");
    return 0;
}