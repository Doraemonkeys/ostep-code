#include <stdio.h>
#include <stdlib.h>
#include "common.h"

//bash: gcc cpu.c -o cpu && ./cpu A & ./cpu B & ./cpu C & ./cpu D &
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }
    char *str = argv[1];

    while (1)
    {
        printf("%s\n", str);
        Spin(1);
    }
    return 0;
}
