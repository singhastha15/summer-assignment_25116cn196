#include<stdio.h>
#include<math.h>

int isarmstrong(int num) {
    int originalnum = num;
    int sum = 0;
    int n = 0;

    // Count the number of digits
    while (originalnum != 0) {
        originalnum /= 10;
        n++;
    }

    originalnum = num; // Reset to original number

    // Calculate the sum of the nth powers of the digits
    while (originalnum != 0) {
        int digit = originalnum % 10;
        sum += pow(digit, n);
        originalnum /= 10;
    }

    return sum == num; // Return true if it's an Armstrong number
}