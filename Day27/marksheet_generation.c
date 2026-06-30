#include <stdio.h>
#include <string.h>

#define MAX_SUBJECTS 5
#define MAX_NAME 50

// Structure to hold student data
struct Student {
    int rollNumber;
    char name[MAX_NAME];
    float marks[MAX_SUBJECTS];
    float total;
    float percentage;
    char grade;
    int isPassed;
};

// Function prototypes
void inputStudentData(struct Student *s);
void calculateResults(struct Student *s);
void displayMarksheet(const struct Student *s);

int main() {
    int numStudents;

    printf("=========================================\n");
    printf("   STUDENT MARKSHEET GENERATION SYSTEM   \n");
    printf("=========================================\n");
    
    printf("Enter the number of students: ");
    if (scanf("%d", &numStudents) != 1 || numStudents <= 0) {
        printf("Invalid number of students. Exiting.\n");
        return 1;
    }

    struct Student students[numStudents];

    // Input and process data for each student
    for (int i = 0; i < numStudents; i++) {
        printf("\n--- Entering Details for Student %d ---\n", i + 1);
        inputStudentData(&students[i]);
        calculateResults(&students[i]);
    }

    // Display marksheets for all students
    printf("\n\n=========================================");
    printf("\n           GENERATED MARKSHEETS          ");
    printf("\n=========================================");
    for (int i = 0; i < numStudents; i++) {
        displayMarksheet(&students[i]);
    }

    return 0;
}

// Function to take student inputs
void inputStudentData(struct Student *s) {
    printf("Enter Roll Number: ");
    scanf("%d", &s->rollNumber);
    
    // Clear input buffer before reading string
    while (getchar() != '\n'); 
    
    printf("Enter Student Name: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter marks for %d subjects (out of 100):\n", MAX_SUBJECTS);
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        do {
            printf("  Subject %d: ", i + 1);
            scanf("%f", &s->marks[i]);
            if (s->marks[i] < 0 || s->marks[i] > 100) {
                printf("  Invalid marks! Please enter between 0 and 100.\n");
            }
        } while (s->marks[i] < 0 || s->marks[i] > 100);
    }
}

// Function to calculate total, percentage, grade, and status
void calculateResults(struct Student *s) {
    s->total = 0;
    s->isPassed = 1; // Assume passed initially

    for (int i = 0; i < MAX_SUBJECTS; i++) {
        s->total += s->marks[i];
        // Fail if marks in any subject are less than 40
        if (s->marks[i] < 40.0) {
            s->isPassed = 0;
        }
    }

    s->percentage = (s->total / (MAX_SUBJECTS * 100.0)) * 100.0;

    // Grade logic (Only gets an academic grade if passed all subjects)
    if (s->isPassed == 0) {
        s->grade = 'F'; 
    } else if (s->percentage >= 90) {
        s->grade = 'A';
    } else if (s->percentage >= 75) {
        s->grade = 'B';
    } else if (s->percentage >= 50) {
        s->grade = 'C';
    } else {
        s->grade = 'D';
    }
}

// Function to print a neatly formatted report card
void displayMarksheet(const struct Student *s) {
    printf("\n-----------------------------------------");
    printf("\n              REPORT CARD                ");
    printf("\n-----------------------------------------");
    printf("\n Roll No: %-10d Name: %s", s->rollNumber, s->name);
    printf("\n-----------------------------------------");
    printf("\n Subject      | Marks Obtained (Out of 100)");
    printf("\n-----------------------------------------");
    
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("\n Subject %d    | %6.2f", i + 1, s->marks[i]);
    }
    
    printf("\n-----------------------------------------");
    printf("\n Total Marks  | %6.2f / %d", s->total, MAX_SUBJECTS * 100);
    printf("\n Percentage   | %6.2f%%", s->percentage);
    printf("\n Final Grade  | %c", s->grade);
    printf("\n Status       | %s", s->isPassed ? "PASSED" : "FAILED (Essential Repeat)");
    printf("\n-----------------------------------------\n");
}
