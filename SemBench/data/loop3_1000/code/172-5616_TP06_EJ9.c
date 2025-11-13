#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double randNormalize(void);
void stdDesv(unsigned char * puntNewArreglo, unsigned char arreglo[]);
void makeArray(unsigned char * puntArreglo);
#define DIM 6
#define COL 2
int main(void) {
	srand(time(0));
	unsigned char arreglo[DIM];
	unsigned char * puntArreglo = arreglo;
	unsigned char newArreglo[DIM][COL];
	unsigned char * puntNewArreglo = newArreglo;
	int j, i;
	makeArray(puntArreglo);
	printf("Vector:\n");
	for(i = 0; i < DIM; i++) {
		printf("%hhx\t", arreglo[i]);
	}
	stdDesv(puntNewArreglo, arreglo);
	printf("\nMatriz:\n");
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < COL; j++) {
			printf("%d\t", newArreglo[i][j]);
		}
		printf("\n");
	}
}
void stdDesv(unsigned char * puntNewArreglo, unsigned char arreglo[]) {
	int i, j;
	for (i = 0, j = 0; i < (DIM * COL); j++, i+=COL) {
			puntNewArreglo[i] = arreglo[j] & 0xF0;
			puntNewArreglo[i] = puntNewArreglo[i] >> 4;
			puntNewArreglo[i+1] = arreglo[j] & 0x0F;
	}
}
void makeArray(unsigned char * puntArreglo) {
	int i;
	randNormalize();
	for(i = 0; i < DIM; i++) {
		puntArreglo[i] = (char) (randNormalize() * (0xFF));
	}
}
double randNormalize(void) {
	return rand() / ((double) RAND_MAX + 1);
}