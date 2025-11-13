#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void heap_down(int* a, int start,int end)
{	
	int cur = start;
	int left = start * 2 + 1;
	int right =  start * 2 + 2;
	for(; left < end; cur = left, left = cur * 2 + 1, right = cur * 2 + 2){
		if(left < end && a[left] < a[right]) 
			swap(&a[left], &a[right]);
		if(a[left] < a[cur])
			break;
		else
			swap(&a[left], &a[cur]);
	}
}
void heap_sort(int* a, int size)
{
	int i ;
	for (i = (size - 1)  / 2; i >= 0; i--)
		heap_down(a, i, size);
	printf("MAX is %d\n", a[0]);
	for( i = size  ; i > 1; i--){
		swap(&a[0], &a[i]);
		heap_down(a, 0, i - 1);
	}
}
int main()
{
	int a[10] = {3,1,5,8, 9, 4, 6};
	heap_sort(a, 6 );
	int i;
	for( i = 0; i < 7; i++)
	 	printf("%d\t",a[i]);
	 printf("\n");
}