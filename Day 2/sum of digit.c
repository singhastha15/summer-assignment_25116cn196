#include<stdio.h>
int main() {
    int num, sum = 0, digit;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    while (num > 0) {
        digit = num % 10; // Get the last digit
        sum += digit;      // Add the digit to the sum
        num /= 10;        // Remove the last digit
    }
    
    printf("The sum of the digits is %d\n", sum);
    return 0;
}