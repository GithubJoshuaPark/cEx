#include "hello.h"

/**
 * Prints a hello message to the console.
 */
void say_hello() {
    printLine("Hello from say_hello function!\n");
}

/**
 * Prints a line with dashes above and below it.
 */
void printLine(const char* line) {
    if (line != NULL) {
        // print '-'  with the provided line length times
        for (int i = 0; line[i] != '\0'; i++) {
            putchar('-');
        }
        putchar('\n');
        printf("%s\n", line);
        for (int i = 0; line[i] != '\0'; i++) {
            putchar('-');
        }
        putchar('\n');
        
    } else {
        printf("NULL line provided.\n");
    }
}
