#include <stdio.h>
#include <stdlib.h>
void printArray(int data[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%4d", data[i]);
	}
	printf("\n");
}
void findTwoNonRepeatElements(int *pdata, int size, int *pX, int *pY)
{
	int i;
	int sum = 0;
	for (i = 0; i < size; i++)
	{
		sum ^= pdata[i];
	}
	printf("Sum = %04X\n", sum);
	i = 0;
	while ((sum & 1) == 0)
	{
		sum >>= 1;
		i++;
	}
	printf("First 1 from left (position from 0) = %d\n", i);
	int flag = 1;
	while (i > 0)
	{
		flag <<= 1;
		i--;
	}
	printf("Flag = %04X\n", flag);
	for (i = 0; i < size; i++)
	{
		if (pdata[i] & flag)
		{
			*pX ^= pdata[i];
		}
		else
		{
			*pY ^= pdata[i];
		}
	}
	printf("X = %d\n", *pX);
	printf("Y = %d\n", *pY);
}
int main(void)
{
	int data[] =
	{ 2, 3, 7, 9, 11, 2, 3, 11 };
	int size = sizeof(data) / sizeof(data[0]);
	int x = 0;
	int y = 0;
	printArray(data, size);
	findTwoNonRepeatElements(data, size, &x, &y);
}