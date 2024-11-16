#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define macros to replace the functions
#define QUICKCHECK(n) ((n) < 2)
#define CHECKFACTOR(a, b) ((a) % (b) == 0)

bool isprime(int n) {
    if (QUICKCHECK(n)) {
        return false;
    }
    for (int factor = 2; factor < n; factor++) {
        if (CHECKFACTOR(n, factor)) {
            return false;
        }
    }
    return true;
}

void main() {
    long start = clock();
    for (int n = -200000; n <= 200000; n++)
        if (isprime(n)) 
            printf("%d ", n);
    long end = clock();
    printf("\nRunning time: %.4f seconds\n", (float)(end - start) / 1000000);
}
