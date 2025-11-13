#include <stdio.h>
#include <stdlib.h>
int findNdigits(int n) {
    int digmodulus, ndigits, modulus;
    digmodulus = 1;
    ndigits = 1;
    modulus = 1 % n;
    while (modulus != 0) {
      digmodulus = (digmodulus * 10) % n;
      modulus = (modulus + digmodulus) % n;
      ndigits++;
    }
    return(ndigits);
}
int main(int argc, char * argv[]) {
    int n, i, maxdigits, maxdigitsi, ndigits;
    if (argc != 2) {
        printf("ERROR: invalid or missing argument\n");
        printf("USAGE: %s n\n", argv[0]);
        return(1);
    }
    n = atoi(argv[1]);
    if (n % 2 == 0 || n % 5 == 0) {
        printf("ERROR: Invalid argument.  n must not be divisible by 2 or 5.\n");
        return(1);
    }
    if (n < 0) {
        maxdigits = 0;
        maxdigitsi = 0;
        for (i = 1; i < -n; i++) {
            if (i % 2 != 0 && i % 5 != 0) {
                ndigits = findNdigits(i);
                printf("%6d: %d\n", i, ndigits);
                if (maxdigits < ndigits) {
                    maxdigits = ndigits;
                    maxdigitsi = i;
                }
            }
        }
        printf("max ndigits = %d for n = %d\n", maxdigits, maxdigitsi);
    } else {
        ndigits = findNdigits(n);
        printf("%6d: %d\n", n, ndigits);
    }
    return(0);
}