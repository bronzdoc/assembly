#include <stdio.h>
#include <unistd.h>


int
main(int argc, char* argv[])
{
    printf("Real user id: %d\n", getuid());
    printf("Effective user id: %d\n", geteuid());
    return 0;
}

