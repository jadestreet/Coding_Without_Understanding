#include<stdio.h>
#include <stdlib.h>
int check_number(int number, int n)
{
	int m;
	int i = 0;
	do {
		m = number % 10;
		if (m == 9)
			i++;
	} while (number /= 10);
	return i;
}
int main(int argc, char *argv[])
{
	int n = atoi(argv[1]), i = 0;
	while (n) {
		i += check_number(n, 9);
		n--;
	}
	printf("there are %d 9 beetwin 1 and  %s\n", i, argv[1]);
	return 0;
}