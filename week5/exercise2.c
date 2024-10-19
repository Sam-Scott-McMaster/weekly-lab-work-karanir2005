/*
* The program takes inputs from the user and prints the lowest date
*
* Rushil Karani
* October 18th, 2024
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m,d,y;               // variables for month, day, year
    int low_m, low_d, low_y; // variables for lowest month, day, year
    int first_inp=0;        // to check if the first valid date has been provided

    do {
        printf("Enter a date (mm/dd/yyyy): "); 
        scanf("%d /%d /%d", &m, &d, &y);       
        
        // check if this is the first date input
        if (first_inp==0){
            low_m=m;  // initialize lowest month/year/day for first valid input
            low_d=d;  
            low_y=y;  
            first_inp=1; // set the first input flag=1 (recieved)
            
            // if user enters 0/0/0 as first input reset the first input flag
            if (m == 0 && d == 0 && y == 0) {
                printf("\nNo dates entered.\n");
                first_inp=0;
            }    
        }
        
        // validate the format for date input
        if ((d<1 || d>31 || m<1 || m>12)){
            // check if the input is not 0/0/0
            if (m != 0 && d != 0 && y != 0){
                printf("Enter valid date format!\n"); 
                first_inp=0; // reset the first input to 0
            }
        }   
        else{
            // update the lowest date if the new date is earlier
            if (low_y>y){ //check if year was earlier: then change all 3
                low_y=y;  // update lowest year/month/date
                low_m=m;  
                low_d=d;  
            }
            else if(low_y==y){ //if year is same then check month
                if (low_m>m){ //change day and month if month is before low_m
                    low_m=m; 
                    low_d=d; 
                }
                else if(low_m==m){ //if month is also same, check day
                    if(low_d>d){ //change day if d is lower than low_d
                        low_d=d; 
                    }
                }
            }
        }
    } while(m != 0 && d != 0 && y != 0); // loop until 0/0/0 input is received

    // print the earliest valid date given a valid date was entered
    if (first_inp==1){
        printf("\nThe earliest valid date is %i/%i/%i\n", low_m,low_d,low_y);
    }
}
