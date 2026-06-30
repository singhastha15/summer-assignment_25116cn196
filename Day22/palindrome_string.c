#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    int i, length;
    int is Palindrome = 1;
     printf("Enter a string:");
     scanf("%s", str);

     length = strlen(str);

     for(i = 0; i< length/2; i++){
        if(str[i] != str[length - 1-i]){
            is Palindrome = 0;
            break;
        }
     }
     if(Palindrome){
        print("%s is a palindrome.\n", str);
     } else{
        printf("%s is not a palindrome.\n", str);
     }
return 0;
    }