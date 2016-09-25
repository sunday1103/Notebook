#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX 1000 /* the loop count */

/* function: do loop operation

 * input: NULL

 * output: counter->the counter result

 */

int do_work()

{

    int counter = 0; /* the counter */

    int i, j; /* the loop variable */

    /* accumulate the counter */

    for (i = 0; i < MAX; i++)

        for (j = 0; j < MAX; j++)

            counter++;

    /* return the counter's value */

    return counter;
}

int main()
{

    struct timeval start, end;

    int interval;

    gettimeofday(&start, NULL);

    //do_work();
    sleep(2);
    gettimeofday(&end, NULL);

    interval = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);

    printf("interval = %f ms\n", interval / 1000.0);

    int a[10000];
    gettimeofday(&start, NULL);

    for (int i = 0; i < 10000; ++i)
    {
        for (int j = 0; j < 10000; ++j)
        {
            a[j];
        }
    }

    gettimeofday(&end, NULL);

    interval = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);

    printf("interval = %f ms\n", interval / 1000.0);

    int *p = a;

    gettimeofday(&start, NULL);

    for (int i = 0; i < 10000; ++i)
    {
        for (int j = 0; j < 10000; ++j)
        {
            *(j + p);
        }
    }

    gettimeofday(&end, NULL);

    interval = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);

    printf("interval = %f ms\n", interval / 1000.0);
}