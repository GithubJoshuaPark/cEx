#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()
#include "dynamic_2d_arrayEx.h"
#include "hello.h" // For printLine

void dynamic_2d_arrayEx(void) {
    printLine("Demonstrating Dynamic 2D Array Allocation");

    int rows = 3;
    int cols = 4;

    printf("Allocating a %d x %d 2D array dynamically.\n\n", rows, cols);

    // 1. Allocate memory for 'rows' number of integer pointers.
    //    This will be our array of rows. Each element will point to a row (an array of integers).
    int **dynamic_2d_array = (int **)malloc(rows * sizeof(int *));

    // Check if allocation for rows was successful
    if (dynamic_2d_array == NULL) {
        printf("Memory allocation failed for rows!\n");
        return;
    }

    // 2. For each row, allocate memory for 'cols' number of integers.
    //    This creates the columns for each row.
    for (int i = 0; i < rows; i++) {
        dynamic_2d_array[i] = (int *)malloc(cols * sizeof(int));
        // Check if allocation for current row was successful
        if (dynamic_2d_array[i] == NULL) {
            printf("Memory allocation failed for row %d!\n", i);
            // Clean up previously allocated rows before exiting
            for (int j = 0; j < i; j++) {
                free(dynamic_2d_array[j]);
            }
            free(dynamic_2d_array);
            return;
        }
    }

    // 3. Use the dynamically allocated 2D array.
    //    Initialize with some values and print them.
    printf("Initializing and printing the 2D array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dynamic_2d_array[i][j] = (i + 1) * 10 + j + 1; // Example value
            printf("%4d ", dynamic_2d_array[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // 4. IMPORTANT: Free the dynamically allocated memory.
    //    First, free each row (the inner arrays).
    for (int i = 0; i < rows; i++) {
        free(dynamic_2d_array[i]);
    }
    //    Then, free the array of pointers (the outer array).
    free(dynamic_2d_array);
    dynamic_2d_array = NULL; // Good practice to set pointer to NULL after freeing.

    printf("Dynamically allocated 2D array memory has been freed.\n");
}