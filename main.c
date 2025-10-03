#include <stdio.h>
#include <stdlib.h> // For system()
#include "hello.h"
#include "data_typesEx.h"
#include "functionsEx.h"
#include "pointersEx.h"
#include "arraysEx.h"
#include "structuresEx.h"
#include "unionsEx.h"
#include "enumsEx.h"
#include "typedefsEx.h"
#include "memory_managementEx.h"
#include "file_ioEx.h"
#include "dynamic_memory_allocationEx.h"
#include "dynamic_2d_arrayEx.h" // New include
#include "stack_data_structureEx.h"
#include "queue_data_structureEx.h"
#include "linked_list_data_structureEx.h"
#include "double_linked_list_data_structureEx.h"
#include "circular_linked_list_data_structureEx.h"
#include "binary_tree_data_structureEx.h"
#include "hash_table_data_structureEx.h"
#include "graphs_data_structureEx.h"
#include "searching_algorithmsEx.h"
#include "sorting_algorithmsEx.h"
#include "recursion_examplesEx.h"
#include "bit_manipulationEx.h"
#include "preprocessor_directivesEx.h"
#include "multithreadingEx.h"
#include "networking_basicsEx.h"
#include "socket_programmingEx.h"
#include "makefile_exampleEx.h"
#include "error_handlingEx.h"
#include "snake_gameEx.h"
#include "tetris_gameEx.h"
#include "breakout_gameEx.h"

// --- Type Definitions for a Data-Driven Menu ---

/**
 * @brief A function pointer type for our example functions.
 * All example functions must match this signature (take no arguments, return void).
 */
typedef void (*ExampleFunc)(void);

/**
 * @brief A structure to hold the information for a single menu item.
 */
typedef struct {
    const char* description; // The text to display in the menu
    ExampleFunc function;    // A pointer to the function to execute
} MenuItem;

// --- Menu Definition ---

// This array now drives the entire menu and dispatch logic.
// To add a new item, just add a new line here.
MenuItem menu_items[] = {
    {"Hello World", say_hello},
    {"Data Types", data_typesEx},
    {"Functions", functionsEx},
    {"Pointers", pointersEx},
    {"Arrays", arraysEx},
    {"Structures", structuresEx},
    {"Unions", unionsEx},
    {"Enums", enumsEx},
    {"Typedefs", typedefsEx},
    {"Memory Management", memory_managementEx},
    {"File I/O", file_ioEx},
    {"Dynamic Memory Allocation", dynamic_memory_allocationEx},
    {"Dynamic 2D Array Allocation", dynamic_2d_arrayEx}, // New menu item
    {"Stack Data Structure", stack_data_structureEx},
    {"Queue Data Structure", queue_data_structureEx},
    {"Linked List Data Structure", linked_list_data_structureEx},
    {"Double Linked List Data Structure", double_linked_list_data_structureEx},
    {"Circular Linked List Data Structure", circular_linked_list_data_structureEx},
    {"Binary Tree Data Structure", binary_tree_data_structureEx},
    {"Hash Table Data Structure", hash_table_data_structureEx},
    {"Graphs Data Structure", graphs_data_structureEx},
    {"Searching Algorithms", searching_algorithmsEx},
    {"Sorting Algorithms", sorting_algorithmsEx},
    {"Recursion Examples", recursion_examplesEx},
    {"Bit Manipulation", bit_manipulationEx},
    {"Preprocessor Directives", preprocessor_directivesEx},
    {"Error Handling", error_handlingEx},
    {"Multithreading", multithreadingEx},
    {"Networking Basics", networking_basicsEx},
    {"Socket Programming", socket_programmingEx},
    {"Makefile Example", makefile_exampleEx},
    {"** Snake Game **", snake_gameEx},
    {"** Tetris Game **", tetris_gameEx},
    {"** Breakout Game **", breakout_gameEx},
};

// Calculate the number of items in the menu array.
const int num_menu_items = sizeof(menu_items) / sizeof(menu_items[0]);

// --- Utility Functions ---

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void show_menu(void) {
    printLine("C Language Interactive Examples");
    for (int i = 0; i < num_menu_items; i++) {
        printf("%2d. %s\n", i + 1, menu_items[i].description);
    }
    printf("99. Exit\n");
    printf("-------------------------------------\n");
}

int main(void) {
    int choice = 0;

    while (choice != 99) {
        clear_screen();
        show_menu();
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            clear_input_buffer();
            printf("Press Enter to continue...");
            getchar(); // Wait for user to press Enter
            continue;
        }
        clear_input_buffer();

        if (choice == 99) {
            printf("\nExiting the program.\n");
            break;
        }

        // The choice is 1-based, our array is 0-based.
        int index = choice - 1;

        if (index >= 0 && index < num_menu_items) {
            clear_screen();
            // Execute the function using the function pointer from the array
            menu_items[index].function();
            printf("\nPress Enter to return to the menu...");
            getchar(); // Wait for user to press Enter
        } else {
            printf("\nInvalid choice. Please try again.\n");
            printf("Press Enter to continue...");
            getchar(); // Wait for user to press Enter
        }
    }
    return 0;
}
