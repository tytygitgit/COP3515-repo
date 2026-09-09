#include <stdio.h>

int main() {
  int studentID;
  char studentName[50];
  float currentGPA;

  printf("Enter Student ID: ");
  scanf("%d", &studentID);

  printf("Enter Student Name: ");
  scanf(" %49[^\n]", studentName);

  printf("Enter Current GPA: ");
  scanf("%f", &currentGPA);

  printf("-------------------------------------\n");
  printf("Student Information Management System\n");
  printf("Version 1.0\n");
  printf("Programmer: Your Name Here\n");
  printf("Welcome to SIMS\n");
  printf("-------------------------------------\n");

  printf("\n");
  printf("Student Summary\n\n");
  printf("Student ID : %d\n", studentID);
  printf("Student Name : %s\n", studentName);
  printf("Current GPA : %.2f\n", currentGPA);

  return 0;
}
