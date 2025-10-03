#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include "linked_list_data_structureEx.h"
#include "hello.h" // For printLine

// 1. Define the structure for a node in the linked list.
//    It contains data and a pointer to the next node in the list.
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        return; // Failed to create node
    }
    newNode->next = *head; // The new node points to the old head
    *head = newNode;       // The head now points to the new node
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the entire list to prevent memory leaks
void freeList(Node** head) {
    Node* current = *head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next; // Save the next node
        free(current);            // Free the current node
        current = nextNode;       // Move to the next node
    }
    *head = NULL; // Set the head to NULL to indicate an empty list
}

void linked_list_data_structureEx(void) {
    printLine("Demonstrating Linked List Data Structure");

    Node* head = NULL; // Start with an empty list

    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);

    printList(head);

    freeList(&head); // Clean up all allocated memory
    printf("Linked list memory has been freed.\n");
}