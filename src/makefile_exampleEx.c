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

    printf("# Compiler and flags\n");
    printf("CC = clang\n\n");
    printf("# -Iinclude: 'include' 디렉터리에서 헤더 파일을 찾도록 컴파일러에 지시합니다.\n");
    printf("# -Wall: 모든 컴파일러 경고를 활성화합니다.\n");
    printf("# -g: 디버깅 정보를 포함합니다.\n");
    printf("# -pthread: 멀티스레딩 예제를 위해 POSIX 스레드 라이브러리를 링크합니다.\n");
    printf("CFLAGS = -Wall -g -pthread -Iinclude\n\n");

    printf("# Directory definitions\n");
    printf("SRC_DIR = src\n");
    printf("INC_DIR = include\n");
    printf("BIN_DIR = bin\n\n");

    printf("# Automatically find all .c source files in the source directory.\n");
    printf("SRCS = $(wildcard $(SRC_DIR)/*.c)\n\n");

    printf("# Create a list of object file names (.o) based on the source files.\n");
    printf("OBJS = $(patsubst $(SRC_DIR)/%%.c, $(BIN_DIR)/%%.o, $(SRCS))\n\n");

    printf("# The name of the final executable file, to be placed in the BIN_DIR.\n");
    printf("TARGET = $(BIN_DIR)/main\n\n");

    printf("# The 'all' target is the default. It's a convention.\n");
    printf(".PHONY: all\n");
    printf("all: $(TARGET)\n\n");

    printf("# Rule to build the final executable from the object files.\n");
    printf("$(TARGET): $(OBJS)\n");
    printf("\t@echo \"Linking to create final executable: $@\"\n");
    printf("\t@mkdir -p $(@D)\n");
    printf("\t$(CC) $(CFLAGS) -o $@ $^\n\n");

    printf("# Pattern rule to compile .c files into .o files.\n");
    printf("$(BIN_DIR)/%%.o: $(SRC_DIR)/%%.c\n");
    printf("\t@echo \"Compiling $< -> $@\"\n");
    printf("\t@mkdir -p $(@D)\n");
    printf("\t$(CC) $(CFLAGS) -c -o $@ $<\n\n");

    printf("# The 'clean' target removes all compiled files.\n");
    printf(".PHONY: clean\n");
    printf("clean:\n");
    printf("\t@echo \"Cleaning up build files...\"\n");
    printf("\trm -rf $(BIN_DIR)\n");

}