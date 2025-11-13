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
void mergeTwoSortedWithoutExtracSpace(int *pdata, int size, int secondPos)
{
	int i = 0;
	int j = secondPos;
	while (i < secondPos)
	{
		printf("i, j = %2d, %2d: ", i, j);
		printArray(pdata, size);
		if (pdata[j] <= pdata[i])
		{
			int temp = pdata[j];
			int k;
			for (k = j; k > i; k--)
			{
				pdata[k] = pdata[k - 1];
			}
			pdata[i] = temp;
			j++;
		}
		i++;
	}
	printf("i, j = %2d, %2d: ", i, j);
	printArray(pdata, size);
}
void mergeTwoSortedWithoutExtracSpace2(int *pdata, int size, int secondPos)
{
	int k;
	for (k = 0; k < secondPos; k++)
	{
		printf("k = %2d: %7c", k, ' ');
		printArray(pdata, size);
		int i = k;
		int j = secondPos;
		while ((i < secondPos) && (j < size))
		{
			if (pdata[j] <= pdata[i])
			{
				int temp = pdata[j];
				pdata[j] = pdata[i];
				pdata[i] = temp;
			}
			printf("i, j = %2d, %2d: ", i, j);
			printArray(pdata, size);
			i++;
			j++;
		}
		if (j < size)
		{
			int temp = pdata[j - 1];
			while (j < size)
			{
				if (pdata[j] <= temp)
				{
					pdata[j - 1] = pdata[j];
				}
				else
				{
					break;
				}
				printf("i, j = %2d, %2d: ", i, j);
				printArray(pdata, size);
				j++;
			}
			pdata[j - 1] = temp;
			printf("i, j = %2d, %2d: ", i, j);
			printArray(pdata, size);
		}
	}
}
int main(void)
{
	int data[] =
	{ 1, 3, 6, 8, -5, -2, 3, 8 };
	int size = sizeof(data) / sizeof(data[0]);
	mergeTwoSortedWithoutExtracSpace(data, size, 4);
	printf("----------\n");
	int data2[] =
	{ 1, 3, 8, 12, -5, -2, 4, 7, 9, 10 };
	int size2 = sizeof(data2) / sizeof(data2[0]);
	mergeTwoSortedWithoutExtracSpace2(data2, size2, 4);
	printf("----------\n");
	int data3[] =
	{ 1, 3, 8, 12, 16, 18, -5, -2, 4, 9 };
	int size3 = sizeof(data3) / sizeof(data3[0]);
	mergeTwoSortedWithoutExtracSpace2(data3, size3, 6);
	return EXIT_SUCCESS;
}