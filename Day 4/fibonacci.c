#include <stdio.h>
int main() {
    int n, a = 0, b = 1, next;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i; // The first two terms are 0 and 1
        } else {
            next = a + b; // Calculate the next term
            a = b; // Update a to the previous term
            b = next; // Update b to the current term
        }
        printf("%d ", next);
    }
    printf("\n");
    return 0;
}