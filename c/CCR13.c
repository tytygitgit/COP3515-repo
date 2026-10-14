#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int main() {

  int numbers[10];

  int pipeFD[2];

  pid_t pid;

  int i;

  int receivedNumbers[10];

  int count = 10;
  int minimumValue;
  int maximumValue;
  int totalValue = 0;

  float averageValue;

  int aboveAverageCount = 0;
  float percentAboveAverage;

  ssize_t bytesRead;
  ssize_t bytesWritten;

  printf("----------------------------------------\n");
  printf("Data Analytics Solutions\n");
  printf("Statistics Processing\n");
  printf("----------------------------------------\n\n");

  if (pipe(pipeFD) < 0) {

    printf("ERROR\n");
    printf("Pipe creation failed.\n");

    return 1;
  }

  pid = fork();

  if (pid < 0) {

    printf("ERROR\n");
    printf("Process creation failed.\n");

    return 1;
  }

  if (pid > 0) {

    printf("Parent Process Started\n");

    printf("Parent PID: %ld\n", (long)getpid());

    srand(time(NULL));

    printf("Generating Numbers...\n");

    for (i = 0; i < 10; i++) {

      numbers[i] = rand() % 100 + 1;
    }

    printf("Generated Numbers: ");

    for (i = 0; i < 10; i++) {

      printf("%d", numbers[i]);

      if (i < 9) {

        printf(", ");
      }
    }

    printf("\n");

    close(pipeFD[0]);

    bytesWritten = write(pipeFD[1], numbers, sizeof(numbers));

    if (bytesWritten != sizeof(numbers)) {

      printf("ERROR\n");
      printf("Failed to send data.\n");

      return 1;
    }

    printf("Numbers Sent Successfully\n");

    close(pipeFD[1]);

    wait(NULL);

    printf("Parent Process Finished\n");
  }

  else {

    printf("Child Process Started\n");

    printf("Child PID: %ld\n", (long)getpid());

    close(pipeFD[1]);

    printf("Receiving Numbers...\n");

    bytesRead = read(pipeFD[0], receivedNumbers, sizeof(receivedNumbers));

    if (bytesRead <= 0) {

      printf("ERROR\n");
      printf("No data received.\n");

      exit(1);
    }

    close(pipeFD[0]);

    printf("Calculating Statistics...\n");

    minimumValue = receivedNumbers[0];

    maximumValue = receivedNumbers[0];

    for (i = 0; i < count; i++) {

      totalValue += receivedNumbers[i];

      if (receivedNumbers[i] < minimumValue) {

        minimumValue = receivedNumbers[i];
      }

      if (receivedNumbers[i] > maximumValue) {

        maximumValue = receivedNumbers[i];
      }
    }

    averageValue = (float)totalValue / count;

    for (i = 0; i < count; i++) {

      if (receivedNumbers[i] > averageValue) {

        aboveAverageCount++;
      }
    }

    percentAboveAverage = (aboveAverageCount * 100.0) / count;

    printf("----------------------------------------\n");

    printf("Count                 : %d\n", count);

    printf("Minimum               : %d\n", minimumValue);

    printf("Maximum               : %d\n", maximumValue);

    printf("Sum                   : %d\n", totalValue);

    printf("Average               : %.2f\n", averageValue);

    printf("Percent Above Average : %.2f%%\n", percentAboveAverage);

    printf("----------------------------------------\n");

    printf("Child Process Finished\n");
  }

  return 0;
}
