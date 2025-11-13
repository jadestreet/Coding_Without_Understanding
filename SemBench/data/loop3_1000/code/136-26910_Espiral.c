#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define F 4
#define C 4
int main()
{                                             
	int mat[4][4], n, cont, i, j, inicio, limite;
	n=4;
	cont=1;
	inicio=0;
	limite=n-1;
    while(cont<=(n*n))
    {
    	for(i=inicio;i<=limite;i++)
    	{
    		mat[inicio][i]=cont;
    		cont++;
		}
		for(i=inicio+1;i<=limite;i++)
		{
			mat[i][limite]=cont;
			cont++;
		}
		for(i=limite-1;i>inicio;i--)
		{
			mat[limite][i]=cont;
			cont++;
		}
		for(i=limite-1;i>inicio+1;i--)
		{
			mat[i][inicio]=cont;
			cont++;
		}
		inicio=inicio+1;
		limite=limite-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");	
	}	
}