#include <stdio.h>
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1; // Increment count if the last bit is 1
        n >>= 1; // Right shift n by 1 to check the next bit
    }
    return count;
}
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    int setBits = countSetBits(number);
    printf("Number of set bits in %d is: %d\n", number, setBits);
    return 0;
}