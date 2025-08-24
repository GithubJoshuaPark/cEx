#include <stdio.h>

void printLine(const char *line) {
    printf("\n%s\n", line);
}

void arithmetic_op() {
    int a = 5, b = 10;
    printf("a: %d, b: %d\n", a, b);
    printf("Addition: %d\n", a + b);
    printf("Subtraction: %d\n", a - b);
    printf("Multiplication: %d\n", a * b);
    printf("Division: %d\n", b / a);
}

void logical_op() {
    int a = 5, b = 10;
    printf("a: %d, b: %d\n", a, b);
    printf("Logical AND: %d\n", a && b);
    printf("Logical OR: %d\n", a || b);
    printf("Logical NOT a: %d\n", !a);
}

void relational_op() {
    int a = 5, b = 10;
    printf("a: %d, b: %d\n", a, b);
    printf("Equal to: %d\n", a == b);
    printf("Not equal to: %d\n", a != b);
    printf("Greater than: %d\n", a > b);
    printf("Less than: %d\n", a < b);
    printf("Greater than or equal to: %d\n", a >= b);
    printf("Less than or equal to: %d\n", a <= b);
}

void bitwise_op() {
    int a = 5, b = 10;
    printf("a: %d, b: %d\n", a, b);

    // a의 이진수 표현 출력
    printf("a's binary value(%zu bits) is: ", sizeof(a) * 8);
    for (int i = sizeof(a) * 8 - 1; i >= 0; i--) {
        printf("%d", (a >> i) & 1);
    }
    printf("\n");

    // b의 이진수 표현 출력
    printf("b's binary value(%zu bits) is: ", sizeof(b) * 8);
    for (int i = sizeof(b) * 8 - 1; i >= 0; i--) {
        printf("%d", (b >> i) & 1);
    }
    printf("\n");
    printf("Bitwise AND: %d\n", a & b);
    printf("Bitwise OR: %d\n", a | b);
    printf("Bitwise XOR: %d\n", a ^ b);
    printf("Bitwise NOT a: %d\n", ~a);
    printf("Left shift a << 1: %d\n", a << 1);
    printf("Right shift b >> 1: %d\n", b >> 1);
}

int main() {
    printLine("<< consoleEx001 project >>");
    printLine("Hello, Joshua! Welcome to C programming.");

    printLine("Performing arithmetic operations:");
    arithmetic_op();

    printLine("Performing logical operations:");
    logical_op();

    printLine("Performing relational operations:");
    relational_op();

    printLine("Performing bitwise operations:");
    bitwise_op();

    return 0;
}