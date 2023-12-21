#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>

int main() {
    // String Manipulation
    char str1[50] = "Hello";
    char str2[] = " World!";
    strcat(str1, str2); // Concatenate strings
    printf("%s\n", str1);

    // Memory Management
    char *dynamicStr = malloc(strlen(str1) + 1);
    strcpy(dynamicStr, str1); // Copy string
    printf("%s\n", dynamicStr);
    free(dynamicStr); // Always free dynamically allocated memory

    // Mathematical Operations
    double squareRoot = sqrt(16.0); // Square root
    printf("The square root of 16 is %.2f\n", squareRoot);

    // Character Classification and Conversion
    char ch = 'a';
    if (isalpha(ch)) { // Check if the character is alphabetic
        ch = toupper(ch); // Convert character to uppercase
        printf("Uppercase: %c\n", ch);
    }

    // Time Management
    time_t now;
    time(&now); // Get the current time
    printf("Current time: %s", ctime(&now)); // Convert time_t to string

    // File I/O
    const char *filename = "example.txt";
    FILE *file = fopen(filename, "w"); // Open a file for writing
    if (file == NULL) {
        perror("Error opening file"); // Print error message
        return EXIT_FAILURE;
    }
    fprintf(file, "Current time: %s", ctime(&now)); // Write to file
    fclose(file); // Close the file

    // Read the same file and print its contents
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);

    // Error Handling
    FILE *invalidFile = fopen("/invalid/path/to/file", "r");
    if (invalidFile == NULL) {
        printf("Error opening file: %s\n", strerror(errno)); // Get the error message string
    }

    // Mathematical computation using trigonometry
    double angle = 45.0; // Angle in degrees
    double radians = angle * (M_PI / 180.0); // Convert degrees to radians
    printf("The sine of %.2f degrees is %.2f\n", angle, sin(radians));

    return 0;
}
