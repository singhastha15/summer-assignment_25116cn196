#include <stdio.h>
#include <string.h>

#define MAX_SIZE 256  // Define size for the ASCII frequency array

int main() {
    char str[100];
    int freq[MAX_SIZE] = {0}; // Initialize all frequencies to 0
    int i, max_count = 0;
    char max_char = '\0';

    printf("Enter a string: ");
    // Safely read string including spaces, removing trailing newline
    if (fgets(str, sizeof(str), stdin)) {
        str[strcspn(str, "\n")] = '\0';
    }

    // Step 1: Count frequency of each character
    for (i = 0; str[i] != '\0'; i++) {
        // Cast to unsigned char to safely handle characters beyond standard ASCII
        unsigned char index = (unsigned char)str[i];
        freq[index]++;
    }

    // Step 2: Traverse the frequency array to find the maximum occurring character
    for (i = 0; i < MAX_SIZE; i++) {
        if (freq[i] > max_count) {
            max_count = freq[i];
            max_char = (char)i;
        }
    }

    // Output the result
    if (max_count > 0) {
        printf("The maximum occurring character is '%c' (occurs %d times).\n", max_char, max_count);
    } else {
        printf("The string is empty.\n");
    }

    return 0;
}
