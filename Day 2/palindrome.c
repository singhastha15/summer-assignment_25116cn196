#include<stdio.h>
int main() {
    int num, originalNum, reverse = 0, digit;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    originalNum = num; // Store the original number for comparison
    
    while (num > 0) {
        digit = num % 10; // Get the last digit
        reverse = reverse * 10 + digit; // Append the digit to the reverse
        num /= 10; // Remove the last digit
    }
    
    if (originalNum == reverse) {
        printf("%d is a palindrome.\n", originalNum);
    } else {
        printf("%d is not a palindrome.\n", originalNum);
    }
    
    return 0;
}