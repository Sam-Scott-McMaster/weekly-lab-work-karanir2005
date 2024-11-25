#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utilities.h"

void to_upper (char *str) {
    for (int i = 0; str[i] != '\0'; i++) { //loops string till null char is found
        if (str[i] >= 'a' && str[i] <= 'z') { //is character is a valid lower case alphabet
            str[i] = str[i] - ('a' - 'A'); 
            //uses unicode numbers to convert leters 
            //to uppercase (ie. subtracts the difference between "a" and "A" 
            //from any lowercase letter to get the coresponding capital letter.)
        }
    }
}

char *to_lower_pure(char *str) {
    
    char *lower_str = malloc(strlen(str) + 1); //allocate memory for the new string (same as the length for the old one +1)

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            lower_str[i] = str[i] + ('a' - 'A'); //convert to lowercase based on unicode difference of "a" and "A"
        } 
        else {
            lower_str[i] = str[i]; //copy other characters as-is
        }
    }

    lower_str[strlen(str)] = '\0'; //null to end the new string
    return lower_str; //return the new string as a copy
}

void find_content(char *s, char **first, char **last) {
    
    int len = strlen(s);

    *first = *last = &s[len];

    for (int i = 0; i < len; i++) {
        if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t') {
            *first = &s[i];
            break;
        }
    }

    for (int i = len - 1; i >= 0; i--) {
        if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t') {
            *last = &s[i];
            break;
        }
    }
}

char *trim(char *str) {
    char *first;
    char *last;
    find_content(str, &first, &last);

    char *trimmed = malloc(last-first + 2);

    strncpy(trimmed, first, last - first + 1);
    trimmed[last - first + 1] = '\0';
    return trimmed;
} 