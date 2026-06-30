#include <stdio.h>
#include <ctype.h>

#define TOTAL_QUESTIONS 3

// Structure to group question data together
typedef struct {
    char question_text[256];
    char options[4][64];
    char correct_option;
} QuizQuestion;

int main() {
    // Array of quiz structures containing the database of questions
    QuizQuestion quiz[TOTAL_QUESTIONS] = {
        {
            "Which programming language is known as the mother of all languages?",
            {"A. Java", "B. Python", "C. C Language", "D. COBOL"},
            'C'
        },
        {
            "What is the format specifier used to print an integer in C?",
            {"A. %f", "B. %d", "C. %c", "D. %s"},
            'B'
        },
        {
            "Which of the following is not a valid loop structure in C?",
            {"A. for", "B. while", "C. do-while", "D. repeat-until"},
            'D'
        }
    };

    char user_guess;
    int current_score = 0;

    printf("=========================================\n");
    printf("     WELCOME TO THE C PROGRAMMING QUIZ    \n");
    printf("=========================================\n\n");

    // Loop through each question sequentially
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].question_text);
        
        // Print the 4 multiple choice options
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        // Input validation and buffer handling loop
        while (1) {
            printf("Enter your choice (A, B, C, or D): ");
            scanf(" %c", &user_guess); // Notice the leading space to skip newlines
            
            // Standardize lower case entries into upper case
            user_guess = toupper(user_guess);

            if (user_guess == 'A' || user_guess == 'B' || user_guess == 'C' || user_guess == 'D') {
                break;
            }
            printf("Invalid entry! Please choose only A, B, C, or D.\n");
        }

        // Evaluate user answer against the stored correct character
        if (user_guess == quiz[i].correct_option) {
            printf("\n--> Correct answer!\n\n");
            current_score++;
        } else {
            printf("\n--> Wrong answer! The correct option was %c.\n\n", quiz[i].correct_option);
        }
        printf("-----------------------------------------\n");
    }

    // Final scorecard overview
    printf("\n=========================================\n");
    printf("               QUIZ OVER!                \n");
    printf("=========================================\n");
    printf("Your final score is: %d out of %d\n", current_score, TOTAL_QUESTIONS);
    printf("Percentage scored: %.2f%%\n", ((float)current_score / TOTAL_QUESTIONS) * 100);
    printf("=========================================\n");

    return 0;
}
