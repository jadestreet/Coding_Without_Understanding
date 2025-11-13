#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TEST_COUNT      100000000
#define TEST_COUNT_HALF (unsigned)TEST_COUNT >> 1
unsigned char prime_list[TEST_COUNT_HALF] = {0};
int main(void)
{
    int i, j;
    int sum = 0;
    int count = TEST_COUNT;
    int root = sqrt(count);
    for(i = 3; i <= root; i += 2) {
        if(!prime_list[(unsigned)(i - 1) >> 1]) {
            for(j = i * i; j <= count; j += i << 1) {
                prime_list[(unsigned)(j - 1) >> 1] = 1;
            }
        }
    }
    if(count >= 2) {
        printf("%d\n", i);
        sum++;
    }
    for(i = 3; i <= count; i += 2) {
        if(!prime_list[(unsigned)(i - 1) >> 1]) {
            printf("%d\n", i);
            sum++;
        }
    }
    printf("sum of the prime number to %d is %d.\n", count, sum);
    return EXIT_SUCCESS;
}