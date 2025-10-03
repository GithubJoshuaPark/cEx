#include <stdio.h>
#include "arraysEx.h"
#include "hello.h" // For printLine

void arraysEx(void) {
    printLine("Demonstrating Arrays");

    // 1. Declare and initialize an array of 5 integers.
    int grades[5] = {85, 92, 78, 95, 88};

    // In C, the name of an array is essentially a pointer to its first element.
    printf("The memory address of the start of the array 'grades' is: %p\n", (void *)grades);
    printf("The memory address of the first element '&grades[0]' is: %p\n\n", (void *)&grades[0]);

    // 2. Calculate the number of elements in the array.
    // This is a common and safe way to get the length of an array.
    int num_grades = sizeof(grades) / sizeof(grades[0]);
    printf("The array has %d elements.\n\n", num_grades);

    // 3. Loop through the array to access each element.
    printf("Printing each grade with its index and memory address:\n");
    for (int i = 0; i < num_grades; i++) {
        printf("  - Index %d: Value = %d, Address = %p\n", i, grades[i], (void *)&grades[i]);
    }
    printf("\nNotice how the memory addresses are sequential!\n");
}