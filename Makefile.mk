# Compiler and flags
CC = clang
# -Iinclude: 'include' 디렉터리에서 헤더 파일을 찾도록 컴파일러에 지시합니다.
# -Wall: 모든 컴파일러 경고를 활성화합니다.
# -g: 디버깅 정보를 포함합니다.
# -pthread: 멀티스레딩 예제를 위해 POSIX 스레드 라이브러리를 링크합니다.
CFLAGS = -Wall -g -pthread -Iinclude

# Directory definitions
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

# Automatically find all .c source files in the source directory.
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Create a list of object file names (.o) based on the source files.
# They will be placed in the BIN_DIR.
# e.g., src/main.c -> bin/main.o
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRCS))

# The name of the final executable file, to be placed in the BIN_DIR.
TARGET = $(BIN_DIR)/main

# The 'all' target is the default. It's a convention.
# It depends on our final executable.
.PHONY: all
all: $(TARGET)

# Rule to build the final executable from the object files.
# It says: to make the $(TARGET), you need all the $(OBJS) files,
# and you run the following command to link them.
$(TARGET): $(OBJS)
	@echo "Linking to create final executable: $@"
	@mkdir -p $(@D) # Ensure the binary directory exists
	$(CC) $(CFLAGS) -o $@ $^

# Pattern rule to compile .c files into .o files.
# It says: to make a file like 'bin/%.o', you need a file 'src/%.c',
# and you run the following command.
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $< -> $@"
	@mkdir -p $(@D) # Ensure the object file directory exists
	$(CC) $(CFLAGS) -c -o $@ $<

# The 'clean' target removes all compiled files.
.PHONY: clean
clean:
	@echo "Cleaning up build files..."
	rm -rf $(BIN_DIR)