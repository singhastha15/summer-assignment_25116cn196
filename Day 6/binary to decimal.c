#include <stdio.h>

int main() {
    long long binary, decimal = 0, base = 1, remainder;
    printf("Enter a binary number: ");
    scanf("%lld", &binary);
    while (binary != 0) {
        remainder = binary % 10;
        decimal += remainder * base;
        binary /= 10;
        base *= 2;
    }
    printf("Decimal representation: %lld\n", decimal);
    return 0;
}
