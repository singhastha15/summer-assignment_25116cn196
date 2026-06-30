#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to store book details
struct Book {
    int id;
    char title[100];
    char author[100];
    float price;
};

// Global library array and counter
struct Book library[MAX_BOOKS];
int bookCount = 0;

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n--- MINI LIBRARY SYSTEM ---");
        printf("\n=================================");
        printf("\n1. Add New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by ID");
        printf("\n4. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            clearBuffer();
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
                printf("\nExiting the program. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}

// Function to add a book to the library
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full! Cannot add more books.\n");
        return;
    }

    struct Book newBook;
    
    printf("\nEnter Book ID (Integer): ");
    if (scanf("%d", &newBook.id) != 1) {
        printf("Invalid ID type! Operation aborted.\n");
        clearBuffer();
        return;
    }
    clearBuffer(); // Clear newline left in buffer

    // Check if ID already exists
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == newBook.id) {
            printf("Error: A book with ID %d already exists!\n", newBook.id);
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Price: ");
    if (scanf("%f", &newBook.price) != 1) {
        printf("Invalid price type! Operation aborted.\n");
        clearBuffer();
        return;
    }

    // Save the book into the array
    library[bookCount] = newBook;
    bookCount++;

    printf("\nBook added successfully!\n");
}

// Function to view all books in the library
void displayBooks() {
    if (bookCount == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-10s\n", "Book ID", "Title", "Author", "Price");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10d %-30s %-25s $%-9.2f\n", 
               library[i].id, library[i].title, library[i].author, library[i].price);
    }
}

// Function to search for a book by its unique ID
void searchBook() {
    if (bookCount == 0) {
        printf("\nThe library is empty. Nothing to search.\n");
        return;
    }

    int searchId;
    int found = 0;

    printf("\nEnter Book ID to search: ");
    if (scanf("%d", &searchId) != 1) {
        printf("Invalid ID format.\n");
        clearBuffer();
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("\n--- Book Found ---");
            printf("\nID: %d", library[i].id);
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s", library[i].author);
            printf("\nPrice: $%.2f\n", library[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found.\n", searchId);
    }
}

// Helper function to clean the standard input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
