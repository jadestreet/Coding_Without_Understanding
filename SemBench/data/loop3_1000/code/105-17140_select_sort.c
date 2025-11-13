#include <stdio.h>
void print(int *a,int n)
{
	for(; n > 0 ; )
		printf("%d ",a[--n]);
}
void select_sort(int a[], int n)
{
	int i, j, temp, min;
	for(i = 0; i < n - 1; i++)
	{
		min = i;
		for(j = i + 1; j < n; j++)
			if(a[j] < a[min])
				min = j;
		if(min != i)
		{
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
}
int main()
{
	int a[] = {1,9,7,3,2,5,6,4,0,8};
	int n = sizeof(a) / sizeof(int);
	select_sort(a,n);
	print(a,n);
	return 0;
}