#include <stdio.h>
#include "recursion_examplesEx.h"
#include "hello.h" // For printLine

// --- Factorial Function (Recursive) ---
// Calculates the factorial of a non-negative integer.
// The factorial of n (n!) is the product of all positive integers up to n.
// Example: 5! = 5 * 4 * 3 * 2 * 1 = 120
unsigned long long factorial(int n) {
    // Base Case: The condition that stops the recursion.
    // The factorial of 0 is 1.
    if (n == 0) {
        return 1;
    }
    // Recursive Step: The function calls itself with a modified argument.
    // n! = n * (n-1)!
    else {
        return n * factorial(n - 1);
    }
}

void recursion_examplesEx(void) {
    printLine("Demonstrating Recursion with Factorial");

    int number = 5;
    printf("Calculating the factorial of %d...\n", number);
    unsigned long long result = factorial(number);
    printf("Factorial of %d (%d!) is %llu.\n\n", number, number, result);

    int another_number = 10;
    printf("Calculating the factorial of %d...\n", another_number);
    result = factorial(another_number);
    printf("Factorial of %d (%d!) is %llu.\n", another_number, another_number, result);
}