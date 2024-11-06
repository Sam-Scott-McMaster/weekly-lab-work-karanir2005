/*A program that takes an int array, size and key and returns the index of the first occurance of the key.
* Rushil Karani
* 11/5/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include "array_utilities.h"

int find_index(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int* find_pointer(int arr[], int size, int key) {
    for (int* ptr = arr; ptr < arr + size; ptr++) {  
        if (*ptr == key) {
            return ptr;
        }
    }
    return NULL;
}

int count(int arr[], int size, int key) {
    int count = 0;
    int* p = find_pointer(arr, size, key);

    while (p != NULL) {
        count++;  // increase count for each occurrence by 1
        int offset = p - arr + 1;  // set the new start index
        size -= offset;            // set the new size of arr
        arr = p + 1;               // shift the pointer to the next position: p+1
        p = find_pointer(arr, size, key);  // call find_pointer on the remaining elements till none are left
    }

    return count;
}

int count2d(int rows, int cols, int arr[][cols], int key) {
    int total_count = 0;

    for (int i = 0; i < rows; i++) {
        total_count += count(arr[i], cols, key); 
    }

    return total_count;
}