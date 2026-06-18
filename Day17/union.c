#include<stdio.h>
int main(){
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {4, 5, 6, 7, 8};
    int n1 = 5, n2 = 5;
    int i, j, flag;

    printf("Union: ");

    for(i = 0; i < n1; i++){
        printf("%d ", a[i]);
    }

    for(i = 0; i < n2; i++){
        flag = 0;
        for(j = 0; j < n1; j++){
            if(b[i] == a[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            printf("%d ", b[i]);
        }
    }
    return 0;
}