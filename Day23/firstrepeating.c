#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256 // Total possible ASCII values

// Function to find the first repeating character
char findFirstRepeating(char *str) {
    // Array to keep track of visited characters initialized to 0 (false)
    int visited[MAX_CHARS] = {0};

    // Traverse the string from left to right
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];

        // If the character is already visited, it is the first repeating one
        if (visited[ch] == 1) {
            return ch;
        }

        // Mark the character as visited
        visited[ch] = 1;
    }

    // Return null character if no repeating character is found
    return '\0'; 
}

int main() {
    char str[100];

    printf("Enter a string: ");
    // Read string including spaces
    fgets(str, sizeof(str), stdin);

    // Remove the newline character added by fgets
    str[strcspn(str, "\n")] = '\0';

    char result = findFirstRepeating(str);

    if (result != '\0') {
        printf("The first repeating character is: '%c'\n", result);
    } else {
        printf("No repeating characters found.\n");
    }

    return 0;
}
