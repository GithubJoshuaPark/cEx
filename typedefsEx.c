#include <stdio.h>
#include "typedefsEx.h"
#include "hello.h" // For printLine

// 1. Define a structure the standard way.
typedef struct Vector2D {
    float x;
    float y;
} Vector2D;

// 2. Use 'typedef' to create a simpler alias for 'struct Vector2D'.
//    The new name 'Point' can now be used instead of 'struct Vector2D'.
typedef struct Vector2D Point;

// 3. It's also common to create an alias for simpler types to make
//    the code's intent clearer.
typedef unsigned long long ULL;

void typedefsEx(void) {
    printLine("Demonstrating Typedefs");

    // Declare a variable the "long" way, without typedef.
    Vector2D v1 = {10.0f, 20.0f};
    printf("Using 'struct Vector2D': v1 = (%.1f, %.1f)\n", v1.x, v1.y);

    // Declare a variable using the 'Point' alias created by typedef.
    Point p1 = {30.0f, 40.0f};
    printf("Using the 'Point' alias: p1 = (%.1f, %.1f)\n\n", p1.x, p1.y);

    ULL very_large_number = 123456789012345ULL;
    printf("Using 'ULL' as an alias for 'unsigned long long': %llu\n", very_large_number);
}