#include <stdio.h>
#include "file_ioEx.h"
#include "hello.h" // For printLine

void file_ioEx(void) {
    printLine("Demonstrating File I/O");

    FILE *file_pointer;
    const char *filename = "example.txt";
    char buffer[256];

    // --- Writing to a file ---
    printf("--- Writing to a file ---\n");

    // 1. Open the file in write mode ("w").
    // If the file doesn't exist, it will be created.
    // If it exists, its contents will be overwritten.
    file_pointer = fopen(filename, "w");

    // 2. Always check if the file was opened successfully.
    if (file_pointer == NULL) {
        perror("Error opening file for writing"); // perror prints a system error message
        return;
    }

    // 3. Write formatted text to the file, similar to printf.
    fprintf(file_pointer, "Hello, this is a test.\n");
    fprintf(file_pointer, "We are writing line %d.\n", 2);
    printf("Successfully wrote to '%s'.\n\n", filename);

    // 4. Close the file to save changes and release the resource.
    fclose(file_pointer);

    // --- Reading from a file ---
    printf("--- Reading from a file ---\n");

    // 5. Re-open the file in read mode ("r").
    file_pointer = fopen(filename, "r");
    if (file_pointer == NULL) {
        perror("Error opening file for reading");
        return;
    }

    // 6. Read the file line by line until the end is reached (fgets returns NULL).
    printf("Contents of '%s':\n", filename);
    while (fgets(buffer, sizeof(buffer), file_pointer) != NULL) {
        printf("  > %s", buffer); // Print the line read from the file
    }

    // 7. Close the file.
    fclose(file_pointer);
}