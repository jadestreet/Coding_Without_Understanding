#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOT_PRIME 0
#define PRIME 1
#define UPPER_LIMIT 1000
int main() {
	char isPrime[1 + UPPER_LIMIT];
	memset(isPrime, PRIME, 1 + UPPER_LIMIT);
	isPrime[0] = NOT_PRIME;
	isPrime[1] = NOT_PRIME;
	for (int i = 2; i <= UPPER_LIMIT; i++) {
		if (isPrime[i] == PRIME) {
			for (int j = 2 * i; j <= UPPER_LIMIT; j += i) {
				isPrime[j] = NOT_PRIME;
			}
		}
	}
	for (int i = 0; i < 1 + UPPER_LIMIT; i++) {
		if (isPrime[i] == PRIME) {
			printf("%d\n", i);
		}
	}
	return EXIT_SUCCESS;
}