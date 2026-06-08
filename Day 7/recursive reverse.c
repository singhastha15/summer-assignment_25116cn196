#include <stdio.h>

int reverseNumber(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) * (int)(pow(10, (int)log10(n))) + reverseNumber(n / 10);
}

int main() {
    int number;
    printf("Enter a number to reverse: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Please enter a positive integer.\n");
    } else {
        int result = reverseNumber(number);
        printf("Reversed number of %d is: %d\n", number, result);
    }

    return 0;
}           
