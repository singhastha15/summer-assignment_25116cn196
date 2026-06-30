#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double num1, num2, result;

    // The do-while loop ensures the menu displays at least once
    // and keeps running until the user decides to exit.
    do {
        // Displaying the interactive menu
        printf("\n=============================\n");
        printf("    MENU-DRIVEN CALCULATOR   \n");
        printf("=============================\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // If user wants to exit, terminate the loop immediately
        if (choice == 5) {
            printf("\nThank you for using the calculator. Goodbye!\n");
            break;
        }

        // Check if the input choice falls outside valid menu options
        if (choice < 1 || choice > 5) {
            printf("\nError: Invalid choice! Please select an option between 1 and 5.\n");
            continue; // Skip the rest of the loop and re-display the menu
        }

        // Get operands from the user
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        // Process calculation based on user selection
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("\nResult: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                result = num1 - num2;
                printf("\nResult: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;
                printf("\nResult: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                // Runtime safety: Validate that denominator is not zero
                if (num2 != 0.0) {
                    result = num1 / num2;
                    printf("\nResult: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                } else {
                    printf("\nError: Division by zero is mathematically undefined!\n");
                }
                break;

            default:
                printf("\nAn unexpected error occurred.\n");
        }

    } while (choice != 5);

    return 0;
}
