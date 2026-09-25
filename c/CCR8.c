#include <stdio.h>

int main() {

  float originalGrade;
  float extraCredit;
  float correctedGrade;

  char confirm;
  char anotherStudent;

  do {

    printf("Enter Original Grade: ");

    while (scanf("%f", &originalGrade) != 1 || originalGrade < 0 ||
           originalGrade > 120) {

      printf("Invalid input. Original grade must be between 0-120: ");

      while (getchar() != '\n')
        ;
    }

    printf("Enter Extra Credit Points: ");

    while (scanf("%f", &extraCredit) != 1 || extraCredit < 0) {

      printf("Invalid input. Extra credit points must be 0 or greater: ");

      while (getchar() != '\n')
        ;
    }

    correctedGrade = originalGrade + extraCredit;

    if (correctedGrade > 120) {
      correctedGrade = 120;
    }

    printf("\nConfirm updated grade? (y/n): ");
    scanf(" %c", &confirm);

    while (confirm != 'y' && confirm != 'Y' && confirm != 'n' &&
           confirm != 'N') {

      printf("Please enter y or n: ");
      scanf(" %c", &confirm);
    }

    if (confirm == 'y' || confirm == 'Y') {

      printf("\n--------------------------\n");
      printf("Sunshine Elementary School\n");
      printf("Grade Adjustment Report\n");
      printf("--------------------------\n\n");

      printf("Original Grade : %.1f\n", originalGrade);
      printf("Extra Credit   : %.1f\n", extraCredit);
      printf("Corrected Grade: %.1f\n", correctedGrade);

    } else {

      printf("\nGrade adjustment canceled.\n");
    }

    printf("\nWould you like to process another student? (y/n): ");
    scanf(" %c", &anotherStudent);

    while (anotherStudent != 'y' && anotherStudent != 'Y' &&
           anotherStudent != 'n' && anotherStudent != 'N') {

      printf("Please enter y or n: ");
      scanf(" %c", &anotherStudent);
    }

  } while (anotherStudent == 'y' || anotherStudent == 'Y');

  printf("\nProgram terminated.\n");

  return 0;
}
