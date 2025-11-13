#include <stdio.h>
#define LIMIT 10
int main()
{
	int arr[LIMIT+1][LIMIT+1];
	int row,col;
	for(row=1;row<=LIMIT;row++)
	{
		arr[row][1]=1;
		for(col=2;col<row;col++)
		{
			arr[row][col] = arr[row-1][col-1] + arr[row-1][col];	
		}
		arr[row][row] = 1;
	}
	for(row=1;row<=LIMIT;row++)
	{
		for(col=1;col<=row;col++)
		{
			printf("%d ",arr[row][col]);
		}
		printf("\n");
	}
	return 0;
}