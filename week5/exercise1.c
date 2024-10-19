/* 
* takes a number_of_days and starting_day input 
* from user and outputs a nicely formated calendar.
*
* Rushil Karani
* October 18th, 2024
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int days_in_month, start_day;  // declare variables to store the number of days in the month and the starting day of the week
    
    // prompt the user to enter the number of days in the current month
    printf("How many days this month? ");
    scanf("%i", &days_in_month); 
    
    // prompt the user to enter the starting day of the week
    printf("What’s the starting day (1=Monday, 7=Sunday)? ");
    scanf("%i", &start_day);  

    // check if the starting day is valid (between 1 and 7)
    if (start_day<=7 && start_day>=1){
        printf("\n   M   T   W   T   F   S   S\n");  

        // print empty spaces for the days before the first day of the month
        for (int i = 1; i<start_day; i++){
            printf("    ");  // spaces to align the first date under the correct day
        }

        // Loop through the days of the month and print them
        for (int i = 1; i<=days_in_month; i++){
            printf("%4d", i);  //print the days with a width of 4

            // if the current day is the last day of the week, move to the next line
            if ((start_day+i-1)%7 == 0){
                printf("\n");
            }
        }
        
        printf("\n"); 
    }
    else{
        // if invalid starting day then print an error message
        printf("Please enter a start day between 1 and 7 (1=Monday, 7=Sunday)\n");
    }

}
