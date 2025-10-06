#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include "double_linked_list_data_structureEx.h"
#include "hello.h" // For printLine

// 1. Define the structure for a node in the double linked list.
//    It contains data, a pointer to the next node, and a pointer to the previous node.
typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

// Function to create a new node
DNode* createDNode(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtHead(DNode** head, int data) {
    DNode* newNode = createDNode(data);
    if (newNode == NULL) {
        return; // Failed to create node
    }
    newNode->next = *head; // New node's next points to the old head
    if (*head != NULL) {
        (*head)->prev = newNode; // Old head's prev points to the new node
    }
    *head = newNode; // The head now points to the new node
}

// Function to print the list from head to tail
void printListForward(DNode* head) {
    DNode* current = head;
    printf("List (Forward):  HEAD -> ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to print the list from tail to head
void printListBackward(DNode* head) {
    if (head == NULL) {
        printf("List (Backward): NULL\n");
        return;
    }
    // Find the tail
    DNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    printf("List (Backward): TAIL -> ");
    DNode* current = tail;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("HEAD\n");
}

// Function to free the entire list
void freeDList(DNode** head) {
    DNode* current = *head;
    DNode* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

void double_linked_list_data_structureEx(void) {
    printLine("Demonstrating Double Linked List Data Structure");

    DNode* head = NULL; // Start with an empty list

    insertAtHead(&head, 30);
    insertAtHead(&head, 20);
    insertAtHead(&head, 10);

    printListForward(head);
    printListBackward(head);

    freeDList(&head); // Clean up all allocated memory
    printf("\nLinked list memory has been freed.\n");
}