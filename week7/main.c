/*Testing for array_utilities.c
* Rushil Karani
* 11/5/2024
*/
#include <stdio.h>
#include "array_utilities.h"
#include <stdlib.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int test_cases[] = {2, 5, 8, 10}; 
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]); //number of total bytes/number of bytes
                                                                //per index gives the length of the array.

    for (int i = 0; i < num_tests; i++) {
        int key = test_cases[i];
        int index = find_index(arr, size, key);
        if (index != -1) {
            printf("Key %d found at index %d\n", key, index);
        } else {
            printf("Key %d not found in the array\n", key);
        }
    }

    printf("\nTesting find_pointer:\n");
    for (int i = 0; i < num_tests; i++) {
        int key = test_cases[i];
        int* result_ptr = find_pointer(arr, size, key);
        if (result_ptr != NULL) {
            printf("Key %d FOUND %d\n", key, *result_ptr);
        } else {
            printf("Key %d NOT FOUND\n", key);
        }
    }

    int arr2[] = {5, -4, 12, 23, 5, 2, 2, 5, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int key2 = 5;

    printf("\nTesting count:\n");
    int occurrences = count(arr2, size2, key2);
    printf("Key %d occurs %d times\n", key2, occurrences);


    int arr3[][4] = {
        {5, -4, 12, 23},
        {5, 2, 2, 5},
        {1, 5, 5, -4}
    };
    int rows3 = sizeof(arr3) / sizeof(arr3[0]);
    int cols3 = sizeof(arr3[0]) / sizeof(arr3[0][0]);
    int key3 = 5;

    printf("Testing count2d:\n");
    int total_occurrences = count2d(rows3, cols3, arr3, key3);
    printf("Key %d occurs %d times in the 2D array\n", key3, total_occurrences);

    return EXIT_SUCCESS;
}
