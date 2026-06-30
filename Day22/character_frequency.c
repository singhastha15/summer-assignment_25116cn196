#include<stdio.h>
#include<string.h>

int main() {
    char str[100];
    int freq[256] = {0};

    printf("Enter a string:");
    fgets(str, sizeof(str), stdin);

    for(int i = 0; str[i] !='\0'; i++){

        if(str[i] !='\0'; i++) {
            if(str[i] !='\n'){

            }
        }
        printf("\ncharacter Frequencies:\n");
        for(i = 0; i<256; i++){
            if(frequency[i] != 0){
                printf("'%c' :%d\n", i, frequency[i]);
            }
        }
    }
    return 0;
}