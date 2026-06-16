#include<stdio.h>

void moveZerosToEnd(int arr[], int n) {
    int count = 0; // Count of non-zero elements

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i]; // Move non-zero element to the front
        }
    }

    // Fill remaining elements with zeros
    while (count < n) {
        arr[count++] = 0;
    }
}
int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZerosToEnd(arr, n);

    printf("Array after moving zeros to the end: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
