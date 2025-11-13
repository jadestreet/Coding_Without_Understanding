#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
# define MAX_INT 32768
void printData(int *pdata, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (*(pdata + (i * size) + j) == MAX_INT)
			{
				printf("  MAX");
			}
			else
			{
				printf("%5d", *(pdata + (i * size) + j));
			}
		}
		printf("\n");
	}
	printf("\n");
}
int reCalculate(int *pdata, int size, int *prow, int *pcolumn)
{
	int cost = 0;
	int i, j, k;
	for (k = 0; k <= 1; k++)
	{
		for (i = 0; i < size; i++)
		{
			if ((k == 0 ? prow[i] : pcolumn[i]) == 0)
			{
				int minValue = MAX_INT;
				for (j = 0; j < size; j++)
				{
					int *pcell = pdata + (i * (k == 0 ? size : 1)) + (j * (k == 1 ? size : 1));
					if ((*pcell != MAX_INT) && (*pcell < minValue))
					{
						minValue = *pcell;
					}
				}
				if (minValue > 0)
				{
					cost += minValue;
					for (j = 0; j < size; j++)
					{
						int *pcell = pdata + (i * (k == 0 ? size : 1)) + (j * (k == 1 ? size : 1));
						if (*pcell != MAX_INT)
						{
							*pcell -= minValue;
						}
					}
				}
			}
		}
	}
	return cost;
}
int main(void)
{
	int size = 5;
	int data[][5] =
	{
	{ MAX_INT, 17, 13, 24, 10 },
	  { 10, MAX_INT, 20, 9, 6 },
	  { 17, 29, MAX_INT, 21, 28 },
	  { 12, 10, 22, MAX_INT, 19 },
	  { 12, 18, 31, 20, MAX_INT } };
	int row[size], column[size];
	int count, selectCity;
	int cost, totalCost;
	int i, j;
	for (i = 0; i < size; i++)
	{
		row[i] = 0;
		column[i] = 0;
	}
	printf("Original:\n");
	printData(*data, size);
	totalCost = reCalculate(*data, size, row, column);
	printf("Pre-processed, cost = %d\n", totalCost);
	printData(*data, size);
	selectCity = 0;
	count = 1;
	do
	{
		printf("Select city = %d\n", selectCity);
		row[selectCity] = count;
		for (i = 0; i < size; i++)
		{
			data[selectCity][i] = MAX_INT;
		}
		int dataTemp[size][size];
		int columnTemp[size];
		int minCost = MAX_INT;
		for (i = 0; i < size; i++)
		{
			if (row[i] == 0)
			{
				printf("Test city = %d, ", i);
				memcpy(dataTemp, data, sizeof(int) * size * size);
				memcpy(columnTemp, column, sizeof(int) * size);
				for (j = 0; j < size; j++)
				{
					dataTemp[j][i] = MAX_INT;
				}
				columnTemp[i] = 1;
				cost = reCalculate(*dataTemp, size, row, columnTemp);
				printf("cost = %d\n", cost);
				if (cost < minCost)
				{
					minCost = cost;
					selectCity = i;
				}
			}
		}
		for (i = 0; i < size; i++)
		{
			data[i][selectCity] = MAX_INT;
		}
		count++;
		column[selectCity] = count;
		cost = reCalculate(*data, size, row, column);
		totalCost += cost;
		printf("Next city = %d, cost = %d\n", selectCity, cost);
		printData(*data, size);
	} while (count < size);
	row[selectCity] = count;
	printf("City -> Sequence\n");
	for (i = 0; i < size; i++)
	{
		printf("%3d  -> %4d\n", i, row[i]);
	}
	printf("Total cost = %d\n", totalCost);
	return EXIT_SUCCESS;
}