#include <stdio.h>
#include <string.h>

unsigned int smallest_dimension (unsigned int dim0, unsigned int dim1, unsigned int dim2) {
  if (dim0 <= dim1 && dim0 <= dim2) {
    return dim0;
  }
  if (dim1 <= dim0 && dim1 <= dim2) {
    return dim1;
  }
  return dim2;
}

int main() {
  char buffer[128];
  unsigned int total_wrap = 0;
  unsigned int l = 0;
  unsigned int w = 0;
  unsigned int h = 0;

  FILE *inputfile = fopen("day2.txt", "r");
  if (inputfile == NULL) {
    perror("Error: failed to open file");
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), inputfile) != NULL) {
    if (buffer[strlen(buffer) - 1] == '\n') {
      buffer[strlen(buffer) - 1] = '\0';
    }

    sscanf(buffer, "%ux%ux%u", &l, &w, &h);

    total_wrap += 2*l*w + 2*w*h + 2*h*l + smallest_dimension(l*w, w*h, h*l);
  }

  printf("Total wrapping paper: %u\n", total_wrap);
}

