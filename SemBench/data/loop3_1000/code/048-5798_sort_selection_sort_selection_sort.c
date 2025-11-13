#include <stdio.h>
#define ARR_NELEMENTS 10
void
swap(int arr[], int a, int b)
{
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
int selection_sort(int arr[], int n)
{
	int i, j, min_index;
	for(i = 0; i < n ;  i++) {
		min_index = i;
		for(j = i+1; j < n; j++) {
			if(arr[min_index] > arr[j])
				min_index = j;
		}
		if(min_index != i)
			swap(arr, min_index, i);
	}
}
void
print_arr(int arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf(" %d", arr[i]);
	printf("\n");
}
int
main()
{
	int arr[ARR_NELEMENTS] = {8, 44, 6, 99, 0, -11, -15, -7, 10, -3};
	print_arr(arr, ARR_NELEMENTS);
	selection_sort(arr,ARR_NELEMENTS);
	print_arr(arr, ARR_NELEMENTS);
}