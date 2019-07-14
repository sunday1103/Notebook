#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    if ((pid = fork()) < 0)
    {
        printf("error in fork\n");
    }
    else if (pid == 0) // fork
    {
        printf("In child process, pid is %ld \n", (long)getpid());
        execlp("pwd", "pwd", NULL);
    }
    else
    {
        printf("In parent process, pid is %ld \n", (long)getpid());
    }
    sleep(1);
    exit(0);
}
