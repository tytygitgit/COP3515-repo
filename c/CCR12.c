#include <stdio.h>
#include <stdlib.h>

int main() {

  int numberOfScores;
  float *surveyScores = NULL;

  float highestScore;
  float lowestScore;
  float averageScore;
  float totalScore = 0.0;

  int i;

  while (1) {

    printf("Number of Survey Scores: ");
    if (scanf("%d", &numberOfScores) != 1) {

      while (getchar() != '\n')
        ;

      printf("\nERROR\n");
      printf("Invalid input.\n\n");

      continue;
    }

    if (numberOfScores >= 1 && numberOfScores <= 10) {

      break;
    }

    printf("\nERROR\n");
    printf("Number of survey responses ");
    printf("must be between 1 and 10.\n\n");
  }

  surveyScores = (float *)malloc(numberOfScores * sizeof(float));

  if (surveyScores == NULL) {

    printf("\nERROR\n");
    printf("Unable to allocate memory.\n");

    return 1;
  }

  for (i = 0; i < numberOfScores; i++) {

    while (1) {

      printf("Score %d: ", i + 1);

      if (scanf("%f", &surveyScores[i]) != 1) {

        while (getchar() != '\n')
          ;

        printf("\nERROR\n");
        printf("Invalid score entered.\n\n");

        continue;
      }

      if (surveyScores[i] >= 0.0 && surveyScores[i] <= 100.0) {

        break;
      }

      printf("\nERROR\n");
      printf("Survey score must ");
      printf("be between 0 and 100.\n\n");
    }
  }

  highestScore = surveyScores[0];
  lowestScore = surveyScores[0];

  for (i = 0; i < numberOfScores; i++) {

    totalScore += surveyScores[i];

    if (surveyScores[i] > highestScore) {

      highestScore = surveyScores[i];
    }

    if (surveyScores[i] < lowestScore) {

      lowestScore = surveyScores[i];
    }
  }

  averageScore = totalScore / numberOfScores;

  printf("\n");
  printf("----------------------------------------\n");
  printf("Insight Market Research Group\n");
  printf("Survey Summary Report\n");
  printf("----------------------------------------\n\n");

  printf("Survey Responses : %d\n", numberOfScores);

  printf("Highest Score    : %.1f\n", highestScore);

  printf("Lowest Score     : %.1f\n", lowestScore);

  printf("Average Score    : %.1f\n", averageScore);

  free(surveyScores);

  surveyScores = NULL;

  printf("\nMemory released successfully.\n");
  printf("Program completed.\n");

  return 0;
}
