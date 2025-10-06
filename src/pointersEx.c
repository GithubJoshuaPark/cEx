#include <stdio.h>
#include "pointersEx.h"
#include "hello.h" // For printLine

void pointersEx(void) {
    printLine("Demonstrating Pointers");

    // 1. A regular integer variable.
    int number = 42;

    // 2. A pointer variable. 
    // The '*' indicates this is a pointer. 
    // 'int *' means "a pointer that will store the address of an integer".
    int *p_number = NULL; // It's good practice to initialize pointers to NULL.

    // 3. The '&' (address-of) operator gets the memory address of 'number'.
    // We assign this address to our pointer.
    p_number = &number;

    printf("The value of the variable 'number' is: %d\n", number);
    printf("The memory address of 'number' is: %p\n", (void *)&number);
    printf("The value of the pointer 'p_number' (which is the address it holds) is: %p\n", (void *)p_number);
    
    // 4. The '*' (dereference) operator gets the value AT the address the pointer is pointing to.
    printf("The value at the address pointed to by 'p_number' is: %d\n\n", *p_number);

    printf("Now, let's change the value using the pointer...\n");
    *p_number = 100; // This changes the data at the memory location.

    printf("The new value of the original variable 'number' is now: %d\n", number);
}