#include<stdio.h>

void fibonacci(int n) {
    int t1 = 0, t2 = 1, next;
    printf("Fibonacci series up to %d terms: ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", t1);
        next = t1 + t2;
        t1 = t2;
        t2 = next;
    }
    printf("\n");
}

int main() {
    int num;
    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        fibonacci(num);
    }

    return 0;
}