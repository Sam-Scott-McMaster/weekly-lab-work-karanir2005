#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utilities.h"

#define INPUT_SIZE 100

int main() {
    char input[INPUT_SIZE + 1];
    while (fgets(input, INPUT_SIZE, stdin)) {
        
        char *trimmed = trim(input);
        to_upper(trimmed); // Modifies the string in-place
        printf("%s", trimmed);

        char *lower_result = to_lower_pure(trimmed);
        printf("%s", lower_result);
        free(lower_result); //deallocate memory
        free (trimmed);
       
    }

    return 0;
}
