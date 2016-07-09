#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

// Function to display an error message and then exit
void
fatal(char* message)
{
    char error_message[100];
    strcpy(error_message, "Fatal error: ");
    strncat(error_message, message, 83);

    perror(error_message);
    exit(-1);
}

// An error-checked malloc() wrapper
void*
ec_malloc(unsigned int size)
{
    void* ptr;
    ptr = malloc(size);
    if (ptr == NULL)
        fatal("in ec_malloc on memory allocation");

    return ptr;
}

void
usage(char* prog_name, char* filename) {
    printf("Usage: %s <data to add to %s>", prog_name, filename);
    exit(0);
}

int
main(int argc, char* argv[])
{
    int user_id;
    int fd; // file descriptor
    char* buffer;
    char* datafile;

    buffer = (char *) ec_malloc(100);
    datafile = (char *) ec_malloc(20);
    strcpy(datafile, "./notes");

    if (argc < 2) // Check if there aren't command line arguments
        usage(argv[0], datafile); // display usage message and exit

    strcpy(buffer, argv[1]); // Copy into buffer

    // Opening file
    fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND|S_IRUSR|S_IWUSR);
    if (fd == -1)
        fatal("in main() while opening file");

    user_id = getuid(); // Get real user id

    // Writing data
    if (write(fd, &user_id, 4) == -1) // Write user ID before note data
        fatal("in main() while closing file");

    write(fd, buffer, strlen(buffer))
    write(fd, "\n", 1); // Terminate line

    if (write(fd))

        fatal("in main() while closing file");


    printf("Note has been saved\n");

    free(buffer);
    free(datafile);

    return 0;
}
