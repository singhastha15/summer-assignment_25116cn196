#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, user_guess;
    int attempts = 0;

    // Seed the random number generator using the current system time
    srand(time(NULL));

    // Generate a pseudo-random number between 1 and 100
    secret_number = (rand() % 100) + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have picked a secret number between 1 and 100.\n");
    printf("Can you guess what it is?\n\n");

    // Loop runs continuously until the user guesses the correct number
    do {
        printf("Enter your guess: ");
        
        // Input validation: ensure the user inputs an integer
        if (scanf("%d", &user_guess) != 1) {
            printf("Invalid input! Please enter a valid number.\n\n");
            while (getchar() != '\n'); // Clear the invalid input from the buffer
            continue;
        }

        attempts++; // Increment the try counter

        // Provide feedback based on the guess
        if (user_guess > secret_number) {
            printf("Too high! Try a smaller number.\n\n");
        } else if (user_guess < secret_number) {
            printf("Too low! Try a larger number.\n\n");
        } else {
            printf("\nCongratulations! You guessed the right number!\n");
            printf("Total attempts taken: %d\n", attempts);
        }

    } while (user_guess != secret_number);

    return 0;
}
