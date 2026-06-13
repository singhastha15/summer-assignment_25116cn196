#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool ispalindrome(char str[]) {
    int low = 0;
    int high = strlen(str) - 1;
    while (low < high) {
        if (str[low++] != str[high]) {
            return false;
        }
    }
    return true;
}

int main() {
    char word[100];
    printf("Enter a string to check if it's a palindrome: ");
    scanf("%s", word);

    if (ispalindrome(word)) {
        printf("%s is a palindrome.\n", word);
    } else {
        printf("%s is not a palindrome.\n", word);
    }

    return 0;
}