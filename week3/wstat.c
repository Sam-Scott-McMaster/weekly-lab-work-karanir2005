/* prints the avg characters per line from a text file
*
* Rushil Karani
* September 28th, 2024
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    double line, word, character;  // stores the output of wc

    int result = scanf("%lf %lf %lf", &line, &word, &character); //reads values from wc and stores them to the variables
                                                                 //result = 3 if successful

    if (result != 3) {                                       //check if input was not valid
        fprintf(stderr, "Error! Enter valid wc command.\n");   //then prints an error message
        return EXIT_FAILURE;
    }

    if (line == 0) { //prints an error message if line = 0 to avoid zero-division error
        fprintf(stderr, "Error: No lines in the input.\n");
        return EXIT_FAILURE;
    }

    double avg_line_len = (character / line-1); //calculates the average line length and subtracts 1 from line 

    printf("Average line length: %.1lf\n", avg_line_len);

    return EXIT_SUCCESS;
}
