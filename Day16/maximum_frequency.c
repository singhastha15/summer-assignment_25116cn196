#include<stdio.h>

int main() {

int arr[] = {1, 3, 2, 1, 4, 1, 3 ,3, 3, 3};
int n = sizeof(arr) / sizeof(arr[0]);

int max_element = arr[0];
int max_count = 0;

for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) {
        if (arr[i] == arr[j]) {
            count++;
        }
    }
    if (count > max_count) {
        max_count = count;
        max_element = arr[i];
    }
}
printf("The element with maximum frequency is: %d\n", max_element);
printf("Its frequency is: %d\n", max_count);
return 0;
}