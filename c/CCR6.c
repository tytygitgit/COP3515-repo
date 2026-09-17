#include <stdio.h>

int main() {

  float orderAmount;
  float discountAmount;
  float discountPercent;
  float salesTax;
  float finalTotal;

  printf("Enter Order Amount: $");

  while (scanf("%f", &orderAmount) != 1 || orderAmount < 0 ||
         orderAmount > 5000) {

    while (getchar() != '\n')
      ;

    printf("Please enter a valid order amount: $");
  }

  printf("Enter Discount Percentage: ");

  while (scanf("%f", &discountPercent) != 1 || discountPercent < 0 ||
         discountPercent > 100) {

    while (getchar() != '\n')
      ;

    printf("Please enter a valid discount percentage (0-100): ");
  }

  /* Calculate Sales Tax */
  salesTax = orderAmount * 0.06;

  /* Round Sales Tax to nearest nickel */
  salesTax = (int)(salesTax * 20 + 0.5) / 20.0;

  /* Calculate Discount AFTER tax */
  discountAmount = (orderAmount + salesTax) * (discountPercent / 100.0);

  /* Round Discount to nearest nickel */
  discountAmount = (int)(discountAmount * 20 + 0.5) / 20.0;

  /* Calculate Final Total */
  finalTotal = orderAmount + salesTax - discountAmount;

  /* Round Final Total to nearest nickel */
  finalTotal = (int)(finalTotal * 20 + 0.5) / 20.0;

  printf("\n----------------------------------------\n");
  printf("Sweet Delights Bakery\n");
  printf("Customer Receipt\n");
  printf("----------------------------------------\n\n");

  printf("Original Order : $%.2f\n", orderAmount);
  printf("Sales Tax      : $%.2f\n", salesTax);
  printf("Discount Rate  : %.2f%%\n", discountPercent);
  printf("Discount Amt   : $%.2f\n", discountAmount);

  printf("----------------------------------------\n");

  printf("Final Total    : $%.2f\n", finalTotal);

  return 0;
}
