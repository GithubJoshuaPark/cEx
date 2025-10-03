#include <stdio.h>
#include <string.h> // For memcpy
#include "sorting_algorithmsEx.h"
#include "hello.h" // For printLine

// Helper function to swap two integer values
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Helper function to print an array
void printArray(const char* name, int arr[], int size) {
    printf("%s: ", name);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// --- Bubble Sort ---
// Repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
// Time Complexity: O(n^2)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// --- Selection Sort ---
// Repeatedly finds the minimum element from the unsorted part and puts it at the beginning.
// Time Complexity: O(n^2)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void sorting_algorithmsEx(void) {
    printLine("Demonstrating Sorting Algorithms");

    int original_array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(original_array) / sizeof(original_array[0]);
    
    int arr_for_bubble[size];
    int arr_for_selection[size];
    memcpy(arr_for_bubble, original_array, sizeof(original_array));
    memcpy(arr_for_selection, original_array, sizeof(original_array));

    printArray("Original Array ", original_array, size);
    printf("\n--- Bubble Sort ---\n");
    bubbleSort(arr_for_bubble, size);
    printArray("Sorted Array   ", arr_for_bubble, size);

    printf("\n--- Selection Sort ---\n");
    selectionSort(arr_for_selection, size);
    printArray("Sorted Array   ", arr_for_selection, size);
}