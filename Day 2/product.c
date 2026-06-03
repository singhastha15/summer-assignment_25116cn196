#include<stdio.h>
int main() {
    int n, digit, product = 1;
    printf("Enter a number: ");
    scanf("%d", &n);

    while (n > 0) {
        digit = n % 10; // Get the last digit
        product *= digit; // Multiply the digit to the product
        n /= 10; // Remove the last digit
    }
    printf("The product of the digits is %d\n", product);
    return 0;
}