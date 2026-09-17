#include <stdio.h>

int main() {

  float hoursParked;
  int vehicleCount = 0;

  float parkingCharge;
  float totalRevenue = 0;
  float averageParkingFee = 0;
  float charges[100];

  char moreVehicles = 'Y';
  char response[10];

  while (moreVehicles == 'Y' || moreVehicles == 'y') {

    printf("Vehicle %d Hours Parked: ", vehicleCount + 1);

    while (scanf("%f", &hoursParked) != 1 || hoursParked < 0) {

      while (getchar() != '\n')
        ;

      printf("Please enter a valid number of hours: ");
    }

    while (getchar() != '\n')
      ;

    parkingCharge = hoursParked * 2.0;

    if (parkingCharge > 50) {
      parkingCharge = 50;
    }

    charges[vehicleCount] = parkingCharge;

    printf("Vehicle %d Charge: $%.2f\n\n", vehicleCount + 1, parkingCharge);

    totalRevenue += parkingCharge;
    vehicleCount++;

    printf("More vehicles? ");
    fgets(response, sizeof(response), stdin);

    while (response[0] != 'Y' && response[0] != 'N' && response[0] != 'y' &&
           response[0] != 'n') {

      printf("Please enter a valid response (Y/N): ");
      fgets(response, sizeof(response), stdin);
    }

    moreVehicles = response[0];

    printf("\n");
  }

  if (vehicleCount > 0) {
    averageParkingFee = totalRevenue / vehicleCount;
  } else {
    averageParkingFee = 0;
    totalRevenue = 0;
  }

  printf("-------------------------\n");
  printf("Downtown Parking Services\n");
  printf("Parking Summary\n");
  printf("-------------------------\n\n");

  printf("Vehicle Charges\n\n");

  for (int i = 0; i < vehicleCount; i++) {
    printf("Vehicle %d Charge: $%.2f\n", i + 1, charges[i]);
  }

  printf("\n");
  printf("Vehicles Processed : %d\n", vehicleCount);
  printf("Total Revenue      : $%.2f\n", totalRevenue);
  printf("Average Parking Fee: $%.2f\n", averageParkingFee);

  return 0;
}
