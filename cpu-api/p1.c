#include <stdio.h>
#include <stdlib.h>
// C 和 C++ 程序设计语言中提供对 POSIX 操作系统 API 的访问功能的头文件的名称
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());
    //父进程获得的返回值为子进程的PID
    //子进程获得的返回值为0
    int rc = fork();
    if (rc < 0)
    {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int)getpid());
    }
    else
    {
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n",
               rc, (int)getpid());
    }
    return 0;
}
