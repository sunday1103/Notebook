#include <stdio.h>
//long long p[10] = {1,2,3,4,5,6,7,8,9,10};
extern long long *p;
int main()
{
    for (size_t i = 0; i < 10; i++) {
       printf("%d, ", p[i]);
    }
    return 0;
}