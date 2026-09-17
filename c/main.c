#include <stdio.h>

int main() {
  int studentID;
  char studentName[50];
  float currentGPA;
  int courseGrades[5];
  float averageGrade;
  int highestGrade;
  int lowestGrade;

  printf("Enter Student ID: ");
  scanf("%d", &studentID);

  printf("Enter Student Name: ");
  scanf(" %49[^\n]", studentName);

  printf("Enter Current GPA: ");
  while (scanf("%f", &currentGPA) != 1 || currentGPA < 0 || currentGPA > 4.0) {
    while (getchar() != '\n')
      ; // clear the input buffer
    printf("\nERROR\n");
    printf("Invalid GPA entered.\n");
    printf("GPA must be between 0.00 and 4.00.\n\n");
    printf("Enter Current GPA: ");
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

  averageGrade = (courseGrades[0] + courseGrades[1] + courseGrades[2] +
                  courseGrades[3] + courseGrades[4]) /
                 5.0;
  highestGrade = courseGrades[0];
  if (courseGrades[1] > highestGrade)
    highestGrade = courseGrades[1];
  if (courseGrades[2] > highestGrade)
    highestGrade = courseGrades[2];
  if (courseGrades[3] > highestGrade)
    highestGrade = courseGrades[3];
  if (courseGrades[4] > highestGrade)
    highestGrade = courseGrades[4];

  lowestGrade = courseGrades[0];
  if (courseGrades[1] < lowestGrade)
    lowestGrade = courseGrades[1];
  if (courseGrades[2] < lowestGrade)
    lowestGrade = courseGrades[2];
  if (courseGrades[3] < lowestGrade)
    lowestGrade = courseGrades[3];
  if (courseGrades[4] < lowestGrade)
    lowestGrade = courseGrades[4];

  printf("\n-------------------------------------\n");
  printf("Student Information Management System\n");
  printf("Version 3.0\n");
  printf("Programmer: Tyler Cabrera\n");
  printf("Welcome to SIMS\n");
  printf("-------------------------------------\n");

  printf("\n");
  printf("Student Summary\n\n");
  printf("Student ID: %d\n", studentID);
  printf("Student Name: %s\n", studentName);
  printf("Current GPA: %.2f\n", currentGPA);

  if (currentGPA >= 3.50) {
    printf("Academic Standing: Honors\n\n");
  } else if (currentGPA >= 2.00) {
    printf("Academic Standing: Good Standing\n\n");
  } else if (currentGPA >= 1.00) {
    printf("Academic Standing: Academic Probation\n\n");
  } else {
    printf("Academic Standing: Academic Suspension\n\n");
  }

  printf("-------------------------------------\n");
  printf("Course Grades \n\n");
  printf("Course 1: %d\n", courseGrades[0]);
  printf("Course 2: %d\n", courseGrades[1]);
  printf("Course 3: %d\n", courseGrades[2]);
  printf("Course 4: %d\n", courseGrades[3]);
  printf("Course 5: %d\n", courseGrades[4]);
  printf("-------------------------------------\n");

  printf("\nAverage Grade: %.2f\n", averageGrade);
  printf("Highest Grade: %d\n", highestGrade);
  printf("Lowest Grade: %d\n", lowestGrade);

  return 0;
}
