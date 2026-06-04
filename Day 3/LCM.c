#include  <stdio.h>
int main() {
    int n1, n2, lcm, i;
    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);
    lcm = (n1 > n2) ? n1 : n2; // Start with the greater number

    while (1) {
        if (lcm % n1 == 0 && lcm % n2 == 0) {
            break; // Found the LCM
        }
        lcm++; // Increment to check the next number
    }

    printf("The LCM of %d and %d is %d\n", n1, n2, lcm);
    return 0;
}