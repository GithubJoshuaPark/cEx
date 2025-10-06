#include <stdio.h>
#include <string.h> // We need this header for the strcpy function
#include "structuresEx.h"
#include "hello.h" // For printLine

// 1. Define a structure. This is a blueprint for a new data type.
// It groups related variables under a single name.
typedef struct Student {
    char name[50];
    int student_id;
    float gpa;
} Student;

void structuresEx(void) {
    printLine("Demonstrating Structures");

    // 2. Declare a variable of our new 'struct Student' type.
    Student student1;

    // 3. Assign values to the members of the structure using the dot (.) operator.
    // For strings, we must use a function like strcpy to copy the value.
    strcpy(student1.name, "John Doe");
    student1.student_id = 12345;
    student1.gpa = 3.8f;

    // 4. Access and print the members of the structure.
    printf("Student Information:\n");
    printf("  Name: %s\n", student1.name);
    printf("  ID:   %d\n", student1.student_id);
    printf("  GPA:  %.2f\n", student1.gpa); // %.2f prints the float with 2 decimal places
}