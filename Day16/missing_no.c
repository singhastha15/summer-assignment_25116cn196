#include<stdio.h>

int findMissingNumber(int arr[], int n) {
    int total = (n + 1) * (n + 2) / 2; // Sum of first n+1 natural numbers
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Sum of elements in the array
    }

    return total - sum; // The missing number is the difference
}

int main() {
    int arr[] = {1, 2, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int missing = findMissingNumber(arr, n);
    printf("The missing number is: %d\n", missing);

    return 0;
}