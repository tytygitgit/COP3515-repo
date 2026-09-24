#include <stdio.h>

#define INVENTORY_FILE "inventory.txt"

/* Global inventory variable */
int currentInventory;

/* Calculate remaining inventory */
int calculateRemainingInventory(int productsPurchased) {
  return currentInventory - productsPurchased;
}

/* Print transaction receipt */
void printReceipt(int productsPurchased, int remainingInventory) {

  printf("-----------------------------\n");
  printf("Green Valley Supply Company\n");
  printf("Inventory Transaction Summary\n");
  printf("-----------------------------\n");

  printf("Inventory Before Sale : %d\n", currentInventory);
  printf("Products Sold         : %d\n", productsPurchased);
  printf("Inventory Remaining   : %d\n", remainingInventory);
}

/* Save inventory to file */
void saveInventoryToFile() {

  FILE *inventoryFile;

  inventoryFile = fopen(INVENTORY_FILE, "w");

  if (inventoryFile == NULL) {
    printf("\nERROR: Unable to open %s to save inventory.\n", INVENTORY_FILE);
    return;
  }

  fprintf(inventoryFile, "%d\n", currentInventory);

  fclose(inventoryFile);

  printf("\nInventory quantity successfully saved to '%s'.\n", INVENTORY_FILE);
}

int main() {

  int productsPurchased;
  int remainingInventory;

  int valid;

  char confirm;
  char nextSale;

  /* Get initial inventory */
  do {

    valid = 1;

    printf("Enter initial current inventory: ");

    if (scanf("%d", &currentInventory) != 1) {

      while (getchar() != '\n')
        ;

      printf("\nERROR\n");
      printf("Please enter a whole number.\n\n");

      valid = 0;
    } else if (currentInventory < 0) {

      printf("\nERROR\n");
      printf("Inventory cannot be a negative number.\n\n");

      valid = 0;
    }

  } while (!valid);

  /* Process multiple sales */
  do {

    if (currentInventory == 0) {

      printf("\nInventory is currently empty (0 units remaining).\n");
      printf("Cannot process any new sales.\n");

      break;
    }

    do {

      valid = 1;

      printf("\nEnter products purchased: ");

      if (scanf("%d", &productsPurchased) != 1) {

        while (getchar() != '\n')
          ;

        printf("\nERROR\n");
        printf("Please enter a whole number.\n\n");

        valid = 0;
      } else if (productsPurchased <= 0) {

        printf("\nERROR\n");
        printf("Products purchased must be greater than zero.\n");

        valid = 0;
      } else if (productsPurchased > currentInventory) {

        printf("\nERROR\n");
        printf("Products purchased cannot be more than the current "
               "inventory.\n");

        valid = 0;
      }

    } while (!valid);

    printf("Confirm this sale? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'n' || confirm == 'N') {

      printf("\nSale canceled. Inventory was not updated.\n");
    } else {

      remainingInventory = calculateRemainingInventory(productsPurchased);

      printf("\n");

      printReceipt(productsPurchased, remainingInventory);

      currentInventory = remainingInventory;
    }

    printf("\nWould you like to process another sale? (y/n): ");
    scanf(" %c", &nextSale);

  } while (nextSale == 'y' || nextSale == 'Y');

  saveInventoryToFile();

  printf("Program terminated. Final remaining inventory: %d\n",
         currentInventory);

  return 0;
}
