#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 10
#define TICKET_PRICE 12.00

// Structure to store booking details
typedef struct {
    int ticket_id;
    char customer_name[50];
    int row;
    int col;
} Ticket;

// Global Seat Matrix: 0 means Available, 1 means Booked
int seats[ROWS][COLS] = {0};

// Array to store active bookings (Up to maximum capacity)
Ticket bookings[ROWS * COLS];
int total_bookings = 0;
int next_ticket_id = 1001;

// Function Prototypes
void display_seats();
void book_ticket();
void cancel_ticket();
void display_bookings();
void clear_input_buffer();

int main() {
    int choice;

    while (1) {
        printf("\n===================================\n");
        printf("    MOVIE TICKET BOOKING SYSTEM    \n");
        printf("===================================\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Ticket\n");
        printf("4. View All Bookings\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                display_seats();
                break;
            case 2:
                book_ticket();
                break;
            case 3:
                cancel_ticket();
                break;
            case 4:
                display_bookings();
                break;
            case 5:
                printf("Thank you for using the Ticket Booking System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose between 1 and 5.\n");
        }
    }
    return 0;
}

// Displays the 2D visual layout of the theater seats
void display_seats() {
    printf("\n========= SCREEN THIS WAY =========\n\n  ");
    for (int j = 0; j < COLS; j++) {
        printf("  %d ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%c ", 'A' + i); // Row names as A, B, C, D, E
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == 0) {
                printf("[ ] "); // Available
            } else {
                printf("[X] "); // Booked
            }
        }
        printf("\n");
    }
    printf("\nLegend: [ ] = Available   [X] = Booked\n");
}

// Handles the booking workflow and stores passenger details
void book_ticket() {
    char row_char;
    int row, col;
    
    display_seats();

    printf("Enter Row Letter (A-%c): ", 'A' + ROWS - 1);
    scanf(" %c", &row_char);
    // Convert lower case to upper case if needed
    if (row_char >= 'a' && row_char <= 'z') {
        row_char -= 32;
    }
    row = row_char - 'A';

    printf("Enter Seat Number (1-%d): ", COLS);
    scanf("%d", &col);
    col--; // Convert to 0-indexed array bounds

    // Validate seat coordinates
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Error: Invalid seat selection!\n");
        return;
    }

    // Check if the chosen seat is already taken
    if (seats[row][col] == 1) {
        printf("Error: Seat %c-%d is already booked!\n", row_char, col + 1);
        return;
    }

    // Create the booking entry
    Ticket new_ticket;
    new_ticket.ticket_id = next_ticket_id++;
    new_ticket.row = row;
    new_ticket.col = col;

    printf("Enter Customer Name: ");
    clear_input_buffer();
    fgets(new_ticket.customer_name, sizeof(new_ticket.customer_name), stdin);
    new_ticket.customer_name[strcspn(new_ticket.customer_name, "\n")] = '\0'; // Strip newline

    // Finalize booking state
    seats[row][col] = 1;
    bookings[total_bookings++] = new_ticket;

    // Display Invoice Summary
    printf("\n🎉 Booking Confirmed Successfully!\n");
    printf("-----------------------------------\n");
    printf("Ticket ID: %d\n", new_ticket.ticket_id);
    printf("Customer:  %s\n", new_ticket.customer_name);
    printf("Seat Assigned: %c-%d\n", row_char, col + 1);
    printf("Total Fare:   $%.2f\n", TICKET_PRICE);
    printf("-----------------------------------\n");
}

// Cancels a booking using the Unique Ticket ID
void cancel_ticket() {
    int target_id;
    int found_index = -1;

    printf("Enter Ticket ID to cancel: ");
    scanf("%d", &target_id);

    // Search for the ticket ID inside active bookings
    for (int i = 0; i < total_bookings; i++) {
        if (bookings[i].ticket_id == target_id) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("Error: Ticket ID %d not found!\n", target_id);
        return;
    }

    // Free up the seat status back to 0
    int r = bookings[found_index].row;
    int c = bookings[found_index].col;
    seats[r][c] = 0;

    printf("Success: Ticket ID %d for seat %c-%d has been canceled.\n", 
            target_id, 'A' + r, c + 1);

    // Shift array items left to delete the record structurally
    for (int i = found_index; i < total_bookings - 1; i++) {
        bookings[i] = bookings[i + 1];
    }
    total_bookings--;
}

// Prints out a summary list of all active reservations
void display_bookings() {
    if (total_bookings == 0) {
        printf("\nNo tickets have been booked yet.\n");
        return;
    }

    printf("\n================ CURRENT BOOKINGS ================\n");
    printf("%-12s %-25s %-8s\n", "Ticket ID", "Customer Name", "Seat");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < total_bookings; i++) {
        printf("%-12d %-25s %c-%-d\n", 
               bookings[i].ticket_id, 
               bookings[i].customer_name, 
               'A' + bookings[i].row, 
               bookings[i].col + 1);
    }
    printf("==================================================\n");
}

// Helper to flush redundant standard input streaming buffers
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
