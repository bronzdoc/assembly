#include <stdio.h>

void function();

int
main(int argc, char* argv[])
{
    static int my_static = 999;
    int i;
    for (i = 0; i < 10; i++) {
        printf("main static: %d\n", my_static);
        function();
    }

    return 0;
}

void
function()
{
    static int my_static = 0;
    int my_non_static = 0;

    printf("static: %d\n", my_static);
    printf("not static: %d\n", my_non_static);

    my_static++;
    my_non_static++;
}
