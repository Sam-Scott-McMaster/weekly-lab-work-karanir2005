/* 
 * Hailstone sequence program
 * Rushil Karani
 * 27th oct 2024
 *
*/


#include <stdio.h>
#include <stdlib.h>

void hailstone(long n) {
    //if n is 1, print it and return (ie terminate function)
    if (n == 1) {
        printf("%ld\n", n);
        return;
    }

    // print the current number
    printf("%ld ", n);

    //apply the hailstone sequence rule and call the function again for the new number
    if (n % 2 == 0) {
        hailstone(n / 2); // even nums
    } else {
        hailstone(3 * n + 1); // odd nums
    }
}

int main() {
    long n;

    // store user input
    printf("Enter a positive, non-zero integer: ");
    scanf("%ld", &n);

    // check for invalid input
    if (n <= 0) {
        printf("Please enter a positive & non-zero integer.\n");
        return 1; // exit with an error code 1
    }

    // start the hailstone sequence
    hailstone(n);

    return 0; // exit with code 0
}