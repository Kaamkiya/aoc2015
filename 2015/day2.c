#include <stdio.h>
#include <string.h>

unsigned int smallest_area(unsigned int area0, unsigned int area1, unsigned int area2) {
	if (area0 <= area1 && area0 <= area2) {
		return area0;
	}
	if (area1 <= area0 && area1 <= area2) {
		return area1;
	}
	return area2;
}

unsigned int smallest_perimeter(unsigned int l, unsigned int w, unsigned int h) {
	unsigned int array[2];
	array[0] = l;
	
	if (w < array[0]) {
		array[1] = l;
		array[0] = w;
	} else {
		array[1] = w;
	}
	
	if (h < array[0]) {
		array[1] = array[0];
		array[0] = h;
	} else if (h < array[1]) {
		array[1] = h;
	}
	
	return 2 * array[0] + 2 * array[1];
}

int main() {
	char buffer[128];
	unsigned int total_wrap = 0;
	unsigned int total_ribbon = 0;
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

		total_wrap += 2*l*w + 2*w*h + 2*h*l + smallest_area(l*w, w*h, h*l);
		total_ribbon += smallest_perimeter(l, w, h) + l*w*h; /* Shortest perimeter plus volume */
	}

	printf("Total wrapping paper: %u\n", total_wrap);
	printf("Total ribbon: %u\n", total_ribbon);
}
