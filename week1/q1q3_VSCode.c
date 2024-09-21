/* Question 1 Lab 1.2 - Print name, st. #, course name with pauses
*  Question 3 Lab 1.2 - Reflection questions.
*
* Rushil Karani
* September 11th, 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Name: "); //prints without changing the carriage to the next line
    fflush(stdout); //avoids the display buffer to print the output immediatly

    /*
    * I used the fflush(stdout) comand since the words were 
    * printing one line at a time instead of 1 word at a time
    * - this command helps to 'flush' the output immediately
    */

    sleep(1); //pauses for 1 second 
    printf("Rushil ");
    fflush(stdout);
    sleep(1);
    puts("Karani "); //goes to the next line after printing
    sleep(1);
    printf("Student #: ");
    fflush(stdout);
    sleep(1);
    puts("400508208 ");
    sleep(1);
    printf("Course Name: ");
    fflush(stdout);
    sleep(1);
    printf("Development ");
    fflush(stdout);
    sleep(1);
    printf("Basics - ");
    fflush(stdout);
    sleep(1);
    printf("SFWENG ");
    fflush(stdout);
    sleep(1);
    puts("2XC3");
    sleep(1);

    //q3 reflections questions:
    puts("\nWhat do you think is the most useful thing you’ve learned so far in this course?");
    sleep(1);
    puts("The most usefull feature for me has been integrating VS Code with the Linux command line \nI preffer to use VS Code, but also want to learn about the Linux command line,\ntherefore a platform that integrates both is a useful feature for me.");
    sleep(1);
    puts("\nIs there anything you’ve learned so far that you do not think is useful? If so, explain why.");
    sleep(1);
    puts("I wouldn't say any knowledge is useless, \nhowever I do feel like the material learnt in lab 1.1 would be used less by me, \nespecially in this modern era of technology and better ways to navigate and create software");
    sleep(1);
    puts("\nWhat are the advantages and disadvantages of using vim for coding?");
    sleep(1);
    puts("Vim can work as a text editor, code interpreter which helps with auto indenting and colour coding. \nVim has useful features that help to edit documents fast. However there are disadvantages.\nThe keystrokes could take long to learn and get used to in order to make a good use of them.\nVim also does not support basic commands like undo/redo using Ctrl+Z/Y. \nVim also does not support selecting text with a mouse cursor.");
    sleep(1);
    puts("\nWhat are the advantages and disadvantages of using VS Code for coding?");
    sleep(1);
    puts("VS Code allows easier and more familiar style of editing code (like Ctrl+Z/Y and mouse cursor selection).\nVS Code is also similar to other IDEs which helps users with cross-software \nexperience and makes switching between IDEs easier.\nVS Code however requires significant setup with extentions for each language and plug-in/package \nusers would want to use.");
    return EXIT_SUCCESS;
}
