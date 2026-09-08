#include <stdio.h>

int main() {
  int sales[5];
  int totalSales = 0;
  float averageSales;
  int highestSales;
  int lowestSales;
  int busiestHour = 1;
  int slowestHour = 1;
  int otherBusiestHour = 1;
  int otherSlowestHour = 1;

  printf("How many cups were sold during hour 1? ");
  scanf("%d", &sales[0]);
  printf("How many cups were sold during hour 2? ");
  scanf("%d", &sales[1]);
  printf("How many cups were sold during hour 3? ");
  scanf("%d", &sales[2]);
  printf("How many cups were sold during hour 4? ");
  scanf("%d", &sales[3]);
  printf("How many cups were sold during hour 5? ");
  scanf("%d", &sales[4]);

  printf(
      "\n----------------------\nSunrise Coffee Company\nDaily Sales Summary "
      "\n----------------------\n\n");

  printf("Sales by Hour\n\n");

  printf("Hour 1: %d cups\n", sales[0]);
  printf("Hour 2: %d cups\n", sales[1]);
  printf("Hour 3: %d cups\n", sales[2]);
  printf("Hour 4: %d cups\n", sales[3]);
  printf("Hour 5: %d cups\n\n", sales[4]);

  printf("Total Cups Sold: %d\n",
         sales[0] + sales[1] + sales[2] + sales[3] + sales[4]);
  printf("Average per Hour: %.1f\n\n",
         (float)(sales[0] + sales[1] + sales[2] + sales[3] + sales[4]) / 5);

  highestSales = sales[0];
  lowestSales = sales[0];

  for (int i = 0; i < 5; i++) {
    totalSales += sales[i];

    if (sales[i] > highestSales) {
      highestSales = sales[i];
      busiestHour = i + 1;
      otherBusiestHour =
          busiestHour; // Reset otherBusiestHour when a new highest is found
    }

    if (sales[i] < lowestSales) {
      lowestSales = sales[i];
      slowestHour = i + 1;
      otherSlowestHour =
          slowestHour; // Reset otherSlowestHour when a new lowest is found
    }

    if (sales[i] == highestSales && i + 1 != busiestHour) {
      otherBusiestHour = i + 1;
    }

    if (sales[i] == lowestSales && i + 1 != slowestHour) {
      otherSlowestHour = i + 1;
    }
  }

  if (otherBusiestHour == busiestHour) {
    printf("Busiest Hour: %d (%d cups)\n", busiestHour, highestSales);
  } else {
    printf("Busiest Hours: %d and %d (%d cups)\n", busiestHour,
           otherBusiestHour, highestSales);
  }

  if (otherSlowestHour == slowestHour) {
    printf("Slowest Hour: %d (%d cups)\n", slowestHour, lowestSales);
  } else {
    printf("Slowest Hours: %d and %d (%d cups)\n", slowestHour,
           otherSlowestHour, lowestSales);
  }
}
