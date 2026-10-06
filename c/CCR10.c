#include <stdio.h>
#include <string.h>

void buildFullName(char *firstName, char *lastName, char *fullName);
void calculateLetterCount(char *fullName, int *letterCount);
void compareNames(char *member1FullName, char *member2FullName,
                  int *comparisonResult);

void trimSpaces(char *text);

int main() {

  char member1FirstName[30];
  char member1LastName[30];

  char member2FirstName[30];
  char member2LastName[30];

  char member1FullName[41];
  char member2FullName[41];

  int member1LetterCount;
  int member2LetterCount;

  int comparisonResult;

  printf("Member 1\n");

  printf("First Name: ");
  fgets(member1FirstName, sizeof(member1FirstName), stdin);

  member1FirstName[strcspn(member1FirstName, "\n")] = '\0';

  trimSpaces(member1FirstName);

  printf("Last Name: ");
  fgets(member1LastName, sizeof(member1LastName), stdin);

  member1LastName[strcspn(member1LastName, "\n")] = '\0';

  trimSpaces(member1LastName);

  printf("\nMember 2\n");

  printf("First Name: ");
  fgets(member2FirstName, sizeof(member2FirstName), stdin);

  member2FirstName[strcspn(member2FirstName, "\n")] = '\0';

  trimSpaces(member2FirstName);

  printf("Last Name: ");
  fgets(member2LastName, sizeof(member2LastName), stdin);

  member2LastName[strcspn(member2LastName, "\n")] = '\0';

  trimSpaces(member2LastName);

  if (strlen(member1FirstName) == 0 && strlen(member1LastName) == 0) {

    strcpy(member1FullName, "");
  } else {

    buildFullName(member1FirstName, member1LastName, member1FullName);
  }

  if (strlen(member2FirstName) == 0 && strlen(member2LastName) == 0) {

    strcpy(member2FullName, "");
  } else {

    buildFullName(member2FirstName, member2LastName, member2FullName);
  }

  calculateLetterCount(member1FullName, &member1LetterCount);
  calculateLetterCount(member2FullName, &member2LetterCount);

  printf("\n----------------------------------------\n");
  printf("Riverside Public Library\n");
  printf("Member Name Report\n");
  printf("----------------------------------------\n\n");

  printf("Member 1 : %s\n", member1FullName);

  printf("Letters  : %d\n\n", member1LetterCount);

  printf("Member 2 : %s\n", member2FullName);

  printf("Letters  : %d\n\n", member2LetterCount);

  compareNames(member1FullName, member2FullName, &comparisonResult);

  if (comparisonResult == 0) {
    printf("The names ARE identical.\n\n");
  } else {
    printf("The names are NOT identical.\n\n");
  }

  printf("Alphabetical Order\n\n");

  if (strlen(member1FullName) == 0 && strlen(member2FullName) == 0) {

    printf("No member names available.\n");
  } else if (strlen(member1FullName) == 0) {

    printf("1. %s\n", member2FullName);
  } else if (strlen(member2FullName) == 0) {

    printf("1. %s\n", member1FullName);
  } else if (comparisonResult < 0) {

    printf("1. %s\n", member1FullName);
    printf("2. %s\n", member2FullName);
  } else {

    printf("1. %s\n", member2FullName);
    printf("2. %s\n", member1FullName);
  }

  return 0;
}

void buildFullName(char *firstName, char *lastName, char *fullName) {
  strcpy(fullName, firstName);
  strcat(fullName, " ");
  strcat(fullName, lastName);
}

void calculateLetterCount(char *fullName, int *letterCount) {

    *letterCount = strlen(fullName);
}

void compareNames(char *member1FullName, char *member2FullName,
                  int *comparisonResult) {
  *comparisonResult = strcmp(member1FullName, member2FullName);
}

void trimSpaces(char *text) {

  int start = 0;
  int end;
  int i;
  while (text[start] == ' ') {
    start++;
  }

  i = 0;

  while (text[start] != '\0') {
    text[i] = text[start];
    i++;
    start++;
  }

  text[i] = '\0';

  end = strlen(text) - 1;

  while (end >= 0 && text[end] == ' ') {
    text[end] = '\0';
    end--;
  }
}
