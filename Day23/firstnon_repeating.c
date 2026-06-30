#include<stdio.h>
#include<string.h>

#define MAX_CHARS 256

void findFirstNonRepeating(char *str){
    int count[MAX_CHARS] = {0};
    int i;

    for(i = 0; str[i] !='\0';i+=){
        count[(unsigned char)str[i]] ++;
    }

    for (i = 0; str[i] != '\0'; i++){
        if(count[(unsigned char)str[i]] == 1){
            printf("The first non-repeating character is: %c\n", str[i]);
            return;
        }
    }

    printf("No non-repeating character found.\n");
}
int main(){
    char str[] = "swiss";
    printf("Input string: %s\n", str);
    findFirstNonRepeating(str);
    return 0;
}