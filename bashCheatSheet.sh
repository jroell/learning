#!/bin/bash

# String Manipulation
str1="Hello"
str2=" World!"
combined="$str1$str2" # Concatenate strings
echo "$combined"

# Memory Management is not a concept in shell scripting as it is in C.

# Mathematical Operations
squareRoot=$(echo "scale=2; sqrt(16)" | bc) # Calculate square root
echo "The square root of 16 is $squareRoot"

# Character Classification and Conversion
ch='a'
if [[ "$ch" =~ [[:alpha:]] ]]; then # Check if the character is alphabetic
    ch=$(echo "$ch" | tr '[:lower:]' '[:upper:]') # Convert character to uppercase
    echo "Uppercase: $ch"
fi

# Time Management
now=$(date) # Get the current time
echo "Current time: $now"

# File I/O
filename="example.txt"
echo "Current time: $now" > "$filename" # Write to file

# Read the same file and print its contents
while IFS= read -r line; do
    echo "$line"
done < "$filename"

# Error Handling
if ! invalidFile=$(cat /invalid/path/to/file 2>&1); then
    echo "Error opening file: $invalidFile"
fi

# Mathematical computation using trigonometry
angle=45 # Angle in degrees
radians=$(echo "$angle*3.14159265/180" | bc -l) # Convert degrees to radians
sine=$(echo "scale=2; s($radians)" | bc -l) # Calculate sine
echo "The sine of $angle degrees is $sine"

