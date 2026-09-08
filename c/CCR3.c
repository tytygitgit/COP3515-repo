#include <stdio.h>

int main() {
  int age;
  char dayType;

  printf("Enter customer's age: ");
  while (scanf("%d", &age) != 1 || age <= 0 || age > 100) {
    while (getchar() != '\n')
      ;
    printf("Please enter a valid age (1-100): ");
  }

  printf("Enter day type (Weekday or Weekend): ");
  while (scanf(" %c", &dayType) != 1 || (dayType != 'W' && dayType != 'w' &&
                                         dayType != 'E' && dayType != 'e')) {
    while (getchar() != '\n')
      ;
    printf("Please enter a valid day type: ");
  }

  printf("\n---------------------\nGrand Cinema Theater\nTicket Classification "
         "\n---------------------\n\n");

  printf("Customer Age: %d\n", age);

  if (dayType == 'W' || dayType == 'w') {
    printf("Day Type: Weekday\n");
  } else {
    printf("Day Type: Weekend\n");
  }

  if (age <= 12) {
    printf("Ticket Type: Child Ticket\n");
  } else if (age >= 13 && age < 60) {
    printf("Ticket Type: Adult Ticket\n");
  } else {
    printf("Ticket Type: Senior Ticket\n");
  }
}
