#include <stdio.h>
unsigned int divisor_count(unsigned int n) {
    unsigned int total = 1;
    for (; (n & 1) == 0; n >>= 1) {
        ++total;
    }
    for (unsigned int p = 3; p * p <= n; p += 2) {
        unsigned int count = 1;
        for (; n % p == 0; n /= p) {
            ++count;
        }
        total *= count;
    }
    if (n > 1) {
        total *= 2;
    }
    return total;
}
int main() {
    const unsigned int limit = 100;
    unsigned int n;
    printf("Count of divisors for the first %d positive integers:\n", limit);
    for (n = 1; n <= limit; ++n) {
        printf("%3d", divisor_count(n));
        if (n % 20 == 0) {
            printf("\n");
        }
    }
    return 0;
}