#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool isprime(int n) {
    if (n < 2) {
        return false;
    }
    for (int factor = 2; factor < n; factor++) {
        if (n % factor == 0){
            return false;
        }
    }
    return true;
}

void main() {
    long start = clock();
    for (int n=-200000; n<=200000; n++)
        if (isprime(n)) 
            printf("%d ",n);
    long end = clock();
    printf("\nRunning time: %.4f seconds\n",(float)(end-start)/1000000);
}
