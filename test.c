#include <stdio.h>

int
main()
{
    int i[5] = {0,1,2,3,4};
    char* x = "hello doc!\n";

    int* int_ptr;
    char* char_ptr;
    void* void_ptr;

    void_ptr = (void *) x;

    //printf("%s\n", ((char*) void_ptr));
    printf("%s\n", (char *) void_ptr);
    printf("%p\n", x);
}
