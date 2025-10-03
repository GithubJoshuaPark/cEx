#include <stdio.h>
#include "functionsEx.h"
#include "hello.h" // Using printLine for consistent output formatting

/**
 * @brief A simple function that takes two integers and returns their sum.
 * @param a The first integer.
 * @param b The second integer.
 * @return The sum of a and b.
 */
int add(int a, int b) {
    return a + b;
}

void functionsEx(void) {
    printLine("Demonstrating Functions");

    int num1 = 10;
    int num2 = 25;
    int sum = add(num1, num2); // Calling our 'add' function

    printf("The sum of %d and %d is %d.\n", num1, num2, sum);
}