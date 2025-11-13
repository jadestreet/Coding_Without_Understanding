#include <stdio.h>
int main(void)
{
	int nextMultiple;
	int i,j;
	i = 365;
	j = 7;
	nextMultiple = i + j - i % j;
	printf("Next largest even multiple of %i for %i is %i\n", j, i, nextMultiple);
	i = 12258;
	j = 23;
	nextMultiple = i + j - i % j;
	printf("Next largest even multiple of %i for %i is %i\n", j, i, nextMultiple);
	i = 996;
	j = 4;
	nextMultiple = i + j - i % j;
	printf("Next largest even multiple of %i for %i is %i\n", j, i, nextMultiple);
	return 0;
}