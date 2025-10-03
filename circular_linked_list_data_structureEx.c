#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include "circular_linked_list_data_structureEx.h"
#include "hello.h" // For printLine

// Define the structure for a node in the circular linked list.
typedef struct CNode {
    int data;
    struct CNode* next;
} CNode;

// Function to create a new node
CNode* createCNode(int data) {
    CNode* newNode = (CNode*)malloc(sizeof(CNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of a circular list
void insertAtEnd(CNode** head, int data) {
    CNode* newNode = createCNode(data);
    if (newNode == NULL) return;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Points to itself
    } else {
        CNode* tail = *head;
        while (tail->next != *head) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = *head;
    }
}

// Function to print the circular linked list
void printCircularList(CNode* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    CNode* current = head;
    printf("List (Circular): HEAD -> ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("... back to HEAD (%d)\n", head->data);
}

// Function to free the entire circular list
void freeCircularList(CNode** head) {
    if (*head == NULL) return;

    CNode* current = *head;
    CNode* nextNode = NULL;
    CNode* stopNode = *head; // Mark where to stop
    
    // Break the loop to traverse it like a normal list
    while(current->next != stopNode) {
        current = current->next;
    }
    current->next = NULL; // Break the circle

    // Now free it like a normal list
    current = *head;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

void circular_linked_list_data_structureEx(void) {
    printLine("Demonstrating Circular Linked List Data Structure");

    CNode* head = NULL; // Start with an empty list

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printCircularList(head);

    freeCircularList(&head); // Clean up all allocated memory
    printf("Circular linked list memory has been freed.\n");
}