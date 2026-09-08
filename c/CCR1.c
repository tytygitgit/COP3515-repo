#include <stdio.h>

int main() {
  char firstName[30];
  int age;
  float price;

  printf("Enter their first name: ");
  scanf("%s", firstName);
  printf("Enter their age: ");
  while (scanf("%d", &age) != 1 || age <= 0) {
    while (getchar() != '\n')
      ; // clear the input buffer
    printf("Please enter a valid age: ");
  }
  printf("Enter the monthly fee: ");
  scanf("%f", &price);

  printf("\n--------------------\nTampa Fitness Center\nMembership "
         "Receipt\n--------------------\n\n");

  printf("Customer: %s\n\n", firstName);
  printf("Age: %d\n\n", age);
  printf("Monthly Fee: $%.2f\n\n", price);
  printf("Status: %s\n\n",
         (age >= 65) ? "Senior Program" : "Standard Membership");
  printf("Thank you for joining!\n\n");

  return 0;
}
