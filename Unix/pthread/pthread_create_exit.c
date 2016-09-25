#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thr_fn1(void *arg)
{
    printf("Thread 1 returning.\n");
    return ((void *)1);
}

void *thr_fun2(void *arg)
{
    printf("thread 2 exiting.\n");
    pthread_exit((void *)2);
}

int main(int argc, char *argv[])
{
    int rtn;
    pthread_t tid1, tid2;
    void *tret;

    rtn = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (rtn != 0)
    {
        printf("Can't create thread 1:%s\n", strerror(rtn));
        exit(1);
    }

    rtn = pthread_create(&tid2, NULL, thr_fun2, NULL);
    if (rtn != 0)
    {
        printf("Can't create thread 2:%s\n", strerror(rtn));
        exit(1);
    }

    rtn = pthread_join(tid1, &tret);
    if (rtn != 0)
    {
        printf("Can't join with thread 1:%s\n", strerror(rtn));
        exit(1);
    }
    printf("Thread 1 exit code:%d\n", (int)tret);

    rtn = pthread_join(tid2, &tret);
    if (rtn != 0)
    {
        printf("Can't join with thread 2:%s\n", strerror(rtn));
        exit(1);
    }
    printf("Thread 2 exit code:%d\n", (int)tret);

    exit(0);
}