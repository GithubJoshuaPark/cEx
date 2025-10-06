#include <stdio.h>
#include <errno.h>   // Required for the 'errno' variable
#include <string.h>  // Required for strerror()
#include "error_handlingEx.h"
#include "hello.h"   // For printLine

void error_handlingEx(void) {
    printLine("Demonstrating Error Handling with errno and perror");

    FILE *file_pointer;
    const char *non_existent_file = "this_file_does_not_exist.txt";

    printf("Attempting to open a non-existent file: '%s'\n\n", non_existent_file);

    // 1. Attempt an operation that is likely to fail.
    file_pointer = fopen(non_existent_file, "r");

    // 2. Check if the operation failed.
    //    Many standard library functions (like fopen) return NULL on failure
    //    and set a global integer variable called 'errno' to a specific error code.
    if (file_pointer == NULL) {
        // 3. Use perror() to print a user-friendly error message.
        //    perror() automatically prints the string you give it, followed by a colon,
        //    a space, and a human-readable description of the current 'errno' value.
        printf("--- Using perror() ---\n");
        perror("Error opening file");
        printf("\n");

        // 4. Alternatively, you can use strerror() to get the error string yourself.
        printf("--- Using strerror() ---\n");
        printf("Error code (errno): %d\n", errno);
        printf("Error message: %s\n", strerror(errno));

    } else {
        // This part should not be executed in this example.
        printf("File opened successfully (this should not happen).\n");
        fclose(file_pointer);
    }
}