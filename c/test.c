#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define LINE_SIZE 256

typedef struct {
  int id;
  char *lastName;
  char *firstName;
  double hours;
  double rate;
  double grossPay;
} Employee;

double calculateGrossPay(double hours, double rate);
void loadEmployees(const char *filename, Employee employees[], int *count);
void displayEmployees(Employee employees[], int count);
Employee *searchEmployee(Employee employees[], int count, int id);
Employee *findHighestGrossPay(Employee employees[], int count);
void freeEmployees(Employee employees[], int count);

int main() {
  Employee employees[MAX_EMPLOYEES];
  int employeeCount = 0;
  int searchID;

  loadEmployees("employees.txt", employees, &employeeCount);

  if (employeeCount == 0) {
    printf("No employee records found.\n");
    return 1;
  }

  printf("\nEMPLOYEE PAYROLL INFORMATION\n");
  printf("----------------------------\n");

  displayEmployees(employees, employeeCount);

  Employee *highest = findHighestGrossPay(employees, employeeCount);

  if (highest != NULL) {
    printf("\nEMPLOYEE WITH HIGHEST GROSS PAY\n");
    printf("------------------------------\n");
    printf("ID: %d\n", highest->id);
    printf("Name: %s %s\n", highest->firstName, highest->lastName);
    printf("Gross Pay: $%.2f\n", highest->grossPay);
  }

  printf("\nEnter employee ID to search: ");
  scanf("%d", &searchID);

  Employee *found = searchEmployee(employees, employeeCount, searchID);

  if (found != NULL) {
    printf("\nEMPLOYEE FOUND\n");
    printf("--------------\n");
    printf("ID: %d\n", found->id);
    printf("Name: %s %s\n", found->firstName, found->lastName);
    printf("Hours Worked: %.2f\n", found->hours);
    printf("Hourly Rate: $%.2f\n", found->rate);
    printf("Gross Pay: $%.2f\n", found->grossPay);
  } else {
    printf("Employee ID %d not found.\n", searchID);
  }

  freeEmployees(employees, employeeCount);

  return 0;
}

double calculateGrossPay(double hours, double rate) { return hours * rate; }

void loadEmployees(const char *filename, Employee employees[], int *count) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("Error opening file.\n");
    return;
  }

  char line[LINE_SIZE];

  while (fgets(line, sizeof(line), file) != NULL && *count < MAX_EMPLOYEES) {
    line[strcspn(line, "\r\n")] = '\0';

    if (line[0] == '\0') {
      continue;
    }

    char *idTok = strtok(line, ",");
    char *lastTok = strtok(NULL, ",");
    char *firstTok = strtok(NULL, ",");
    char *hoursTok = strtok(NULL, ",");
    char *rateTok = strtok(NULL, ",");

    if (idTok == NULL || lastTok == NULL || firstTok == NULL ||
        hoursTok == NULL || rateTok == NULL) {
      printf("Skipping invalid line.\n");
      continue;
    }

    employees[*count].id = atoi(idTok);

    employees[*count].lastName = malloc(strlen(lastTok) + 1);
    if (employees[*count].lastName == NULL) {
      printf("Memory allocation failed.\n");
      fclose(file);
      exit(1);
    }
    strcpy(employees[*count].lastName, lastTok);

    employees[*count].firstName = malloc(strlen(firstTok) + 1);
    if (employees[*count].firstName == NULL) {
      printf("Memory allocation failed.\n");
      fclose(file);
      exit(1);
    }
    strcpy(employees[*count].firstName, firstTok);

    employees[*count].hours = atof(hoursTok);
    employees[*count].rate = atof(rateTok);

    employees[*count].grossPay =
        calculateGrossPay(employees[*count].hours, employees[*count].rate);

    (*count)++;
  }

  fclose(file);
}

void displayEmployees(Employee employees[], int count) {
  int i;

  for (i = 0; i < count; i++) {
    printf("\nID: %d\n", employees[i].id);
    printf("Name: %s %s\n", employees[i].firstName, employees[i].lastName);
    printf("Hours Worked: %.2f\n", employees[i].hours);
    printf("Hourly Rate: $%.2f\n", employees[i].rate);
    printf("Gross Pay: $%.2f\n", employees[i].grossPay);
  }
}

Employee *searchEmployee(Employee employees[], int count, int id) {
  int i;

  for (i = 0; i < count; i++) {
    if (employees[i].id == id) {
      return &employees[i];
    }
  }

  return NULL;
}

Employee *findHighestGrossPay(Employee employees[], int count) {
  int i;
  int highestIndex = 0;

  if (count == 0) {
    return NULL;
  }

  for (i = 1; i < count; i++) {
    if (employees[i].grossPay > employees[highestIndex].grossPay) {
      highestIndex = i;
    }
  }

  return &employees[highestIndex];
}

void freeEmployees(Employee employees[], int count) {
  int i;

  for (i = 0; i < count; i++) {
    free(employees[i].firstName);
    free(employees[i].lastName);
  }
}
