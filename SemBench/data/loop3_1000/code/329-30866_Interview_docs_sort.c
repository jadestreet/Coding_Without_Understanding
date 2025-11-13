#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int *arr);
void quick_sort(int *arr, int length);
void quick_sort_helper(int *arr, int first, int last);
void merge_sort(int *arr, int length);
void merge_sort_helper(int *arr, int left, int right);
int partition(int *arr, int left, int right);
void swap(int *a, int *b);
int main(){
	int a[] = {54,26,93,17,77,31,44,55,20}, i;
	merge_sort(a, 9);
	for(i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return EXIT_SUCCESS;
}
void insertion_sort(int *arr){
	int i, j, k, length = sizeof(arr) / sizeof(int);
	for(i = 0; i < length; i++){
		k = arr[i];
		j = i - 1;
		while(j >= 0 && k < arr[j]){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = k;
	}
}
void quick_sort(int *arr, int length){
	quick_sort_helper(arr, 0, length - 1);
}
void quick_sort_helper(int *arr, int first, int last){
	int part;
	if(first < last){
		part = partition(arr, first, last);
		quick_sort_helper(arr, first, part - 1);
		quick_sort_helper(arr, part + 1, last); 
	}
}
int partition(int *arr, int first, int last){
	int pivot = arr[first], done = 0, left = first + 1, right = last;
	while(!done){
		while(left <= right && arr[left] <= pivot) left++;
		while(left <= right && arr[right >= pivot]) right--;
		if(right < left){
			done = 1;
		} else {
			swap(&arr[left], &arr[right]);
		}
	}
	swap(&arr[right], &arr[first]);
	return right;
} 
void merge_sort(int *arr, int length){
	merge_sort_helper(arr, 0, length - 1);
}
void merge_sort_helper(int *arr, int left, int right){
	int mid;
	if(left < right){
		mid = left + (right - left) / 2;
		merge_sort_helper(arr, left, mid);
		merge_sort_helper(arr, mid + 1, right);
		int temp[right - left + 1], i = left, j = mid + 1, k = 0, m;
		while((i <= mid) && (j <= right)){
			if(arr[i] < arr[j]){
				temp[k] = arr[i];
				i++;
				k++;
			} else {
				temp[k] = arr[j];
				j++;
				k++;
			}
		}
		while(i <= mid){
			temp[k] = arr[i];
			k++;
			i++;
		}
		while(j <= right){
			temp[k] = arr[j];
			k++;
			j++;
		}
		for (m = right - left; m >= 0; m--){
			arr[right] = temp[m];
			right--;
		}
	}
}
void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}