#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()
#include "memory_managementEx.h"
#include "hello.h" // For printLine

void memory_managementEx(void) {
    printLine("Demonstrating Memory Management: Stack vs. Heap");

    // --- The Stack ---
    // Local variables are allocated on the stack.
    // Memory is automatically managed: allocated when the function is called,
    // and deallocated when the function returns.
    int stack_variable = 10;
    printf("--- Stack Memory ---\n");
    printf("Local 'stack_variable' has value: %d\n", stack_variable);
    printf("Its memory address is: %p\n", (void *)&stack_variable);
    printf("This memory is automatically freed when 'memory_managementEx' finishes.\n\n");

    // --- The Heap ---
    // The heap is a large pool of memory available for dynamic allocation.
    // You must manage it manually using malloc(), calloc(), realloc(), and free().
    int *heap_pointer = NULL;

    // 1. Allocate memory on the heap for a single integer.
    //    malloc() returns a void pointer, so we cast it to (int *).
    heap_pointer = (int *)malloc(sizeof(int));

    printf("--- Heap Memory ---\n");
    // 2. Check if allocation was successful. malloc() returns NULL on failure.
    if (heap_pointer == NULL) {
        printf("Failed to allocate memory on the heap!\n");
        return; // Exit the function if memory allocation fails.
    }
    printf("Memory for one integer allocated on the heap at address: %p\n", (void *)heap_pointer);

    // 3. Use the allocated memory.
    *heap_pointer = 20;
    printf("Value stored in heap memory: %d\n\n", *heap_pointer);

    // 4. IMPORTANT: Free the memory when you are done with it.
    //    Forgetting to free memory causes a "memory leak".
    free(heap_pointer);
    heap_pointer = NULL; // Good practice to set pointer to NULL after freeing.
    printf("Heap memory has been freed.\n");
}