#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIMIT 200

int main() {
    char str[MAX_LIMIT];
    char longest_word[MAX_LIMIT] = "";
    char current_word[MAX_LIMIT];
    
    int max_len = 0;
    int cur_len = 0;
    int i = 0, j = 0;

    printf("Enter a sentence: ");
    // Reads an entire line including spaces safely
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character added by fgets
    str[strcspn(str, "\n")] = '\0';

    int len = strlen(str);

    for (i = 0; i <= len; i++) {
        // Check if character is part of a word (alphanumeric)
        if (isalnum(str[i])) {
            current_word[j++] = str[i];
            cur_len++;
        } 
        // End of a word reached (space, punctuation, or null terminator)
        else {
            if (cur_len > max_len) {
                max_len = cur_len;
                current_word[j] = '\0'; // Null-terminate current word
                strcpy(longest_word, current_word);
            }
            j = 0;       // Reset current word index
            cur_len = 0; // Reset current word length
        }
    }

    if (max_len > 0) {
        printf("The longest word is: %s\n", longest_word);
        printf("Length of the longest word: %d\n", max_len);
    } else {
        printf("No valid words found.\n");
    }

    return 0;
}
