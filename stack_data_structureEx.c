#include <stdio.h>
#include <stdbool.h> // For bool, true, false
#include "stack_data_structureEx.h"
#include "hello.h" // For printLine

#define STACK_SIZE 5

// A structure to represent a stack
typedef struct {
    int items[STACK_SIZE];
    int top; // Index of the top element
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if the stack is full
bool isFull(Stack *s) {
    return s->top == STACK_SIZE - 1;
}

// Check if the stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Add an element to the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        s->top++;
        s->items[s->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Remove an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1; // Return an error value
    } else {
        int item = s->items[s->top];
        s->top--;
        return item;
    }
}

void stack_data_structureEx(void) {
    printLine("Demonstrating Stack Data Structure (LIFO)");

    Stack myStack;
    initStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 40);
    push(&myStack, 50);
    push(&myStack, 60); // This will cause an overflow

    printf("\nPopping items from the stack:\n");
    while (!isEmpty(&myStack)) {
        printf("Popped %d from the stack.\n", pop(&myStack));
    }

    // Try to pop from an empty stack
    pop(&myStack);
}