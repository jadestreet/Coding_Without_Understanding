#include <stdio.h>
void insertion_sort(int *arr, int arr_size) {
	int i, key, j;
	for (i = 1; i < arr_size; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}
int main() {
	int arr[] = {12, 11, 13, 5, 6};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	int i;
	insertion_sort(arr, arr_size);
	for (i = 0; i < arr_size; i++) {   
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}