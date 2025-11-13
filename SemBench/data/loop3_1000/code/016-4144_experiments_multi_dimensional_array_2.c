#include <stdio.h>
#define DIM1 2
#define DIM2 4
void print_array(char [DIM1][DIM2]);
void shift_array(char *);
int main(void) {
	char array[DIM1][DIM2] = {{'a', 'b', 'c', '\0'}, {'1', '2', '3', '\0'}};
	print_array(array); putchar('\n');
	shift_array(array[0]);
	print_array(array);
	return 0;
}
void print_array(char array[DIM1][DIM2]) {
	int element1;
	for (element1 = 0; element1 < DIM1; ++element1) {
		printf("Dimension %d:\n", element1 + 1);
		int element2;
		for (element2 = 0; array[element1][element2] != '\0'; ++element2)
			printf("\tarray[%d][%d] = %c\n", element1, element2, array[element1][element2]);
	}
}
void shift_array(char array[]) {
	int element = 0;
	while (array[element] != '\0')
		array[element++] += 5;
}