#include <math.h>
#include <stdio.h>
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d,", arr[i]);
	printf("\n");
}
int main()
{
	int arr[] = { 18, 12, 8, 14, 13, 16, 29, 17, 5, 26, 11, 20, 3, 1, 7, 28, 4, 2, 15, 0, 9, 24, 27, 23, 21, 22, 10, 19, 25, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	insertionSort(arr, n);
	printArray(arr, n);
	for (int i = 0; i < n; ++i)
        if (arr[i] != i)
            return i + 1;
	return 0;
}