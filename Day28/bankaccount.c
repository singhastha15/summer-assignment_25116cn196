#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankAccount {
    int accountNumber;
    char name[100];
    float balance;
};

void createAccount(struct BankAccount *account) {
    system("cls||clear");
    printf("=== Create Account ===\n");
    printf("Enter Account Number: ");
    scanf("%d", &account->accountNumber);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]s", account->name);
    account->balance = 0.0f;
    printf("\nAccount created successfully for %s!\n", account->name);
}

void checkBalance(struct BankAccount account) {
    system("cls||clear");
    printf("=== Balance Inquiry ===\n");
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Holder: %s\n", account.name);
    printf("Current Balance: $%.2f\n", account.balance);
}

void deposit(struct BankAccount *account) {
    float amount;
    system("cls||clear");
    printf("=== Deposit Funds ===\n");
    printf("Enter amount to deposit: $");
    scanf("%f", &amount);
    
    if (amount > 0) {
        account->balance += amount;
        printf("Successfully deposited $%.2f. New Balance: $%.2f\n", amount, account->balance);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void withdraw(struct BankAccount *account) {
    float amount;
    system("cls||clear");
    printf("=== Withdraw Funds ===\n");
    printf("Enter amount to withdraw: $");
    scanf("%f", &amount);
    
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Successfully withdrawn $%.2f. New Balance: $%.2f\n", amount, account->balance);
    } else if (amount > account->balance) {
        printf("Insufficient balance.\n");
    } else {
        printf("Invalid withdrawal amount.\n");
    }
}

int main() {
    struct BankAccount userAccount;
    int choice;
    int accountCreated = 0;

    do {
        printf("\n=== Bank Management System ===\n");
        printf("1. Create Account\n");
        printf("2. Check Balance\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createAccount(&userAccount);
                accountCreated = 1;
                break;
            case 2:
                if (accountCreated) checkBalance(userAccount);
                else printf("Please create an account first.\n");
                break;
            case 3:
                if (accountCreated) deposit(&userAccount);
                else printf("Please create an account first.\n");
                break;
            case 4:
                if (accountCreated) withdraw(&userAccount);
                else printf("Please create an account first.\n");
                break;
            case 5:
                printf("\nThank you for using our Banking System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}
