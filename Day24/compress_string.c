#include <stdio.h>
#include <string.h>

void compressString(char *str, char *compressed) {
    int i = 0;
    int j = 0; // Index for compressed string
    int len = strlen(str);

    while (i < len) {
        int count = 1;

        // Count consecutive occurrences of the current character
        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        // Store the character
        compressed[j++] = str[i];

        // Convert count integer to string characters and append
        int charsWritten = sprintf(&compressed[j], "%d", count);
        j += charsWritten;

        i++;
    }
    
    // Add null terminator to the end of compressed string
    compressed[j] = '\0';
}

int main() {
    char str[100];
    char compressed[200]; // Allocation for worst-case growth (e.g., "ABCD" -> "A1B1C1D1")

    printf("Enter a string: ");
    scanf("%99s", str); // Limits reading to avoid buffer overflow

    compressString(str, compressed);

    printf("Original String: %s\n", str);
    printf("Compressed String: %s\n", compressed);

    return 0;
}
