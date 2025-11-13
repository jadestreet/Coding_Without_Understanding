#include <stdio.h>
#define KANALY 3
#define WIERSZE 5
#define KOLUMNY 6
void odwrocWiersz(int tab[], int rozmiar)
{
	int temp, i, j;
	for (i = 0, j = rozmiar - 1; i < j; i++, j--)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
	}
}
int main(void)
{
	int obraz[KANALY][WIERSZE][KOLUMNY];
	int i, j, k, l, wartosc = 0;
	int temp;
	for (i = 0; i < KANALY; i++)
	{
		for (j = 0; j < WIERSZE; j++)
		{
			for (k = 0; k < KOLUMNY; k++)
			{
				obraz[i][j][k] = wartosc++;
			}
		}
		wartosc = (i == 1) ? 1000 : 100;
	}
	printf("\nWypelniona tablica reprezentujaca obraz:\n\n");
	for (i = 0; i < KANALY; i++)
	{
		printf("Kanal nr: %d\n", i);
		for (j = 0; j < WIERSZE; j++)
		{
			for (k = 0; k < KOLUMNY; k++)
			{
				printf("%d ", obraz[i][j][k]);
			}
			printf("\n");
		}
	}
	for (i = 0; i < KANALY; i++)
	{
		for (j = 0; j < WIERSZE; j++)
		{
			for (k = 0, l = KOLUMNY - 1; k < l; k++, l--)
			{
				temp = obraz[i][j][k];
				obraz[i][j][k] = obraz[i][j][l];
				obraz[i][j][l] = temp;
			}
		}
	}
	printf("\nPo odbiciu wzgledem osi pionowej:\n\n");
	for (i = 0; i < KANALY; i++)
	{
		printf("Kanal nr: %d\n", i);
		for (j = 0; j < WIERSZE; j++)
		{
			for (k = 0; k < KOLUMNY; k++)
			{
				printf("%d ", obraz[i][j][k]);
			}
			printf("\n");
		}
	}
	return 0;
}