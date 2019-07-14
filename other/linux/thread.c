#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

pthread_t ntid;

void printids(const char *s)
{
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    printf("%s pid %lu tid %lu \n", s, (unsigned long)pid, (unsigned long)tid);
}

void *thr_fn(void *arg)
{
    printids("new thread: ");
    return (void *)0;
}

int main()
{
    int err;
    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if (err != 0)
        exit(-1);
    printids("main thread: ");
    sleep(1);
    exit(0);
}
