#include<stdio.h>

int main(){
    int rows, cols, i, j;
     
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int A[rows][cols], B[rows][cols], C[rows][cols];
    printf("Enter the elements of the first matrix:\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            scanf("%d", &B[i][j]);
        }
    }
    // Subtracting the two matrices
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    printf("Result of subtraction:\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}