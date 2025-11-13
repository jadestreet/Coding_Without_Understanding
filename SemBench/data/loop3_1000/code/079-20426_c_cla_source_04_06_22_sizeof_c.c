#include <stdio.h>
int main(void) {
	printf("This computing enviroments uses:\n");
	printf("%d byte for chars\n",sizeof(char));
	printf("%d bytes for shorts\n",sizeof(short int));
	printf("%d bytes for ints\n",sizeof(int));
	printf("%d bytes for longs\n",sizeof(long int));
	printf("%d bytes for long longs\n",sizeof(long long int));
	printf("%d bytes for floats\n",sizeof(float));
	printf("%d bytes for doubles\n",sizeof(double));
	printf("%d bytes for pointers\n",sizeof(int *));
	return 0;
} 