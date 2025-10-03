#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table_data_structureEx.h"
#include "hello.h" // For printLine

#define TABLE_SIZE 10

// Node for storing key-value pairs in a linked list (for collision handling)
typedef struct HashNode {
    char* key;
    char* value;
    struct HashNode* next;
} HashNode;

// The hash table structure
typedef struct {
    HashNode** table; // Array of pointers to HashNode
    int size;
} HashTable;

// Hash function: simple sum of ASCII values
unsigned int hash(const char* key, int table_size) {
    unsigned long int hash_value = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash_value += key[i];
    }
    return hash_value % table_size;
}

// Create a new hash table
HashTable* createHashTable(int size) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    if (ht == NULL) return NULL;

    ht->size = size;
    ht->table = (HashNode**)calloc(ht->size, sizeof(HashNode*));
    if (ht->table == NULL) {
        free(ht);
        return NULL;
    }
    return ht;
}

// Insert a key-value pair into the hash table
void hashInsert(HashTable* ht, const char* key, const char* value) {
    unsigned int index = hash(key, ht->size);

    // Create a new node
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = strdup(key);     // strdup allocates memory and copies the string
    newNode->value = strdup(value);
    newNode->next = NULL;

    // Insert at the beginning of the linked list at that index
    if (ht->table[index] == NULL) {
        ht->table[index] = newNode;
    } else {
        newNode->next = ht->table[index];
        ht->table[index] = newNode;
    }
}

// Search for a value by key
char* hashSearch(HashTable* ht, const char* key) {
    unsigned int index = hash(key, ht->size);
    HashNode* current = ht->table[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL; // Not found
}

// Free the entire hash table
void freeHashTable(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        HashNode* current = ht->table[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

void hash_table_data_structureEx(void) {
    printLine("Demonstrating Hash Table Data Structure");

    HashTable* ht = createHashTable(TABLE_SIZE);

    hashInsert(ht, "name", "John Doe");
    hashInsert(ht, "course", "C Programming");
    hashInsert(ht, "level", "Intermediate"); // This might collide with "name"

    printf("Searching for key 'course': %s\n", hashSearch(ht, "course"));
    printf("Searching for key 'name': %s\n", hashSearch(ht, "name"));
    printf("Searching for key 'level': %s\n", hashSearch(ht, "level"));
    
    char* result = hashSearch(ht, "age");
    if (result == NULL) {
        printf("Searching for key 'age': Not Found\n");
    }

    freeHashTable(ht);
    printf("\nHash table memory has been freed.\n");
}