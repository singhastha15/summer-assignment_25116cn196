#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function prototypes
void createArray(int arr[], int *n);
void displayArray(int arr[], int n);
void insertElement(int arr[], int *n);
void deleteElement(int arr[], int *n);
void searchElement(int arr[], int n);

int main() {
    int arr[MAX_SIZE];
    int n = 0, choice;

    while (1) {
        printf("\n1. Create 2. Display 3. Insert 4. Delete 5. Search 6. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        switch (choice) {
            case 1: createArray(arr, &n); break;
            case 2: displayArray(arr, n); break;
            case 3: insertElement(arr, &n); break;
            case 4: deleteElement(arr, &n); break;
            case 5: searchElement(arr, n); break;
            case 6: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}

// Function implementations
void createArray(int arr[], int *n) {
    printf("Enter number of elements: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) scanf("%d", &arr[i]);
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insertElement(int arr[], int *n) {
    int pos, val;
    printf("Enter pos and value: ");
    scanf("%d %d", &pos, &val);
    for (int i = *n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
    (*n)++;
}

void deleteElement(int arr[], int *n) {
    int pos;
    printf("Enter index to delete: ");
    scanf("%d", &pos);
    for (int i = pos; i < *n - 1; i++) arr[i] = arr[i + 1];
    (*n)--;
}

void searchElement(int arr[], int n) {
    int key, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) { printf("Found at %d\n", i); found = 1; break; }
    }
    if (!found) printf("Not found\n");
}
