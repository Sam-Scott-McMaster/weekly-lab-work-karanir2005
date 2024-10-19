/*
* Program to use a switch statement to output 
* the date with the name of the month.
*
* Rushil Karani
* October 18th, 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int m,d,y;              // variables for month, day, year
    int low_m, low_d, low_y; // variables for lowest month, day, year
    int first_inp=0;       // to check if the first valid date has been provided

    do {
        printf("Enter a date (mm/dd/yyyy): "); // prompt for date input
        scanf("%d /%d /%d", &m, &d, &y); // read month, day, year
       
        // check if this is the first date input
        if (first_inp==0){
            low_m=m;  // initialize lowest month/day/year
            low_d=d;  
            low_y=y;  
            first_inp=1; // set the first input=1
            
            // if user enters 0/0/0 as first input, reset the first input flag
            if (m == 0 && d == 0 && y == 0) {
                printf("\nNo dates entered.\n");
                first_inp=0; // reset the first input =1 
            }    
        }
        
        // validate the format for date input
        if ((d<1 || d>31 || m<1 || m>12) || (m==2 && d>28) || ((m == 2 || m == 4 || m == 6 || m == 9 || m == 11) && d>30)){
            // check if the input is not 0/0/0
            if (m != 0 && d != 0 && y != 0){
                printf("Enter valid date format!\n"); // prompt for valid date
                first_inp=0; // reset the first input to 0
            }
        }   
        else{
            // update the lowest date if the new date is earlier
            if (low_y>y){ // check if year is earlier
                low_y=y;  // update lowest year/month and day
                low_m=m;  
                low_d=d;  
            }
            else if(low_y==y){ // if year is the same, check month
                if (low_m>m){ // if new month is earlier
                    low_m=m; // update lowest month
                    low_d=d; // update lowest day
                }
                else if(low_m==m){ // if month is also the same, check day
                    if(low_d>d){ // if new day is earlier
                        low_d=d; // update lowest day
                    }
                }
            }
        }
    } while(m != 0 && d != 0 && y != 0); // loop until 0/0/0 input is received

    int x=low_m; // store lowest month for switch statement
    char m_str[]="         "; // initialize month string

    // switch statement to get month name
    switch(x){
        case 1:
            strcpy(m_str, "Jan,"); // copy month name to string
            break;
        case 2:
            strcpy(m_str, "Feb,");
            break;
        case 3:
            strcpy(m_str, "Mar,");
            break;
        case 4:
            strcpy(m_str, "Apr,");
            break;
        case 5:
            strcpy(m_str, "May,");
            break;
        case 6:
            strcpy(m_str, "Jun,");
            break;
        case 7:
            strcpy(m_str, "Jul,");
            break;
        case 8:
            strcpy(m_str, "Aug,");
            break;
        case 9:
            strcpy(m_str, "Sep,");
            break;
        case 10:
            strcpy(m_str, "Oct,");
            break;
        case 11:
            strcpy(m_str, "Nov,");
            break;
        case 12:
            strcpy(m_str, "Dec,");
            break;
        default:
            break; // no valid month, do nothing
    }

    // print the earliest valid date if one was entered
    if (first_inp==1){
        printf("\nThe earliest valid date is %i %s %i\n", low_d,m_str,low_y); // output the date
    }
}
