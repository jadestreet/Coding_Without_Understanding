#include <stdio.h>
#define	SIZE	100	
int primeFactor(unsigned long int num, unsigned long int *p2a);
int primeCheck(unsigned long int num);
int main(void) {
	unsigned long int factors[SIZE];
	const unsigned long int BIGNUM = 600851475143;
	for (int pre = 0; pre < SIZE; pre++) {
		*(factors+pre) = 0;
	}
	primeFactor(BIGNUM, factors);
	for (int i = 0; i < SIZE; i++) {	
		printf("%lu ", factors[i]);
	}
	return 0;
}
int primeFactor(unsigned long int num, unsigned long int *p2a) {
	int j = 0;
	for (unsigned long int i = 2; i <= num; i++) {
		while (num % i == 0) {
			num /= i;
			*(p2a+(j++)) = i;	
		}
	}
	return 0;
}