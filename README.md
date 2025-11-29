# C language examples
This repository contains various examples of C programming language code snippets and projects. Each example is designed to demonstrate different features and functionalities of the C language.

저는 현장에서 java, c#, javascript, python 등 다양한 언어를 사용하고 있지만, 가장 기본이 되는 언어는 C언어라고 생각합니다.
C언어는 시스템 프로그래밍, 임베디드 시스템, 운영체제 개발 등 다양한 분야에서 사용되며, 다른 언어의 기초가 되는 중요한 언어입니다.
따라서 C언어를 잘 이해하고 활용하는 것은 프로그래밍 전반에 큰 도움이 됩니다.
이 저장소는 C언어의 다양한 예제를 통해 학습하고자 하는 분들에게 도움이 되고자 합니다.

---

```
# project structure
    cEx/
    ├── src/
    │   ├── main.c
    │   ├── hello.c
    │   ├── data_typesEx.c
    │   └── ... (모든 .c 파일)
    ├── include/
    │   ├── hello.h
    │   ├── data_typesEx.h
    │   └── ... (모든 .h 파일)
    ├── bin/
    │   └── (비어 있음)
    ├── Makefile
    ├── Makefile.mk
    └── README.md
    ...

```


## Contents
- [Hello World](hello.c)
- [Data Types](data_typesEx.c)
- [Functions](functionsEx.c)
- [Pointers](pointersEx.c)
- [Arrays](arraysEx.c)
- [Structures](structuresEx.c)
- [Unions](unionsEx.c)
- [Enums](enumsEx.c)
- [Typedefs](typedefsEx.c)
- [Memory Management](memory_managementEx.c)
- [File I/O](file_ioEx.c)
- [Dynamic Memory Allocation](dynamic_memoryEx.c)
- [Dynamic 2D Array Allocation](dynamic_2d_arrayExEx.c)
- [Stack Data Structure](stackEx.c)
- [Queue Data Structure](queueEx.c)
- [Linked List Structure](linked_listEx.c)
- [Double Linked List](double_linked_listEx.c)
- [Circular Linked List](circular_linked_listEx.c)
- [Binary Trees](binary_treesEx.c)
- [Hash Tables](hash_tablesEx.c)
- [Graphs](graphsEx.c)
- [Searching Algorithms](searchingEx.c)
- [Sorting Algorithms](sortingEx.c)
- [Recursion Examples](recursion_examplesEx.c)
- [Bit Manipulation](bit_manipulationEx.c)
- [Preprocessor Directives](preprocessorEx.c)
- [Error Handling](error_handlingEx.c)
- [Multithreading](multithreadingEx.c)
- [Networking](networkingEx.c)
- [Socket Programming](socket_programmingEx.c)
- [Snake Game](snake_gameExEx.c)
- [Tetris Game](tetris_gameExEx.c)
- [Breakout Game](breakout_gameExEx.c)
- [Makefile Example](Makefile)
- [README](README.md)


---

## compile and run
To compile and run the examples, you can use the following commands in your terminal:

```bash
$ make           # This will compile all examples and create the 'main' executable
$ make copy_main # This will copy the 'main' executable to the current directory
$ ./main     # This will run the main example
```

## Getting Started
1. Clone the repository to your local machine.
2. Navigate to the directory containing the examples.
3. Compile all example using `make` command.
4. Run the compiled executable ( ./main ) to see the output.
---

![memory_segment](memory_segment.png)