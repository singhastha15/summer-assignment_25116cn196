#include<stdio.h>
int main() {
    int n = 0, digit, reverse = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    while (n > 0) {
        digit = n % 10; // Get the last digit
        reverse = reverse * 10 + digit; // Append the digit to the reverse
        n /= 10; // Remove the last digit
    }
    printf("The reverse of the number is %d\n", reverse);
    return 0;
}