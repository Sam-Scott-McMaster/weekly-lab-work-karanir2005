#!/bin/bash

#Question 2 Lab 1.1


current_dir=$(pwd) #variable to store current directory

#asks user for directory to cleanup and saves the directory in variable
echo "Which directory would you like to clean?: "
read target_dir

# goes to the required directory and cleans the .tmp files
cd "$target_dir";
find . -type f -name "*.tmp" -exec rm {} \;
echo "Process completed!"

# goes back to the old directory
cd "$original_dir"
