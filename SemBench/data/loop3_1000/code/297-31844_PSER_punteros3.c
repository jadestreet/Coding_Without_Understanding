#include <stdio.h>
int main(int argc, char **argv) {
	int mat[3][5] = {{ 23,1,54,3,14 }, { 5,67,7,8,9 }, { 10,111,12,13,14 }};
	int i, j;
	printf("sizeof(int): %d\n", sizeof(int));
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 5; j++) {
			printf("[%d][%d]. %p\n", i, j, &mat[i][j]);
		}
	}
	printf("\n");
	for(i = 0; i < 3; i++) {
		printf("[%d]. %p\n", i, mat+i);
		printf("[%d]. %d\n", i, **(mat+i));
	}
	printf("\n");
	for(i = 0; i < 15; i++) {
		printf("[%d]. %p\n", i, *(mat+i));
		printf("%d\n", *(*mat+i));
	}
	return 0;
}