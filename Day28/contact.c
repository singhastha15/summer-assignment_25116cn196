#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the contact structure
typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} Contact;

// Function prototypes
void addContact();
void displayContacts();
void searchContact();
void deleteContact();

int main() {
    int choice;

    while (1) {
        printf("\n=== CONTACT MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}

// 1. Add a new contact to the text file
void addContact() {
    FILE *fp = fopen("contacts.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Contact c;
    printf("\nEnter Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0'; // Remove newline

    printf("Enter Phone Number: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = '\0';

    // Write structure to file with a comma delimiter
    fprintf(fp, "%s,%s,%s\n", c.name, c.phone, c.email);
    fclose(fp);

    printf("Contact added successfully!\n");
}

// 2. Read and display all contacts
void displayContacts() {
    FILE *fp = fopen("contacts.txt", "r");
    if (fp == NULL) {
        printf("\nNo contacts found. The list is empty!\n");
        return;
    }

    char line[120];
    Contact c;
    int count = 1;

    printf("\n---------------------------------------------------------\n");
    printf("%-5s %-20s %-15s %-20s\n", "S.No", "Name", "Phone", "Email");
    printf("---------------------------------------------------------\n");

    while (fgets(line, sizeof(line), fp)) {
        // Parse the comma-separated line back into variables
        sscanf(line, "%[^,],%[^,],%[^\n]", c.name, c.phone, c.email);
        printf("%-5d %-20s %-15s %-20s\n", count++, c.name, c.phone, c.email);
    }
    
    fclose(fp);
    if (count == 1) {
        printf("No records inside the file.\n");
    }
    printf("---------------------------------------------------------\n");
}

// 3. Search for a contact by name
void searchContact() {
    FILE *fp = fopen("contacts.txt", "r");
    if (fp == NULL) {
        printf("\nNo contacts saved yet!\n");
        return;
    }

    char searchName[50];
    char line[120];
    Contact c;
    int found = 0;

    printf("\nEnter the name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,],%[^,],%[^\n]", c.name, c.phone, c.email);
        // Case-sensitive comparison
        if (strcmp(c.name, searchName) == 0) {
            printf("\nContact Found!\n");
            printf("Name: %s\nPhone: %s\nEmail: %s\n", c.name, c.phone, c.email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
    fclose(fp);
}

// 4. Delete a contact by creating a temporary file
void deleteContact() {
    FILE *fp = fopen("contacts.txt", "r");
    if (fp == NULL) {
        printf("\nNo contacts saved yet!\n");
        return;
    }

    FILE *tempFp = fopen("temp.txt", "w");
    if (tempFp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    char deleteName[50];
    char line[120];
    Contact c;
    int found = 0;

    printf("\nEnter the exact name of the contact to delete: ");
    fgets(deleteName, sizeof(deleteName), stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,],%[^,],%[^\n]", c.name, c.phone, c.email);
        
        // If it matches, skip writing it to the temporary file
        if (strcmp(c.name, deleteName) == 0) {
            found = 1;
        } else {
            fprintf(tempFp, "%s,%s,%s\n", c.name, c.phone, c.email);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove("contacts.txt");         // Delete original file
        rename("temp.txt", "contacts.txt"); // Rename temp to original
        printf("Contact deleted successfully!\n");
    } else {
        remove("temp.txt"); // Clean up temp file
        printf("Contact not found.\n");
    }
}
