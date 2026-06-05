#include <stdio.h>

int main() {
    int n, a = 0, b = 1, next;
    printf("Enter the position of the term to find: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    if (n == 1) {
        printf("The %dth Fibonacci number is: %d\n", n, a);
        return 0;
    }

    if (n == 2) {
        printf("The %dth Fibonacci number is: %d\n", n, b);
        return 0;
    }

    for (int i = 2; i < n; i++) {
        next = a + b;
        a = b;
        b = next;
    }

    printf("The %dth Fibonacci number is: %d\n", n, b);
    return 0;
}