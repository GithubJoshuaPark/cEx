# Compiler to use (gcc or clang)
CC = clang

# Compiler flags:
#  -Wall:    Enable all compiler warnings (highly recommended).
#  -g:       Include debugging information in the executable.
#  -pthread: Link the POSIX threads library (required for multithreadingEx.c).
CFLAGS = -Wall -g -pthread

# Automatically find all .c source files in the current directory.
SRCS = $(wildcard *.c)

# The name of the final executable file.
TARGET = main.exe

# The 'all' target is the default. It's a convention.
# Typing 'make' is the same as typing 'make all'.
all: $(TARGET)

# The rule to build the target executable.
# It says: to make the $(TARGET), you need all the $(SRCS) files,
# and you run the following command to do it.
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# The 'clean' target removes the compiled executable.
clean:
	rm -f $(TARGET)

# Tells make that 'all' and 'clean' are not actual files to be built.
.PHONY: all clean