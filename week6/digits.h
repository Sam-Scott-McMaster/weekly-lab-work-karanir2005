int digits (long n, int *max, int *min) {

    //set max and min to lowest and highest possible number
    
    if (n==0) return 0; //return 0 if n is 0

    *max = 0;
    *min = 9;
    int sum=0; //innitialize sum to 0
    //absolute value of long number (for cases when n is negative
    //we ignore the negative sign
    //ie. the sum, max and min will ignore the negative sign.)
    n=labs(n);     

    //this loop adds all the digits to sum individually and also sets max and min to the max and min of n
    while (n >  0) {
        int digit = n % 10;  // store the last digit in int digit
        sum += digit;        // add the last digit to sum

        // if digit is smaller or bigger than min/max then update
        if (digit > *max) *max = digit;
        if (digit < *min) *min = digit;

        n /= 10;  // remove the last digit
    }

    return sum; //return sum
}