#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

int main() {
    char words[MAX_WORDS][MAX_LENGTH];
    char temp[MAX_LENGTH];
    int n, i, j;

    // 1. Get user input
    printf("Enter the number of words: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_WORDS) {
        printf("Invalid number of words.\n");
        return 1;
    }

    printf("Enter %d words:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    // 2. Sort words by length using Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // Compare lengths of adjacent words
            if (strlen(words[j]) > strlen(words[j + 1])) {
                // Swap the words if they are out of order
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    // 3. Print the sorted list
    printf("\nWords sorted by length:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
