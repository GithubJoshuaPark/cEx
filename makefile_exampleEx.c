#include <stdio.h>
#include "makefile_exampleEx.h"
#include "hello.h" // For printLine

void makefile_exampleEx(void) {
    printLine("Explaining Makefiles");

    printf("A Makefile is a special file that contains a set of rules to automate the build process (compiling, linking, etc.).\n");
    printf("Instead of typing a long compilation command every time, you can just type 'make'.\n\n");

    printf("Key Concepts:\n");
    printf("  - Target: The file you want to create (e.g., the final executable).\n");
    printf("  - Dependencies: The files the target depends on (e.g., source .c files).\n");
    printf("  - Rule: The command to run to create the target from its dependencies.\n\n");

    printf("--- Example Makefile for this Project ---\n\n");

    // The following printf statements display a sample Makefile.
    // The double backslashes are used to escape the single backslash for the line continuation character.
    printf("# Compiler to use\n");
    printf("CC = clang\n\n");

    printf("# Compiler flags:\n");
    printf("#  -Wall: Enable all compiler warnings.\n");
    printf("#  -g:    Include debugging information.\n");
    printf("#  -pthread: Link the POSIX threads library (for the multithreading example).\n");
    printf("CFLAGS = -Wall -g -pthread\n\n");

    printf("# Automatically find all .c source files in the current directory.\n");
    printf("SRCS = $(wildcard *.c)\n\n");

    printf("# The name of the final executable file.\n");
    printf("TARGET = main\n\n");

    printf("# The 'all' target is the default. It's a convention.\n");
    printf("# It depends on our final executable.\n");
    printf("all: $(TARGET)\n\n");

    printf("# The rule to build the target executable.\n");
    printf("# It says: to make the $(TARGET), you need all the $(SRCS) files,\n");
    printf("# and you run the following command to do it.\n");
    printf("$(TARGET): $(SRCS)\n");
    printf("\t$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)\n\n");

    printf("# The 'clean' target removes the compiled executable.\n");
    printf("clean:\n");
    printf("\trm -f $(TARGET)\n\n");

    printf("# Tells make that 'all' and 'clean' are not actual files.\n");
    printf(".PHONY: all clean\n");
}