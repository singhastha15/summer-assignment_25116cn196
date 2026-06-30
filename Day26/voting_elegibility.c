#include <stdio.h>

int main() {
    int age;

    // Prompt the user to enter their age
    printf("Enter your age: ");
    scanf("%d", &age);

    // Check if the age is 18 or older
    if (age >= 18) {
        printf("Congratulations! You are eligible to vote.\n");
    } 
    else if (age > 0 && age < 18) {
        printf("Sorry, you are not eligible to vote.\n");
        printf("You must wait %d more year(s) to vote.\n", 18 - age);
    } 
    else {
        printf("Invalid age entered. Please enter a positive number.\n");
    }

    return 0;
}
