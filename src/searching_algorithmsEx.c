#include <stdio.h>
#include "searching_algorithmsEx.h"
#include "hello.h" // For printLine

// --- Linear Search ---
// Searches for a value in an array by checking every element sequentially.
// Works on sorted or unsorted arrays. Time Complexity: O(n)
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index where the target was found
        }
    }
    return -1; // Return -1 if the target is not in the array
}

// --- Binary Search (Recursive) ---
// Searches for a value in a *sorted* array by repeatedly dividing the search interval in half.
// Time Complexity: O(log n)
int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle
        if (arr[mid] == target) {
            return mid;
        }

        // If element is smaller than mid, search the left subarray
        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }

        // Else the element can only be in the right subarray
        return binarySearch(arr, mid + 1, right, target);
    }

    // Element is not present in the array
    return -1;
}

void searching_algorithmsEx(void) {
    printLine("Demonstrating Searching Algorithms");

    int sorted_array[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(sorted_array) / sizeof(sorted_array[0]);
    int target_found = 23;
    int target_not_found = 40;
    int result;

    printf("Array to search: {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}\n\n");

    // --- Linear Search ---
    printf("--- Linear Search ---\n");
    result = linearSearch(sorted_array, size, target_found);
    printf("Searching for %d... Found at index: %d\n", target_found, result);
    result = linearSearch(sorted_array, size, target_not_found);
    printf("Searching for %d... Found at index: %d (not found)\n\n", target_not_found, result);

    // --- Binary Search ---
    printf("--- Binary Search ---\n");
    result = binarySearch(sorted_array, 0, size - 1, target_found);
    printf("Searching for %d... Found at index: %d\n", target_found, result);
    result = binarySearch(sorted_array, 0, size - 1, target_not_found);
    printf("Searching for %d... Found at index: %d (not found)\n", target_not_found, result);
}