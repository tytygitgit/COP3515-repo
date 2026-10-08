#include <stdio.h>
#include <string.h>

#define MAX_PRESENTERS 10

int findLongestLength(int argc, char *argv[]);
int isDuplicate(int currentIndex, char *argv[]);

int main(int argc, char *argv[]) {
  int i;
  int uniqueCount;
  int longestLength;

  if (argc < 2) {
    printf("ERROR: No presenter names supplied.\n");
    return 1;
  }

  if ((argc - 1) > MAX_PRESENTERS) {
    printf("ERROR: Maximum number of presenters is %d.\n", MAX_PRESENTERS);
    return 1;
  }

  for (i = 1; i < argc; i++) {
    if (strchr(argv[i], ' ') != NULL) {
      printf("ERROR: Presenter names cannot contain spaces.\n");
      return 1;
    }
  }

  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "Dr.") == 0 || strcmp(argv[i], "Professor") == 0) {
      printf("ERROR: Titles are not valid presenter names.\n");
      return 1;
    }
  }

  uniqueCount = 0;

  for (i = 1; i < argc; i++) {
    if (!isDuplicate(i, argv)) {
      uniqueCount++;
    }
  }

  printf("----------------------------------------\n");
  printf("National Technology Conference Presenter Summary\n");
  printf("----------------------------------------\n\n");

  printf("Presenters\n\n");

  for (i = 1; i < argc; i++) {
    if (!isDuplicate(i, argv)) {
      printf("%d. %s\n", uniqueCount - (uniqueCount - i), argv[i]);
    }
  }

  longestLength = findLongestLength(argc, argv);

  printf("\n----------------------------------------\n\n");

  printf("Total Presenters : %d\n", uniqueCount);

  printf("Longest Name(s)  :\n");

  for (i = 1; i < argc; i++) {
    if (!isDuplicate(i, argv) && strlen(argv[i]) == longestLength) {
      printf("%s\n", argv[i]);
    }
  }

  printf("Characters       : %d\n", longestLength);

  return 0;
}

int findLongestLength(int argc, char *argv[]) {
  int i;
  int longestLength;

  longestLength = 0;

  for (i = 1; i < argc; i++) {
    if (!isDuplicate(i, argv)) {
      if (strlen(argv[i]) > longestLength) {
        longestLength = strlen(argv[i]);
      }
    }
  }

  return longestLength;
}

int isDuplicate(int currentIndex, char *argv[]) {
  int j;

  for (j = 1; j < currentIndex; j++) {
    if (strcmp(argv[currentIndex], argv[j]) == 0) {
      return 1;
    }
  }

  return 0;
}
