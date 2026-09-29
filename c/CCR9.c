#include <stdio.h>

void calculateVolume(float length, float width, float height, float *volume);
void calculateSurfaceArea(float length, float width, float height,
                          float *surfaceArea);

int main() {

  float length;
  float width;
  float height;

  float volume;
  float surfaceArea;

  const float MAX_LENGTH = 39.0;
  const float MAX_WIDTH = 7.4167;
  const float MAX_HEIGHT = 7.5;

  printf("Enter Length (feet): ");
  while (scanf("%f", &length) != 1 || length <= 0 || length > MAX_LENGTH) {
    while (getchar() != '\n')
      ;

    printf("\nERROR\n");
    printf("Length must be greater than 0 and must not exceed more than %.2f "
           "feet.\n",
           MAX_LENGTH);
    printf("\nEnter Length (feet): ");
  }

  printf("Enter Width (feet): ");
  while (scanf("%f", &width) != 1 || width <= 0 || width > MAX_WIDTH) {
    while (getchar() != '\n')
      ;

    printf("\nERROR\n");
    printf("Width must be greater than 0 and must not exceed more than %.2f "
           "feet.\n",
           MAX_WIDTH);
    printf("\nEnter Width (feet): ");
  }

  printf("Enter Height (feet): ");
  while (scanf("%f", &height) != 1 || height <= 0 || height > MAX_HEIGHT) {
    while (getchar() != '\n')
      ;

    printf("\nERROR\n");
    printf("Height must be greater than 0 and must not exceed more than %.2f "
           "feet.\n",
           MAX_HEIGHT);
    printf("\nEnter Height (feet): ");
  }

  calculateVolume(length, width, height, &volume);

  calculateSurfaceArea(length, width, height, &surfaceArea);

  printf("\n-------------------------------------\n");
  printf("Atlantic Shipping & Logistics\n");
  printf("Package Measurement Report\n");
  printf("-------------------------------------\n\n");

  printf("Length       : %.2f\n", length);
  printf("Width        : %.2f\n", width);
  printf("Height       : %.2f\n", height);

  printf("\n-------------------------------------\n");

  printf("Volume       : %.2f cubic units\n", volume);
  printf("Surface Area : %.2f square units\n", surfaceArea);

  return 0;
}

void calculateVolume(float length, float width, float height, float *volume) {
  *volume = length * width * height;
}

void calculateSurfaceArea(float length, float width, float height,
                          float *surfaceArea) {
  *surfaceArea = 2 * ((length * width) + (length * height) + (width * height));
}
