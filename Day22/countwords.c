#include<stdio.h>
#include<string.h>

int main(){
    char str[200];
    int i, word = 0;

    printf("Enter a sentence:");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        if(str[i] == '' && str[i+1] != '' && str[i+1] != '\0'){
            words++;
        }
    }

    if(strlen(str)>0){
        words++;
    }

    printf("Total number of words: %d\n", words);
    return 0;
}