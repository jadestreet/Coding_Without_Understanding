#include <stdio.h>
#include <stdlib.h>
#define LOWEST_PRIME 2
void setArray(unsigned short int *Array, unsigned int ArraySize)
{
	unsigned int i;
	for (i = 0; i < ArraySize; i++) Array[i] = 1;
}
void printPrimes(unsigned short int *Array, unsigned int ArraySize)
{
	unsigned int i;
	for (i = 0; i < ArraySize; i++) if (Array[i]) printf("%d\t", i+2);
	printf("\n");
}
void getPrimes(unsigned int n)
{
	unsigned short int *PrimeNums = malloc((n-1)*sizeof(unsigned short int));
	setArray(PrimeNums, n-1);
	unsigned int actN;
	for (actN = LOWEST_PRIME; actN <= n; actN++) {
		while (!PrimeNums[actN-2]) actN++;
		unsigned int i;
		for (i = actN+actN; i <= n; i += actN) PrimeNums[i-2] = 0;
	}
	printPrimes(PrimeNums, n-1);
	free(PrimeNums);
}
int main(int argc, char **argv)
{
	int natNum = 0;
	if (argc == 2) {
		natNum = atoi(argv[1]);
		if (natNum >= LOWEST_PRIME) getPrimes((unsigned)natNum);
		else printf("%s: 'natural_number' must be at least %d\n", argv[0], LOWEST_PRIME);
	}
	else printf("Usage: %s natural_number\n", argv[0]);
	return 0;
}