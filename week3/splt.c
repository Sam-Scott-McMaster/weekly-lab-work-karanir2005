/* reads strings one at a time from stdin and writes them to stdout
*
* Rushil Karani
* September 28th, 2024
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100]; //a list with a capacity of 100 strings
    int valid;      //validate if loop has reached EOF

    while (valid = scanf("%s", input) != EOF){ //loop that takes string input until the EOF. Sets valid to 1 if input is a valid string.   
        if (valid == 1) { 
            printf("%s\n", input); //prints the string from stdin if valid = 1
        }
        else{
            fprintf(stderr, "Bad Value!"); //otherwise prints error message and returns EXIT_FAILURE
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS; //is everything runs successfully then return EXIT_SUCCESS
}
