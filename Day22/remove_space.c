#include<stdio.h>

void removespaces(char* str){
    int count = 0;

    for(int i = 0; str[i]; i++){
        if(str[i] !=''){
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
}

int main(){
    char str[] = "Hello World from C";

    printf("Original:%s\n", str);
    removespaces(str);
    printf("Modified:%s\n", str);

    return 0;
}
