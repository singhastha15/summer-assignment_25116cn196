#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"

// Structure to define a student record
typedef struct {
    int roll_no;
    char name[50];
    float cgpa;
} Student;

// Function prototypes
void add_student();
void display_students();
void search_student();
void delete_student();

int main() {
    int choice;
    
    while(1) {
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting.\n");
            break;
        }

        switch(choice) {
            case 1: add_student(); break;
            case 2: display_students(); break;
            case 3: search_student(); break;
            case 4: delete_student(); break;
            case 5: printf("Exiting system. Goodbye!\n"); exit(0);
            default: printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

// 1. Add a new student record to the binary file
void add_student() {
    FILE *fp = fopen(FILE_NAME, "ab"); // Append binary mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll_no);
    getchar(); // Clear newline character from buffer

    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Strip trailing newline

    printf("Enter CGPA: ");
    scanf("%f", &s.cgpa);

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Record added successfully!\n");
}

// 2. Read and display all student records
void display_students() {
    FILE *fp = fopen(FILE_NAME, "rb"); // Read binary mode
    if (fp == NULL) {
        printf("\nNo records found! Add a student first.\n");
        return;
    }

    Student s;
    printf("\n%-10s %-30s %-5s\n", "Roll No", "Name", "CGPA");
    printf("--------------------------------------------------\n");

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        printf("%-10d %-30s %-5.2f\n", s.roll_no, s.name, s.cgpa);
    }
    fclose(fp);
}

// 3. Search for a specific student record
void search_student() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int target_roll;
    int found = 0;
    Student s;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &target_roll);

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.roll_no == target_roll) {
            printf("\nRecord Found:\n");
            printf("Roll No: %d\nName: %s\nCGPA: %.2f\n", s.roll_no, s.name, s.cgpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with Roll No %d not found.\n", target_roll);
    }
    fclose(fp);
}

// 4. Delete a student record using a temporary file
void delete_student() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found to delete!\n");
        return;
    }

    FILE *temp_fp = fopen("temp.dat", "wb"); // Write binary mode
    if (temp_fp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    int target_roll;
    int found = 0;
    Student s;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &target_roll);

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.roll_no == target_roll) {
            found = 1; // Skip writing this record to the temp file
        } else {
            fwrite(&s, sizeof(Student), 1, temp_fp);
        }
    }

    fclose(fp);
    fclose(temp_fp);

    if (found) {
        remove(FILE_NAME);             // Delete old database
        rename("temp.dat", FILE_NAME); // Promote temp file to main database
        printf("\nRecord deleted successfully!\n");
    } else {
        remove("temp.dat"); // Clean up temp file
        printf("\nStudent with Roll No %d not found.\n", target_roll);
    }
}
