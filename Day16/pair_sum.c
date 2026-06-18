#include<stdio.h>

void findPairsWithSum(int arr[], int n, int target) {
    printf("Pairs with sum %d are:\n", target);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    findPairsWithSum(arr, n, target);

    return 0;
}