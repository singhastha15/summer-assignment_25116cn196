#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if two strings are anagrams
bool checkAnagram(const char *str1, const char *str2) {
    int i;
    int frequency[256] = {0}; // Initialize count array for all ASCII characters to 0

    // If lengths are different, they cannot be anagrams
    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    // Increment count for first string and decrement for second string
    for (i = 0; str1[i] != '\0'; i++) {
        frequency[(unsigned char)str1[i]]++;
        frequency[(unsigned char)str2[i]]--;
    }

    // If all frequencies are 0, then the strings are anagrams
    for (i = 0; i < 256; i++) {
        if (frequency[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    char str1[100];
    char str2[100];

    printf("Enter the first string: ");
    // Using fgets instead of gets for safety against buffer overflow
    fgets(str1, sizeof(str1), stdin);
    // Remove newline character added by fgets
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    // Call function and display result
    if (checkAnagram(str1, str2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", str1, str2);
    } else {
        printf("\"%s\" and \"%s\" are NOT anagrams.\n", str1, str2);
    }

    return 0;
}
