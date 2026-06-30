#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "inventory.dat"

// Structure to represent an inventory item
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Function prototypes
void addProduct();
void viewInventory();
void searchProduct();
void deleteProduct();
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewInventory();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to display the main user menu
void displayMenu() {
    printf("\n====================================");
    printf("\n     INVENTORY MANAGEMENT SYSTEM    ");
    printf("\n====================================");
    printf("\n1. Add New Product");
    printf("\n2. View All Inventory");
    printf("\n3. Search Product by ID");
    printf("\n4. Delete Product");
    printf("\n5. Exit");
    printf("\n====================================\n");
}

// Function to add a product to the binary file
void addProduct() {
    FILE *file = fopen(FILE_NAME, "ab"); // Open in append-binary mode
    if (file == NULL) {
        printf("Error opening database file!\n");
        return;
    }

    Product p;
    printf("\nEnter Product ID (Integer): ");
    scanf("%d", &p.id);
    getchar(); // Clear trailing newline from buffer

    printf("Enter Product Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = '\0'; // Remove newline character

    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);

    printf("Enter Price: ");
    scanf("%f", &p.price);

    // Write the structure block directly to the file
    fwrite(&p, sizeof(Product), 1, file);
    fclose(file);

    printf("\nProduct added successfully!\n");
}

// Function to read and display all items from the file
void viewInventory() {
    FILE *file = fopen(FILE_NAME, "rb"); // Open in read-binary mode
    if (file == NULL) {
        printf("\nNo inventory records found. Add a product first!\n");
        return;
    }

    Product p;
    printf("\n%-10s %-25s %-10s %-10s\n", "ID", "Product Name", "Quantity", "Price");
    printf("------------------------------------------------------------\n");

    // Read blocks of Product structures until EOF is reached
    while (fread(&p, sizeof(Product), 1, file) == 1) {
        printf("%-10d %-25s %-10d $%-9.2f\n", p.id, p.name, p.quantity, p.price);
    }
    fclose(file);
}

// Function to find a specific product by its ID
void searchProduct() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int searchId;
    int found = 0;
    Product p;

    printf("\nEnter Product ID to search: ");
    scanf("%d", &searchId);

    while (fread(&p, sizeof(Product), 1, file) == 1) {
        if (p.id == searchId) {
            printf("\nProduct Found:");
            printf("\nID: %d", p.id);
            printf("\nName: %s", p.name);
            printf("\nQuantity: %d", p.quantity);
            printf("\nPrice: $%.2f\n", p.price);
            found = 1;
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("\nProduct with ID %d not found.\n", searchId);
    }
}

// Function to delete a product by rewriting records to a temporary file
void deleteProduct() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found to delete!\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("Error creating temporary storage!\n");
        fclose(file);
        return;
    }

    int deleteId;
    int found = 0;
    Product p;

    printf("\nEnter Product ID to delete: ");
    scanf("%d", &deleteId);

    // Copy all data except the target ID to the temporary file
    while (fread(&p, sizeof(Product), 1, file) == 1) {
        if (p.id == deleteId) {
            found = 1; // Mark found but skip writing to exclude it
        } else {
            fwrite(&p, sizeof(Product), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Swap the temporary file with the production file
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("\nProduct deleted successfully!\n");
    } else {
        printf("\nProduct with ID %d not found.\n", deleteId);
    }
}
