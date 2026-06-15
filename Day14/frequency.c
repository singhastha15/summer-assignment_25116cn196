#include<stdio.h>

int main() {
    int arr[] = {1, 2, 8, 3,2, 2, 2, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            count++;
        }
    }

    printf("Frequency of %d is %d\n", target, count);
    return 0;
}