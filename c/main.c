#include <stdio.h>

int totalStudentsEntered = 0;
int totalHonorsStudents = 0;
float totalGPA = 0.0;

void updateStatistics(float currentGPA) {

  totalStudentsEntered++;

  totalGPA += currentGPA;

  if (currentGPA >= 3.50) {
    totalHonorsStudents++;
  }
}

void displayHeader() {
  printf("\n-------------------------------------\n");
  printf("Student Information Management System\n");
  printf("Version 7.0\n");
  printf("-------------------------------------\n\n");
}
void displayMenu() {
  printf("1. Add Student\n");
  printf("2. Display Student\n");
  printf("3. Enter Grades\n");
  printf("4. Save Student Record\n");
  printf("6. Display Statistics\n\n");
  printf("5. Exit\n");
}

void displayStanding(float currentGPA);
void displayStatistics();

void addStudent(int *studentID, char studentName[], float *currentGPA,
                int *studentExists) {

  printf("Enter Student ID: ");
  scanf("%d", studentID);

  printf("Enter Student Name: ");
  scanf(" %49[^\n]", studentName);

  printf("Enter Current GPA: ");

  while (scanf("%f", currentGPA) != 1 || *currentGPA < 0 || *currentGPA > 4.0) {

    while (getchar() != '\n')
      ;

    printf("\nERROR\n");
    printf("Invalid GPA entered.\n");
    printf("GPA must be between 0.00 and 4.00.\n\n");
    printf("Enter Current GPA: ");
  }

  *studentExists = 1;
  updateStatistics(*currentGPA);

  printf("\nStudent successfully added.\n");
}

void enterGrades(int courseGrades[], float *averageGrade, int *highestGrade,
                 int *lowestGrade, int studentExists, int *gradesExist) {

  if (!studentExists) {

    printf("\nERROR\n");
    printf("Please add a student before entering grades.\n");

    return;
  }

  printf("\nEnter Course 1 Grade: ");
  scanf("%d", &courseGrades[0]);

  printf("Enter Course 2 Grade: ");
  scanf("%d", &courseGrades[1]);

  printf("Enter Course 3 Grade: ");
  scanf("%d", &courseGrades[2]);

  printf("Enter Course 4 Grade: ");
  scanf("%d", &courseGrades[3]);

  printf("Enter Course 5 Grade: ");
  scanf("%d", &courseGrades[4]);

  *averageGrade = (courseGrades[0] + courseGrades[1] + courseGrades[2] +
                   courseGrades[3] + courseGrades[4]) /
                  5.0;

  *highestGrade = courseGrades[0];

  if (courseGrades[1] > *highestGrade)
    *highestGrade = courseGrades[1];

  if (courseGrades[2] > *highestGrade)
    *highestGrade = courseGrades[2];

  if (courseGrades[3] > *highestGrade)
    *highestGrade = courseGrades[3];

  if (courseGrades[4] > *highestGrade)
    *highestGrade = courseGrades[4];

  *lowestGrade = courseGrades[0];

  if (courseGrades[1] < *lowestGrade)
    *lowestGrade = courseGrades[1];

  if (courseGrades[2] < *lowestGrade)
    *lowestGrade = courseGrades[2];

  if (courseGrades[3] < *lowestGrade)
    *lowestGrade = courseGrades[3];

  if (courseGrades[4] < *lowestGrade)
    *lowestGrade = courseGrades[4];

  *gradesExist = 1;

  printf("\nGrades successfully recorded.\n");
}

void displayStudent(int studentID, char studentName[], float currentGPA,
                    int courseGrades[], float averageGrade, int highestGrade,
                    int lowestGrade, int studentExists, int gradesExist) {

  if (!studentExists) {

    printf("\nERROR\n");
    printf("No student information available.\n");

    return;
  }

  printf("\n-------------------------------------\n");
  printf("Student Summary\n");
  printf("-------------------------------------\n\n");

  printf("Student ID          : %d\n", studentID);
  printf("Student Name        : %s\n", studentName);
  printf("Current GPA         : %.2f\n", currentGPA);
  displayStanding(currentGPA);

  if (!gradesExist) {

    printf("No grades have been entered.\n");

    return;
  }

  printf("Course Grades\n\n");

  printf("Course 1: %d\n", courseGrades[0]);
  printf("Course 2: %d\n", courseGrades[1]);
  printf("Course 3: %d\n", courseGrades[2]);
  printf("Course 4: %d\n", courseGrades[3]);
  printf("Course 5: %d\n", courseGrades[4]);

  printf("\nAverage Grade : %.2f\n", averageGrade);
  printf("Highest Grade : %d\n", highestGrade);
  printf("Lowest Grade  : %d\n", lowestGrade);
}

