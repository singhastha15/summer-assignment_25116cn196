#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Structure to define a student record
struct Student {
    int rollNumber;
    char name[NAME_LENGTH]; // String implemented as a character array
    float marks;
};

// Function prototypes
void addStudentRecord(struct Student students[], int *count);
void displayAllRecords(const struct Student students[], int count);
void searchStudentByRoll(const struct Student students[], int count);

int main() {
    struct Student database[MAX_STUDENTS]; // Array of structures
    int studentCount = 0;
    int choice;

    do {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudentRecord(database, &studentCount);
                break;
            case 2:
                displayAllRecords(database, studentCount);
                break;
            case 3:
                searchStudentByRoll(database, studentCount);
                break;
            case 4:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a new record to the array
void addStudentRecord(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Database full! Cannot add more student records.\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[*count].rollNumber);
    
    // Clear input buffer newline character before reading a string
    getchar(); 

    printf("Enter Student Name: ");
    // Safely read string with spaces up to buffer limits
    fgets(students[*count].name, NAME_LENGTH, stdin);
    // Remove the trailing newline character captured by fgets
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';

    printf("Enter Marks: ");
    scanf("%f", &students[*count].marks);

    (*count)++; // Increment total records
    printf("Record added successfully!\n");
}

// Function to print all records
void displayAllRecords(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records found in the database.\n");
        return;
    }

    printf("\n%-10s %-30s %-10s\n", "Roll No", "Name", "Marks");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-10.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
    }
}

// Function to look up a student using linear search
void searchStudentByRoll(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int targetRoll;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &targetRoll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == targetRoll) {
            printf("\nRecord Found!\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name       : %s\n", students[i].name);
            printf("Marks      : %.2f\n", students[i].marks);
            found = 1;
            break; // Exit loop early once matched
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", targetRoll);
    }
}
