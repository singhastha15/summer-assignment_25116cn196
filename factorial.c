#include<stdio.h>
int main() {
    int n, i, factorial = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Error! Factorial of a negative number doesn't exist.\n");
    } else {
        for (i = 1; i <= n; ++i) {
            factorial *= i;
        }
        printf("Factorial of %d = %d\n", n, factorial);
    }
    return 0;
}