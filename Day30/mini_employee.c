#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Define the Employee structure
struct Employee {
    int id;
    char name[50];
    char department[30];
    float salary;
};

// Global variables to store data
struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void deleteEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n=== Employee Management System ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: printf("Exiting system. Goodbye!\n"); return 0;
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a new employee record
void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Error: System storage full!\n");
        return;
    }

    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);

    // Check if ID already exists
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == emp.id) {
            printf("Error: Employee ID %d already exists!\n", emp.id);
            return;
        }
    }

    printf("Enter Name: ");
    getchar(); // Clear newline buffer
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Department: ");
    fgets(emp.department, sizeof(emp.department), stdin);
    emp.department[strcspn(emp.department, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    employees[employeeCount] = emp;
    employeeCount++;
    printf("Employee added successfully!\n");
}

// Function to display all employee records
void displayEmployees() {
    if (employeeCount == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-10d %-20s %-20s $%-9.2f\n", 
               employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
    }
}

// Function to search for an employee by ID
void searchEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int searchId;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == searchId) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\nName: %s\nDepartment: %s\nSalary: $%.2f\n", 
                   employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", searchId);
}

// Function to delete an employee record
void deleteEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records available to delete.\n");
        return;
    }

    int deleteId, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == deleteId) {
            found = 1;
            // Shift remaining elements left to fill the gap
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee record deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", deleteId);
    }
}
