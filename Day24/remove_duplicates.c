#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str) {
    // Array to keep track of visited characters (ASCII size 256)
    int seen[256] = {0}; 
    
    int targetIndex = 0; // Index to track the position of unique characters

    for (int i = 0; str[i] != '\0'; i++) {
        // Cast to unsigned char to safely handle extended ASCII values
        unsigned char ch = (unsigned char)str[i]; 

        // If the character hasn't been seen before
        if (seen[ch] == 0) {
            seen[ch] = 1;               // Mark it as seen
            str[targetIndex] = str[i]; // Move it to the unique character position
            targetIndex++;             // Increment the target index
        }
    }
    
    // Add the null terminator to mark the end of the modified string
    str[targetIndex] = '\0'; 
}

int main() {
    // Example test string
    char str[] = "programming language"; 
    
    printf("Original String: %s\n", str);
    
    removeDuplicates(str);
    
    printf("String after removing duplicates: %s\n", str);
    
    return 0;
}
