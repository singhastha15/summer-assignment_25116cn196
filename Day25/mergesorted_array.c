#include <stdio.h>

// Function to merge two sorted arrays
void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int arr3[]) {
    int i = 0; // Index pointer for arr1
    int j = 0; // Index pointer for arr2
    int k = 0; // Index pointer for arr3

    // Traverse both arrays simultaneously
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    // Store remaining elements of the first array, if any
    while (i < n1) {
        arr3[k++] = arr1[i++];
    }

    // Store remaining elements of the second array, if any
    while (j < n2) {
        arr3[k++] = arr2[j++];
    }
}

int main() {
    int n1, n2;

    // Input size and elements of the first sorted array
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter %d sorted elements for the first array:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input size and elements of the second sorted array
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter %d sorted elements for the second array:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Array to store the final merged result
    int arr3[n1 + n2];

    // Call the merge function
    mergeSortedArrays(arr1, n1, arr2, n2, arr3);

    // Print the final sorted merged array
    printf("\nThe merged sorted array is:\n");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    return 0;
}
