#include <stdio.h>

int main() {
  int sales[5];
  int totalSales;
  float averageSales;
  int highestSales;
  int lowestSales;
  int busiestHours[5];
  int busiestCount = 0;
  int slowestHours[5];
  int slowestCount = 0;

  // Loop through the 5 hours instead of repeating the same block 5 times.
  for (int i = 0; i < 5; i++) {
    printf("How many cups were sold during hour %d? ", i + 1);
    while (scanf("%d", &sales[i]) != 1 || sales[i] < 0) {
      scanf("%*[^\n]"); // discard bad characters up to the newline
      scanf("%*c");     // discard the newline itself
      printf("Please enter a valid number of cups: ");
    }
  }

  printf(
      "\n----------------------\nSunrise Coffee Company\nDaily Sales Summary "
      "\n----------------------\n\n");

  printf("Sales by Hour\n\n");
  for (int i = 0; i < 5; i++) {
    printf("Hour %d: %d cups\n", i + 1, sales[i]);
  }

  totalSales = sales[0] + sales[1] + sales[2] + sales[3] + sales[4];
  averageSales = (float)totalSales / 5;

  printf("\nTotal Cups Sold: %d\n", totalSales);
  printf("Average per Hour: %.0f\n\n", averageSales);

  highestSales = sales[0];
  lowestSales = sales[0];
  for (int i = 1; i < 5; i++) {
    if (sales[i] > highestSales) {
      highestSales = sales[i];
    }
    if (sales[i] < lowestSales) {
      lowestSales = sales[i];
    }
  }

  // Collect every hour that matches the max/min, so ties of any size
  // (two, three, or more hours) are all reported correctly.
  for (int i = 0; i < 5; i++) {
    if (sales[i] == highestSales) {
      busiestHours[busiestCount] = i + 1;
      busiestCount++;
    }
    if (sales[i] == lowestSales) {
      slowestHours[slowestCount] = i + 1;
      slowestCount++;
    }
  }

  if (busiestCount == 1) {
    printf("Busiest Hour: %d (%d cups)\n", busiestHours[0], highestSales);
  } else {
    printf("Busiest Hours: ");
    for (int i = 0; i < busiestCount; i++) {
      printf("%d", busiestHours[i]);
      if (i < busiestCount - 1) {
        printf(" and ");
      }
    }
    printf(" (%d cups)\n", highestSales);
  }

  if (slowestCount == 1) {
    printf("Slowest Hour: %d (%d cups)\n", slowestHours[0], lowestSales);
  } else {
    printf("Slowest Hours: ");
    for (int i = 0; i < slowestCount; i++) {
      printf("%d", slowestHours[i]);
      if (i < slowestCount - 1) {
        printf(" and ");
      }
    }
    printf(" (%d cups)\n", lowestSales);
  }

  return 0;
}

return 0;
