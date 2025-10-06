#include <stdio.h>
#include <string.h>
#include "unionsEx.h"
#include "hello.h" // For printLine

// 1. Define a union.
// All members of a union share the same memory location.
// The size of the union is determined by the size of its largest member.
typedef union Data {
    int i;
    float f;
    char str[20];
} Data;

void unionsEx(void) {
    printLine("Demonstrating Unions");

    // 2. Declare a union variable.
    Data data;

    printf("Memory size of union Data: %zu bytes (size of the largest member, char[20])\n\n", sizeof(data));

    // 3. Assign a value to the integer member.
    data.i = 10;
    printf("Data after assigning an integer:\n");
    printf("  data.i = %d\n\n", data.i);

    // 4. Assign a value to the float member. This overwrites the integer.
    data.f = 220.5f;
    printf("Data after assigning a float (integer value is now corrupted):\n");
    printf("  data.f = %f\n", data.f);
    printf("  data.i (garbage value) = %d\n\n", data.i);

    // 5. Assign a value to the string member. This overwrites the float.
    strcpy(data.str, "C Programming");
    printf("Data after assigning a string (float and int values are now corrupted):\n");
    printf("  data.str = \"%s\"\n", data.str);
}