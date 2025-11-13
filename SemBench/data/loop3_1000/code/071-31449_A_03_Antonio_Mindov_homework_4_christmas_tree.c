#include <stdio.h>
void PrintTree(int height)
{
	int i,j;
	int spaces;
	for (i = 0; i < height; i += 1)
	{
		spaces = (height - 1) - i;
		for (j = 0; j < spaces; j += 1)
		{
			printf(" ");
		}
		for (j = 0; j < i*2 + 1; j += 1)
		{
			printf("*");
		}
		printf("\n");
	}
}
int main ()
{
	PrintTree(4);
	PrintTree(7);
	PrintTree(11);
	return 0;
}