#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Define the Employee structure
struct Employee {
    int id;
    char name[50];
    char designation[30];
    float basic_salary;
    float hra;          // House Rent Allowance
    float da;           // Dearness Allowance
    float pf;           // Provident Fund Deduction
    float gross_salary;
    float net_salary;
};

// Function prototypes
void addEmployee(struct Employee emp[], int *count);
void displayAll(struct Employee emp[], int count);
void searchEmployee(struct Employee emp[], int count);
void calculateSalary(struct Employee *emp);

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int employee_count = 0;
    int choice;

    while (1) {
        printf("\n=========================================");
        printf("\n       SALARY MANAGEMENT SYSTEM          ");
        printf("\n=========================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Employee Payslips");
        printf("\n3. Search Employee by ID");
        printf("\n4. Exit");
        printf("\n=========================================");
        printf("\nEnter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addEmployee(employees, &employee_count);
                break;
            case 2:
                displayAll(employees, employee_count);
                break;
            case 3:
                searchEmployee(employees, employee_count);
                break;
            case 4:
                printf("\nExiting system. Thank you!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to automatically break down salary components
void calculateSalary(struct Employee *emp) {
    // Payroll calculation rules
    emp->hra = emp->basic_salary * 0.15; // 15% HRA
    emp->da = emp->basic_salary * 0.20;  // 20% DA
    emp->pf = emp->basic_salary * 0.12;  // 12% PF Deduction
    
    // Total earnings before deductions
    emp->gross_salary = emp->basic_salary + emp->hra + emp->da;
    
    // Take-home pay after deductions
    emp->net_salary = emp->gross_salary - emp->pf;
}

// Function to register a new employee
void addEmployee(struct Employee emp[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nError: Database is full!\n");
        return;
    }

    struct Employee new_emp;
    
    printf("\nEnter Employee ID: ");
    scanf("%d", &new_emp.id);
    
    // Consume trailing newline character left by scanf
    while (getchar() != '\n'); 
    
    printf("Enter Name: ");
    fgets(new_emp.name, sizeof(new_emp.name), stdin);
    new_emp.name[strcspn(new_emp.name, "\n")] = '\0'; // Remove trailing newline
    
    printf("Enter Designation: ");
    fgets(new_emp.designation, sizeof(new_emp.designation), stdin);
    new_emp.designation[strcspn(new_emp.designation, "\n")] = '\0';

    printf("Enter Basic Salary: ");
    scanf("%f", &new_emp.basic_salary);

    // Run the salary breakdown math
    calculateSalary(&new_emp);

    // Save into the array
    emp[*count] = new_emp;
    (*count)++;
    
    printf("\nEmployee record added successfully!\n");
}

// Function to print a detailed summary of all entries
void displayAll(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo records found!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n-----------------------------------------");
        printf("\n          PAYSLIP FOR ID: %d             ", emp[i].id);
        printf("\n-----------------------------------------");
        printf("\nName:        %s", emp[i].name);
        printf("\nDesignation: %s", emp[i].designation);
        printf("\nBasic Pay:   $%.2f", emp[i].basic_salary);
        printf("\nHRA (15%%):   $%.2f", emp[i].hra);
        printf("\nDA (20%%):    $%.2f", emp[i].da);
        printf("\nPF (12%%):    $%.2f [Deduction]", emp[i].pf);
        printf("\n-----------------------------------------");
        printf("\nGross Pay:   $%.2f", emp[i].gross_salary);
        printf("\nNet Salary:  $%.2f", emp[i].net_salary);
        printf("\n-----------------------------------------\n");
    }
}

// Function to look up an individual employee profile
void searchEmployee(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int search_id, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == search_id) {
            printf("\nRecord Found!");
            // Temporary collection to match display schema
            struct Employee match[1] = {emp[i]};
            displayAll(match, 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", search_id);
    }
}
