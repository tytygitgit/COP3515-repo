#include <stdio.h>

// File name constant for saving data
#define INVENTORY_FILE "inventory.txt"

// Global variable: tracks the overall stock throughout the program execution
int currentInventory;

// Structure to group all data related to a single sale transaction
typedef struct {
  int productsPurchased;
  int remainingInventory;
} Sale;

// Function to calculate remaining inventory using the global inventory variable
int calculateRemainingInventory(int productsPurchased) {
  return currentInventory - productsPurchased;
}

// Function to display the professionally formatted receipt
void printReceipt(Sale currentSale) {
  printf("----------------------------------------\n");
  printf("Green Valley Supply Company\n");
  printf("Inventory Transaction Summary\n");
  printf("----------------------------------------\n");
  printf("Inventory Before Sale : %d\n", currentInventory);
  printf("Products Sold         : %d\n", currentSale.productsPurchased);
  printf("Inventory Remaining   : %d\n", currentSale.remainingInventory);
}

// Function to save the final inventory quantity to a text file
void saveInventoryToFile() {
  FILE *inventoryFile;

  inventoryFile = fopen(INVENTORY_FILE, "w");

  if (inventoryFile == NULL) {
    printf("\nERROR: Unable to open %s to save the updated inventory.\n",
           INVENTORY_FILE);
    return;
  }

  fprintf(inventoryFile, "%d\n", currentInventory);
  fclose(inventoryFile);

  printf("\nInventory quantity successfully saved to '%s'.\n", INVENTORY_FILE);
}

int main() {
  Sale sale;
  int valid;
  char confirm;
  char nextSale;

  // 1. Get initial current inventory (Allows 0, blocks negative numbers,
  // handles bad input)
  do {
    valid = 1;
    printf("Enter initial current inventory: ");

    if (scanf("%d", &currentInventory) != 1) {
      while (getchar() != '\n')
        ; // Clear the invalid input buffer
      printf("\nERROR\n");
      printf("Please enter a whole number.\n\n");
      valid = 0;
    } else if (currentInventory < 0) {
      printf("\nERROR\n");
      printf("Inventory cannot be a negative number.\n\n");
      valid = 0;
    }
  } while (!valid);

  // Main transaction loop to handle multiple customer purchases sequentially
  do {
    // If inventory reaches 0, notify the user and check if they want to exit
    if (currentInventory == 0) {
      printf("\nInventory is currently empty (0 units remaining).\n");
      printf("Cannot process any new sales.\n");
      break;
    }

    // 2. Get products purchased (Must be > 0, cannot exceed current inventory)
    do {
      valid = 1;
      printf("\nEnter products purchased: ");

      if (scanf("%d", &sale.productsPurchased) != 1) {
        while (getchar() != '\n')
          ; // Clear buffer
        printf("\nERROR\n");
        printf("Please enter a whole number.\n\n");
        valid = 0;
      } else if (sale.productsPurchased <= 0) {
        printf("\nERROR\n");
        printf("Products purchased must be greater than zero.\n\n");
        valid = 0;
      } else if (sale.productsPurchased > currentInventory) {
        printf("\nERROR\n");
        printf("Products purchased cannot be more than the current "
               "inventory.\n\n");
        valid = 0;
      }
    } while (!valid);

    // 3. Confirmation step before updating values
    printf("Confirm this sale? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'n' || confirm == 'N') {
      printf("\nSale canceled. Inventory was not updated.\n");
    } else {
      // Compute the remaining stock for this transaction
      sale.remainingInventory =
          calculateRemainingInventory(sale.productsPurchased);

      // Print out the transaction summary report
      printf("\n");
      printReceipt(sale);

      // Automatically update the global inventory for the next sale loop
      currentInventory = sale.remainingInventory;
    }

    // Ask if the employee wants to process another customer transaction
    printf("\nWould you like to process another sale? (y/n): ");
    scanf(" %c", &nextSale);

  } while (nextSale == 'y' || nextSale == 'Y');

  // 4. Save the final inventory to a text file right before termination
  saveInventoryToFile();

  printf("Program terminated. Final remaining inventory: %d\n",
         currentInventory);

  return 0;
}
