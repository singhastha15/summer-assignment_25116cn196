#include<stdio.h>
int main(){
    int rows, cols, i, j;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nColumn-wise sums:\n");
    for(j = 0; j < cols; j++){
        int colSum = 0;
        for(i = 0; i < rows; i++){
            colSum += matrix[i][j];
        }
        printf("Column %d: %d\n", j+1, colSum);
    }
    return 0;
}