#include <stdio.h>
#include "data_typesEx.h"
#include "hello.h" // For printLine

/**
 * @brief Demonstrates basic data types in C.
 * 
 * This function defines variables of different fundamental types
 * (integer, floating-point, character) and prints their values
 * and sizes to the console.
 */
void data_typesEx(void) {
    // Integer type: for whole numbers
    int age = 30;

    // Floating-point type: for numbers with a decimal point
    float weight = 155.5f; // 'f' suffix is good practice for float literals

    // Double-precision floating-point type: for more precise decimal numbers
    double pi = 3.14159265359;

    // Character type: for single characters
    char initial = 'J';

    printLine("Demonstrating Basic Data Types");
    printf("Integer (age): %d\n", age);
    printf("Float (weight): %f\n", weight);
    printf("Double (pi): %lf\n", pi); // Use %lf for printing doubles
    printf("Character (initial): %c\n\n", initial);
    printf("Size of int on this machine: %zu bytes\n", sizeof(int));
    printf("Size of char on this machine: %zu bytes\n", sizeof(char));
}