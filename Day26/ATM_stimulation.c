#include <stdio.h>
#include <stdlib.h>

// Function declarations
void checkBalance(double balance);
double depositMoney(double balance);
double withdrawMoney(double balance);

int main() {
    // Initial configuration
    const int CORRECT_PIN = 1234;
    double balance = 5000.00; 
    int enteredPin;
    int pinAttempts = 0;
    int choice;
    int continueTransaction = 1;

    printf("=========================================\n");
    printf("       WELCOME TO THE EMERALD BANK       \n");
    printf("=========================================\n");

    // PIN Authentication Phase (Max 3 attempts)
    while (pinAttempts < 3) {
        printf("\nPlease enter your 4-digit PIN: ");
        if (scanf("%d", &enteredPin) != 1) {
            printf("Invalid input. Please enter numbers only.\n");
            while (getchar() != '\n'); // Clear input buffer
            pinAttempts++;
            continue;
        }

        if (enteredPin == CORRECT_PIN) {
            printf("\nAccess Granted! Welcome to your account.\n");
            break;
        } else {
            pinAttempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n", 3 - pinAttempts);
        }
    }

    // Card locking check
    if (pinAttempts == 3 && enteredPin != CORRECT_PIN) {
        printf("\n=========================================\n");
        printf("ERROR: Too many incorrect PIN attempts.\n");
        printf("Your card has been blocked for safety reasons.\n");
        printf("Please contact your nearest bank branch.\n");
        printf("=========================================\n");
        return 0;
    }

    // Main ATM Operation Loop
    while (continueTransaction) {
        printf("\n************ ATM SERVICES ************\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit Terminal\n");
        printf("**************************************\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = depositMoney(balance);
                break;
            case 3:
                balance = withdrawMoney(balance);
                break;
            case 4:
                printf("\nThank you for choosing Emerald Bank. Goodbye!\n");
                continueTransaction = 0;
                break;
            default:
                printf("\nInvalid option. Please choose a number between 1 and 4.\n");
        }

        // Check if user wants another transaction before closing
        if (continueTransaction != 0) {
            int submenuChoice;
            printf("\nDo you want to perform another transaction?\n");
            printf("1. Yes\n2. No\nYour choice: ");
            scanf("%d", &submenuChoice);
            if (submenuChoice != 1) {
                printf("\nThank you for using our ATM. Have a great day!\n");
                continueTransaction = 0;
            }
        }
    }

    return 0;
}

// Function to print the current account balance
void checkBalance(double balance) {
    printf("\nCurrent Balance: $%.2f\n", balance);
}

// Function to safely deposit money
double depositMoney(double balance) {
    double depositAmount;
    printf("\nEnter amount to deposit: $");
    scanf("%lf", &depositAmount);

    if (depositAmount <= 0) {
        printf("Transaction Denied: Invalid deposit amount.\n");
    } else {
        balance += depositAmount;
        printf("Success: $%.2f deposited successfully.\n", depositAmount);
        printf("New Balance: $%.2f\n", balance);
    }
    return balance;
}

// Function to safely withdraw money with system checks
double withdrawMoney(double balance) {
    double withdrawAmount;
    printf("\nEnter amount to withdraw: $");
    scanf("%lf", &withdrawAmount);

    if (withdrawAmount <= 0) {
        printf("Transaction Denied: Invalid withdrawal amount.\n");
    } else if (withdrawAmount > balance) {
        printf("Transaction Denied: Insufficient funds available.\n");
        printf("Your current balance is $%.2f\n", balance);
    } else {
        balance -= withdrawAmount;
        printf("Success: Please collect your cash.\n");
        printf("Remaining Balance: $%.2f\n", balance);
    }
    return balance;
}
