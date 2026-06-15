#include<stdio.h

int main(){
int arr[] = {10, 23, 45, 70, 11, 15};
int target = 70;
int n = sizeof(arr) / sizeof(arr[0]);
int found = -1;

for(int i=0; i<n; i++){
    if(arr[i] == target){
        found = i;
        break;
    }
}
if(found != -1){
    printf("Element found at index %d\n", found);
} else {
    printf("Element not found\n");
}
return 0;
}