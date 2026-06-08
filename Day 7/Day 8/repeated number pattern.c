#include <stdio.h>

int main() {
    int rows = 5;
    printf("Enter the number of rows for the repeated number pattern: ");
    scanf("%d", &rows);

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}