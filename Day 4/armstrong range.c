#include <stdio.h>
#include <math.h>

int main() {
    int start, end, num, originalNum, remainder, result = 0;

    printf("Enter the start and end of the range: ");
    scanf("%d %d", &start, &end);

    printf("Armstrong numbers in the range %d to %d are:\n", start, end);

    for (num = start; num <= end; num++) {
        originalNum = num;
        result = 0;

        while (originalNum != 0) {
            remainder = originalNum % 10;
            result += pow(remainder, 3);
            originalNum /= 10;
        }

        if (result == num)
            printf("%d ", num);
    }

    return 0;
}