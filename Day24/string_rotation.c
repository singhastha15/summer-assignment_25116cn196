#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if str2 is a rotation of str1
int isRotation(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If lengths are not equal, they cannot be rotations of each other
    if (len1 != len2) {
        return 0;
    }

    // Allocate memory for the concatenated string (len1 * 2 + 1 for null-terminator)
    char *temp = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    // Initialize temp as an empty string, then copy and concatenate str1
    temp[0] = '\0';
    strcpy(temp, str1);
    strcat(temp, str1);

    // Check if str2 is a substring of the concatenated string
    // strstr returns a pointer if found, otherwise returns NULL
    char *ptr = strstr(temp, str2);

    // Free dynamically allocated memory to avoid memory leaks
    free(temp);

    // Return 1 (true) if found, 0 (false) otherwise
    return (ptr != NULL) ? 1 : 0;
}

int main() {
    char str1[100], str2[100];

    // Take user inputs
    printf("Enter the first string: ");
    scanf("%99s", str1);

    printf("Enter the second string: ");
    scanf("%99s", str2);

    // Evaluate and print results
    if (isRotation(str1, str2)) {
        printf("'%s' IS a rotation of '%s'\n", str2, str1);
    } else {
        printf("'%s' is NOT a rotation of '%s'\n", str2, str1);
    }

    return 0;
}
