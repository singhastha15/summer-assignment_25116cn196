#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"

// Define the Employee structure
typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

// Function Prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void modifyEmployee();
void deleteEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n=== EMPLOYEE MANAGEMENT SYSTEM ===");
        printf("\n=================================");
        printf("\n1. Add Employee");
        printf("\n2. Display All Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Modify Employee Record");
        printf("\n5. Delete Employee Record");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: modifyEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                printf("\nExiting the program. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

// 1. Function to Add a New Employee Record
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab"); // Open in append-binary mode
    if (fp == NULL) {
        printf("\nError opening file!");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); // Clear trailing newline from buffer

    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Remove newline character

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(Employee), 1, fp);
    fclose(fp);

    printf("\nRecord added successfully!\n");
}

// 2. Function to Display All Employee Records
void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb"); // Open in read-binary mode
    if (fp == NULL) {
        printf("\nNo records found (or file doesn't exist yet).\n");
        return;
    }

    Employee emp;
    printf("\n-------------------------------------------------------------------");
    printf("\n%-10s %-20s %-20s %-12s", "ID", "Name", "Designation", "Salary");
    printf("\n-------------------------------------------------------------------");

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        printf("\n%-10d %-20s %-20s %-12.2f", emp.id, emp.name, emp.designation, emp.salary);
    }
    printf("\n-------------------------------------------------------------------\n");
    fclose(fp);
}

// 3. Function to Search for an Employee by ID
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int searchId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == searchId) {
            found = 1;
            printf("\nRecord Found:");
            printf("\nID: %d", emp.id);
            printf("\nName: %s", emp.name);
            printf("\nDesignation: %s", emp.designation);
            printf("\nSalary: %.2f\n", emp.salary);
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
    fclose(fp);
}

// 4. Function to Modify an Existing Employee Record
void modifyEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb+"); // Open in read-and-write binary mode
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int modifyId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to modify: ");
    scanf("%d", &modifyId);

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == modifyId) {
            found = 1;
            printf("\nCurrent Data: Name: %s, Desg: %s, Salary: %.2f", emp.name, emp.designation, emp.salary);
            
            printf("\n\nEnter New Name: ");
            getchar(); // Clear buffer
            fgets(emp.name, sizeof(emp.name), stdin);
            emp.name[strcspn(emp.name, "\n")] = 0;

            printf("Enter New Designation: ");
            fgets(emp.designation, sizeof(emp.designation), stdin);
            emp.designation[strcspn(emp.designation, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &emp.salary);

            // Move the file pointer back to the start of this specific record
            fseek(fp, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, fp);
            printf("\nRecord updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", modifyId);
    }
    fclose(fp);
}

// 5. Function to Delete an Employee Record
void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    FILE *tempFp = fopen("temp.dat", "wb"); // Temporary file to write remaining data
    if (tempFp == NULL) {
        printf("\nError processing request.");
        fclose(fp);
        return;
    }

    int deleteId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    // Read from original, write to temporary file if ID does not match
    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == deleteId) {
            found = 1; // Skip writing this record to delete it
        } else {
            fwrite(&emp, sizeof(Employee), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILE_NAME);             // Delete old storage file
        rename("temp.dat", FILE_NAME); // Rename temp file to permanent file name
        printf("\nRecord deleted successfully!\n");
    } else {
        remove("temp.dat"); // Clean up the temp file if no match was found
        printf("\nEmployee with ID %d not found.\n", deleteId);
    }
}
