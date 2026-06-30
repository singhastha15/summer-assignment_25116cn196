#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256 // To handle all standard ASCII characters

void findCommonCharacters(char str1[], char str2[]) {
    int freq1[MAX_CHAR] = {0};
    int freq2[MAX_CHAR] = {0};
    int found = 0;

    // 1. Count character frequencies in the first string
    for (int i = 0; str1[i] != '\0'; i++) {
        freq1[(unsigned char)str1[i]]++;
    }

    // 2. Count character frequencies in the second string
    for (int i = 0; str2[i] != '\0'; i++) {
        freq2[(unsigned char)str2[i]]++;
    }

    // 3. Print common characters based on the minimum occurrence in both
    printf("Common characters: ");
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq1[i] > 0 && freq2[i] > 0) {
            // If you only want unique characters, print the character once:
            printf("%c ", i);
            found = 1;
            
            /* 
               Alternative: If you want to include duplicates (like LeetCode 1002), 
               uncomment the loop below instead of the printf above:
               
               int min_count = (freq1[i] < freq2[i]) ? freq1[i] : freq2[i];
               for (int j = 0; j < min_count; j++) {
                   printf("%c ", i);
               }
            */
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    char string1[] = "programming";
    char string2[] = "gaming console";

    printf("String 1: %s\n", string1);
    printf("String 2: %s\n", string2);

    findCommonCharacters(string1, string2);

    return 0;
}
