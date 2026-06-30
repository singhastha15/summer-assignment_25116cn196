#include <stdio.h>
#include <string.h>

// Helper function to remove trailing newline characters from fgets
void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    char str1[100], str2[100], result[200];
    int choice;

    do {
        // Displaying Menu Options
        printf("\n==================================\n");
        printf("     STRING OPERATION SYSTEM     \n");
        printf("==================================\n");
        printf("1. Find Length of a String\n");
        printf("2. Copy String\n");
        printf("3. Concatenate Two Strings\n");
        printf("4. Compare Two Strings\n");
        printf("5. Reverse a String\n");
        printf("6. Exit\n");
        printf("==================================\n");
        printf("Enter your choice (1-6): ");
        
        // Read user option safely
        if (scanf("%d", &choice) != 1) {
            printf("Invalid data input! Exiting program.\n");
            break;
        }
        
        // Consume left-over newline character in the input buffer
        getchar(); 

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                fgets(str1, sizeof(str1), stdin);
                removeNewline(str1);
                
                printf("Length of the string: %lu\n", strlen(str1));
                break;

            case 2:
                printf("\nEnter the source string to copy: ");
                fgets(str1, sizeof(str1), stdin);
                removeNewline(str1);
                
                strcpy(str2, str1);
                printf("Successfully copied! Target String: \"%s\"\n", str2);
                break;

            case 3:
                printf("\nEnter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                removeNewline(str1);
                
                printf("Enter the second string to append: ");
                fgets(str2, sizeof(str2), stdin);
                removeNewline(str2);
                
                // Copy first string to safe result buffer to avoid buffer overflow
                strcpy(result, str1);
                strcat(result, str2);
                printf("Concatenated Result: \"%s\"\n", result);
                break;

            case 4:
                printf("\nEnter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                removeNewline(str1);
                
                printf("Enter the second string: ");
                fgets(str2, sizeof(str2), stdin);
                removeNewline(str2);
                
                int cmp = strcmp(str1, str2);
                if (cmp == 0) {
                    printf("Result: Both strings are exactly equal.\n");
                } else if (cmp > 0) {
                    printf("Result: First string is lexicographically greater.\n");
                } else {
                    printf("Result: Second string is lexicographically greater.\n");
                }
                break;

            case 5:
                printf("\nEnter a string to reverse: ");
                fgets(str1, sizeof(str1), stdin);
                removeNewline(str1);
                
                int len = strlen(str1);
                printf("Reversed String: ");
                for (int i = len - 1; i >= 0; i--) {
                    putchar(str1[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("\nExiting the system. Goodbye!\n");
                break;

            default:
                printf("\nInvalid selection! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
