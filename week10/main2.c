#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utilities.h"

void main () {
    char *s = "              ";
    char *first;
    char *last;
    find_content(s, &first, &last);
    printf("%c...%c\n", *first, *last);
}