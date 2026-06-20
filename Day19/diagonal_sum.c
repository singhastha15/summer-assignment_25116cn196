#include<stdio.h>

int main(){
    int n, i, j, primarysum = 0, secondarysum = 0;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int matrix;

    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
            if(i == j){
                primarysum += matrix[i][j]; // Sum of primary diagonal
            }
            if(i + j == n - 1){
                secondarysum += matrix[i][j]; // Sum of secondary diagonal
            }
        }
    }
    printf("Sum of the primary diagonal: %d\n", primarysum);
    printf("Sum of the secondary diagonal: %d\n", secondarysum);
    return 0;
}