#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"

volatile int counter = 0; 
int loops;

void *worker(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
	counter++;
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) { 
	fprintf(stderr, "usage: threads <loops>\n"); 
	exit(1); 
    } 
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    Pthread_create(&p1, NULL, worker, NULL); 
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("Final value   : %d\n", counter);
    return 0;
}

// bash: gcc -o thread threads.c -pthread

// pthread 库不是 Linux 系统默认的库，连接时需要使用静态库 libpthread.a
//所以在使用  pthread_create()创建线程，以及调用 pthread_atfork()函数建立fork处理程序时，需要链接该库。
//-pthread或者-pthreads的编译选项是用于在编译时增加多线程的支持。
//编译选项中指定 -pthread 会附加一个宏定义 -D_REENTRANT，该宏会导致 libc 头文件选择那些thread-safe的实现。
//链接选项中指定 -pthread 则同 -lpthread 一样，只表示链接 POSIX thread 库。
//由于 libc 用于适应 thread-safe 的宏定义可能变化，因此在编译和链接时都使用 -pthread 选项而不是传统的 -lpthread 能够保持向后兼容，并提高命令行的一致性。
//目前gcc 4.5.2中已经没有了关于 -lpthread的介绍了。所以以后的多线程编译应该用-pthread，而不是-lpthread。