#include <stdio.h>
#include <string.h>

/* Not Quite Lisp: https://adventofcode.com/2015/day/1 */
int main() {
  char input[16384];
  FILE *inputfile = fopen("day1.txt", "r");
  if (inputfile == NULL) {
    perror("Failed to open input file.");
    return 1;
  }

  fscanf(inputfile, "%s", &input);
  fclose(inputfile);

  int floor = 0;
  int basement_entry = -1;

  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == '(') {
      floor++;
    } else {
      floor--;
    }

    if (basement_entry < 0 && floor < 0) {
      basement_entry = i + 1;
    }
  }
  printf("Floor: %d\n", floor);
  printf("Entered basement: %d\n", basement_entry);
  return 0;
}
