#include "stdlib.h"
#include "stdio.h"

typedef struct {
    int a;
    int b;
} Ele;

void printArray(Ele *a, int len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("[%d %d] ", a[i].a, a[i].b);
    }
    printf("\n");
}

/*
qsort 比较函数，
*/
int myCmp(const void *a, const void *b)
{
    Ele *a1 = (Ele*)a;
    Ele *b1 = (Ele*)b;

    if (a1->a < b1->a)
    {
        return -1;
    }

    if (a1->a == b1->a)
    {
        return a1->b - b1->b;
    }
    
    return 1;
}

int main()
{
    Ele array[10];
    for (size_t i = 0; i < 10; i++)
    {
        array[i].a = i * 29 % 4;
        array[i].b = i * i * 34 / 7;
    }

    printArray(array, 10);
    qsort(array, 10, sizeof(Ele), myCmp);
    printArray(array, 10);

    return 0;
}


// -------------- from cplusplus.com
/* qsort example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */

int values[] = { 40, 10, 100, 90, 20, 25 };

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main ()
{
  int n;
  qsort (values, 6, sizeof(int), compare);
  for (n=0; n<6; n++)
     printf ("%d ",values[n]);
  return 0;
}