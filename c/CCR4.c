#include <stdio.h>

int main() {
  FILE *inputFile;
  FILE *outputFile;

  char inputFileName[100];
  char outputFileName[] = "numbered_hours.txt";
  char lineBuffer[200];

  int lineNumber = 1;
  int lineCount = 0;
  int characterCount = 0;
  int i;

  printf("Enter input file name: ");
  scanf("%s", inputFileName);

  inputFile = fopen(inputFileName, "r");

  if (inputFile == NULL) {
    printf("----------------------------------------\n");
    printf("Precision Payroll Services\n");
    printf("File Processing Summary\n");
    printf("----------------------------------------\n\n");

    printf("Error\n");
    printf("Unable to open file \"%s\".\n", inputFileName);
    printf("Please verify that the file exists and try again.\n");

    return 0;
  }

  outputFile = fopen(outputFileName, "w");

  while (fgets(lineBuffer, sizeof(lineBuffer), inputFile) != NULL) {
    fprintf(outputFile, "%d. %s", lineNumber, lineBuffer);

    lineCount++;

    for (i = 0; lineBuffer[i] != '\0'; i++) {
      if (lineBuffer[i] != '\n') {
        characterCount++;
      }
    }

    lineNumber++;
  }

  characterCount += lineCount - 1;

  fclose(inputFile);
  fclose(outputFile);

  printf("----------------------------------------\n");
  printf("Precision Payroll Services\n");
  printf("File Processing Summary\n");
  printf("----------------------------------------\n\n");

  printf("Input File  : %s\n", inputFileName);
  printf("Output File : %s\n\n", outputFileName);

  printf("Lines Copied      : %d\n", lineCount);
  printf("Characters Copied : %d\n\n", characterCount);

  printf("File copied successfully.\n");

  return 0;
}
