#include<stdio.h>
int main() {
    int lower, upper, i, j, isPrime;
    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &lower, &upper);

    printf("Prime numbers between %d and %d are: ", lower, upper);
    for (i = lower; i <= upper; ++i) {
        isPrime = 1;
        if (i <= 1) {
            isPrime = 0;
        } else {
            for (j = 2; j <= i / 2; ++j) {
                if (i % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
        }
        if (isPrime) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}