#include<stdio.h>
int main(){
    int n, a[n][n], b[n][n], c[n][n], i, j, k, sum = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the elements of the first matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            a[i][j] + b[i][j] = c[i][j];
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            for(k = 0; k < n; k++){
                sum += a[i][k] * b[k][j];
            d[i][j] = sum;
        }
        sum = 0;
    }
    }
    printf("The addition of two matrices is:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("The multiplication of two matrices is:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }


    return 0;
}