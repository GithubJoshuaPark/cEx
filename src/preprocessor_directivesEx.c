#include <stdio.h>
#include "preprocessor_directivesEx.h"
#include "hello.h" // For printLine

// 1. #define: Creates a macro, which is a fragment of code that has been given a name.
// It can be used for constants. The preprocessor will replace PI with 3.14159 before compilation.
#define PI 3.14159

// It can also be used for function-like macros.
#define SQUARE(x) ((x) * (x))

// 2. Conditional Compilation: #ifdef, #ifndef, #if, #else, #endif
// This is often used for platform-specific code or for debugging.
#define DEBUG_MODE

void preprocessor_directivesEx(void) {
    printLine("Demonstrating Preprocessor Directives");

    // --- Using #define for a constant ---
    printf("--- #define for constants ---\n");
    double radius = 5.0;
    double area = PI * radius * radius;
    printf("The value of PI is: %f\n", PI);
    printf("The area of a circle with radius %.1f is: %f\n\n", radius, area);

    // --- Using #define for a function-like macro ---
    printf("--- #define for function-like macros ---\n");
    int num = 7;
    printf("The square of %d is: %d\n\n", num, SQUARE(num));

    // --- Using conditional compilation ---
    printf("--- Conditional Compilation ---\n");
#ifdef DEBUG_MODE
    printf("Debug mode is ON. This message is printed because DEBUG_MODE is defined.\n");
#else
    printf("Debug mode is OFF.\n");
#endif

#ifndef RELEASE_MODE
    printf("RELEASE_MODE is not defined, so this message is printed.\n");
#endif
}