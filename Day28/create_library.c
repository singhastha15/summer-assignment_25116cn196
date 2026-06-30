#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Define structure for book information
struct Book {
    int id;
    char title[100];
    char author[100];
    int is_issued; // 0 = Available, 1 = Issued
};

// Global variables
struct Book library[MAX_BOOKS];
int book_count = 0;

// Function declarations
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n==== Library Management System ===");
        printf("\n=================================");
        printf("\n1. Add New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by ID");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("\nThank you for using the Library Management System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

// Function to add a new book to the library array
void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("\nError: Library space is full! Cannot add more books.\n");
        return;
    }

    struct Book new_book;
    
    printf("\nEnter Unique Book ID (Integer): ");
    scanf("%d", &new_book.id);
    clearInputBuffer(); // Clear leftover newline from scanf

    // Check if ID already exists
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == new_book.id) {
            printf("Error: A book with ID %d already exists!\n", new_book.id);
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(new_book.title, sizeof(new_book.title), stdin);
    new_book.title[strcspn(new_book.title, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Author Name: ");
    fgets(new_book.author, sizeof(new_book.author), stdin);
    new_book.author[strcspn(new_book.author, "\n")] = '\0'; // Remove trailing newline

    new_book.is_issued = 0; // New books are available by default

    library[book_count] = new_book;
    book_count++;

    printf("\nSuccess: Book added successfully!\n");
}

// Function to display all the books in the system
void displayBooks() {
    if (book_count == 0) {
        printf("\nThe library is empty. No records to display.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-15s\n", "Book ID", "Title", "Author", "Status");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%-10d %-30s %-25s %-15s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
}

// Function to find a book using its Unique ID
void searchBook() {
    if (book_count == 0) {
        printf("\nThe library is empty.\n");
        return;
    }

    int search_id;
    int found = 0;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == search_id) {
            printf("\n--- Book Found ---");
            printf("\nID: %d", library[i].id);
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s", library[i].author);
            printf("\nStatus: %s\n", library[i].is_issued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found.\n", search_id);
    }
}

// Function to change status to "Issued"
void issueBook() {
    int issue_id;
    int found = 0;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &issue_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == issue_id) {
            found = 1;
            if (library[i].is_issued == 1) {
                printf("\nSorry, this book is already issued to someone else.\n");
            } else {
                library[i].is_issued = 1;
                printf("\nSuccess: Book issued successfully!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found.\n", issue_id);
    }
}

// Function to change status back to "Available"
void returnBook() {
    int return_id;
    int found = 0;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &return_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == return_id) {
            found = 1;
            if (library[i].is_issued == 0) {
                printf("\nThis book is already marked as available in the library.\n");
            } else {
                library[i].is_issued = 0;
                printf("\nSuccess: Book returned successfully!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found.\n", return_id);
    }
}

// Helper function to clear buffer and avoid menu looping bugs
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
