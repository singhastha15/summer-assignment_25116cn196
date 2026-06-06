#include <stdio.h>

int main() {
    long long n, i, largest = -1;
    printf("Enter a number: ");
    scanf("%lld", &n);
    for (i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
    }
    if (n > 1) {
        largest = n;
    }
    printf("The largest prime factor is: %lld\n", largest);
    return 0;
}