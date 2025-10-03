#include <stdio.h>
#include <stdlib.h> // Required for calloc() and realloc()
#include "dynamic_memory_allocationEx.h"
#include "hello.h" // For printLine

void dynamic_memory_allocationEx(void) {
    printLine("Demonstrating Dynamic Memory Allocation: calloc and realloc");

    int *array = NULL;
    int initial_size = 5;

    // --- Using calloc ---
    // calloc (contiguous allocation) allocates memory for an array of elements
    // and initializes them to zero. It takes two arguments: number of elements and size of each element.
    printf("--- Using calloc ---\n");
    array = (int *)calloc(initial_size, sizeof(int));

    if (array == NULL) {
        printf("Failed to allocate memory with calloc!\n");
        return;
    }

    printf("Allocated memory for %d integers with calloc. Initial values:\n", initial_size);
    for (int i = 0; i < initial_size; i++) {
        printf("  array[%d] = %d\n", i, array[i]); // Should all be 0
    }
    printf("\n");

    // --- Using realloc ---
    // realloc resizes a previously allocated memory block.
    printf("--- Using realloc ---\n");
    int new_size = 10;
    int *temp = (int *)realloc(array, new_size * sizeof(int));

    if (temp == NULL) {
        printf("Failed to reallocate memory with realloc!\n");
        free(array); // Free the original block if realloc fails
        return;
    }
    array = temp; // Point to the new (or possibly same) memory block

    printf("Resized array to hold %d integers.\n", new_size);
    // Fill the new part of the array
    for (int i = initial_size; i < new_size; i++) {
        array[i] = i * 10;
    }

    printf("Values after realloc and filling new elements:\n");
    for (int i = 0; i < new_size; i++) {
        printf("  array[%d] = %d\n", i, array[i]);
    }
    printf("\n");

    // IMPORTANT: Always free the dynamically allocated memory.
    free(array);
    array = NULL;
    printf("Memory has been freed.\n");
}