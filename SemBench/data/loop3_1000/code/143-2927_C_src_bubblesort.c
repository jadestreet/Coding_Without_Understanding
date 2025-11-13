#include <stdio.h>
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(int arr[], int n)
{
int i, j;
for (i = 0; i < n-1; i++)
	for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);
}
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d,", arr[i]);
	printf("\n");
}
int main()
{
	int arr[] = { 18, 12, 8, 14, 13, 16, 29, 17, 5, 26, 11, 20, 3, 1, 7, 28, 4, 2, 15, 0, 9, 24, 27, 23, 21, 22, 10, 19, 25, 6 };
	int n = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, n);
	printf("Sorted array:");
	printArray(arr, n);
	for (int i = 0; i < n; ++i)
        if (arr[i] != i)
            return i + 1;
	return 0;
}