#include<stdio.h>
#include<ctype.h>

int main(){
    char str[100];
    int i = 0;

    printf("Enter a string in lowercase:");
    fgets(str, sizeof(str), stdin);

    while(str[i]){

        str[i] = toupper(str[i]);
        i++;
    }

    printf("Uppercase string: %s", str);
    return 0;
}