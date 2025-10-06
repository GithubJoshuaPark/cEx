#include <stdio.h>
#include "bit_manipulationEx.h"
#include "hello.h" // For printLine

// Helper function to print the binary representation of an 8-bit number (a char)
void print_binary(unsigned char n) {
    printf("0b");
    for (int i = 7; i >= 0; i--) {
        putchar((n & (1 << i)) ? '1' : '0');
    }
}

void bit_manipulationEx(void) {
    printLine("Demonstrating Bit Manipulation");

    unsigned char a = 60;  // Binary: 0011 1100
    unsigned char b = 13;  // Binary: 0000 1101

    printf("a = %3d, binary: ", a); print_binary(a); printf("\n");
    printf("b = %3d, binary: ", b); print_binary(b); printf("\n\n");

    // AND (&): Sets a bit to 1 only if both corresponding bits are 1.
    unsigned char result_and = a & b; // 0000 1100 (12)
    printf("a & b = %3d, binary: ", result_and); print_binary(result_and); printf(" (AND)\n");

    // OR (|): Sets a bit to 1 if at least one of the corresponding bits is 1.
    unsigned char result_or = a | b; // 0011 1101 (61)
    printf("a | b = %3d, binary: ", result_or); print_binary(result_or); printf(" (OR)\n");

    // XOR (^): Sets a bit to 1 only if the corresponding bits are different.
    unsigned char result_xor = a ^ b; // 0011 0001 (49)
    printf("a ^ b = %3d, binary: ", result_xor); print_binary(result_xor); printf(" (XOR)\n");

    // NOT (~): Inverts all the bits.
    unsigned char result_not = ~a; // 1100 0011 (195)
    printf("  ~a  = %3d, binary: ", result_not); print_binary(result_not); printf(" (NOT)\n\n");

    // Left Shift (<<): Shifts bits to the left, filling with zeros. (Equivalent to multiplying by 2^n)
    unsigned char result_lshift = a << 2; // 1111 0000 (240)
    printf("a << 2 = %3d, binary: ", result_lshift); print_binary(result_lshift); printf(" (Left Shift)\n");

    // Right Shift (>>): Shifts bits to the right. (Equivalent to dividing by 2^n)
    unsigned char result_rshift = a >> 2; // 0000 1111 (15)
    printf("a >> 2 = %3d, binary: ", result_rshift); print_binary(result_rshift); printf(" (Right Shift)\n");
}