void saveStudentRecord(int studentID, char studentName[], float currentGPA,
                       int courseGrades[], int studentExists, int gradesExist) {

  FILE *studentFile;

  if (!studentExists) {

    printf("\nERROR\n");
    printf("No student information available to save.\n");

    return;
  }

  if (!gradesExist) {

    printf("\nERROR\n");
    printf("No grades have been entered.\n");

    return;
  }

  studentFile = fopen("student_records.txt", "w");

  if (studentFile == NULL) {

    printf("ERROR\n");
    printf("Unable to open student_records.txt.\n");

    return;
  }

  fprintf(studentFile, "%d\n", studentID);
  fprintf(studentFile, "%s\n", studentName);
  fprintf(studentFile, "%.2f\n", currentGPA);

  if (currentGPA >= 3.50)
    fprintf(studentFile, "Honors\n");

  else if (currentGPA >= 2.00)
    fprintf(studentFile, "Good Standing\n");

  else if (currentGPA >= 1.00)
    fprintf(studentFile, "Academic Probation\n");

  else
    fprintf(studentFile, "Academic Suspension\n");

  for (int i = 0; i < 5; i++) {

    fprintf(studentFile, "%d\n", courseGrades[i]);
  }

  fclose(studentFile);

  printf("\nStudent record successfully saved.\n");
  printf("student_records.txt created.\n");
}

void displayStanding(float currentGPA) {

  if (currentGPA >= 3.50)
    printf("Academic Standing   : Honors\n\n");

  else if (currentGPA >= 2.00)
    printf("Academic Standing   : Good Standing\n\n");

  else if (currentGPA >= 1.00)
    printf("Academic Standing   : Academic Probation\n\n");

  else
    printf("Academic Standing   : Academic Suspension\n\n");
}

void displayStatistics() {

  float averageGPA = 0.0;

  if (totalStudentsEntered > 0) {
    averageGPA = totalGPA / totalStudentsEntered;
  }

  printf("\n-------------------------------------\n");
  printf("SIMS Statistics\n");
  printf("-------------------------------------\n\n");

  printf("Total Students Entered : %d\n", totalStudentsEntered);

  printf("Average GPA            : %.2f\n", averageGPA);

  printf("Honor Students         : %d\n", totalHonorsStudents);
}

int main() {

  int studentID;
  char studentName[50];
  float currentGPA;
  int courseGrades[5];
  float averageGrade;
  int highestGrade;
  int lowestGrade;

  int menuChoice = 0;
  int studentExists = 0;
  int gradesExist = 0;

  while (menuChoice != 5) {

    displayHeader();

    displayMenu();

    printf("Selection: ");
    if (scanf("%d", &menuChoice) != 1) {

      while (getchar() != '\n')
        ;

      printf("\nERROR\n");
      printf("Invalid menu selection.\n");
      printf("Please choose an option between 1 and 6.\n");

      continue;
    }

    switch (menuChoice) {

    case 1:

      addStudent(&studentID, studentName, &currentGPA, &studentExists);

      break;

    case 2:

      displayStudent(studentID, studentName, currentGPA, courseGrades,
                     averageGrade, highestGrade, lowestGrade, studentExists,
                     gradesExist);

      break;

    case 3:

      enterGrades(courseGrades, &averageGrade, &highestGrade, &lowestGrade,
                  studentExists, &gradesExist);

      break;

    case 4:

      saveStudentRecord(studentID, studentName, currentGPA, courseGrades,
                        studentExists, gradesExist);

      break;

    case 6:

      displayStatistics();

      break;

    case 5:
      printf("\nThank you for using the\n");
      printf("Student Information Management System.\n");
      printf("Program terminated successfully.\n");
      break;

    default:
      printf("\nERROR\n");
      printf("Invalid menu selection.\n");
      printf("Please choose an option between 1 and 6.\n");
    }
  }

  return 0;
}
