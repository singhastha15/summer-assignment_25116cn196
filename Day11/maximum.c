#include<stdio.h>

int findmax(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int num1, num2, max;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    max = findmax(num1, num2);
    printf("The maximum of %d and %d is: %d\n", num1, num2, max);

    return 0;
}