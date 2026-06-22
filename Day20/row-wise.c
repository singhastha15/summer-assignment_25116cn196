#include<stdio.h>
int main(){

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nRow-wise sums:\n");
    for(i = 0; i < rows; i++){
        int rowSum = 0;
        for(j = 0; j < cols; j++){
            rowSum += matrix[i][j];
        }
        printf("Row %d: %d\n", i+1, rowSum);
    }
    return 0;
}