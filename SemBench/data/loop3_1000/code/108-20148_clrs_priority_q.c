#include <stdio.h>
void heapify(int array[], int heap_size, int idx){
	int largest_idx = -1;
	int left = 2*(idx) + 1;
	int right = 2*(idx+1);
	if(left <= heap_size && array[left] > array[idx]){
		largest_idx = left;
	}else{
		largest_idx = idx;
	}
	if(right <= heap_size && array[right] > array[largest_idx]){
		largest_idx = right;
	}
	if(largest_idx != idx){
		int temp = array[largest_idx];
		array[largest_idx] = array[idx];
		array[idx] = temp;
		heapify(array, heap_size, largest_idx);
	}
}
int build_max_heap(int array[], int array_size){
	int heap_size = array_size - 1;
	int non_leaf_idx = heap_size / 2;
	for(;non_leaf_idx >= 0;non_leaf_idx--){
		heapify(array, heap_size, non_leaf_idx);
	}
	return heap_size;
}
int heap_max(int array[]){
	return array[0];
}
int pop_heap_max(int array[], int heap_size){
	int max = heap_max(array);
	array[0] = array[heap_size];
	heapify(array, heap_size-1,0);
	return max;
}
void heap_increase(int array[], int i, int key){
	array[i] = key;
	while(i > 0 && array[i/2] < array[i]){
		int temp = array[i/2];
		array[i/2] = array[i];
		array[i] = temp;
		i = i / 2;
	}
}
void insert(int array[], int heap_size, int key){
	heap_size++;
	array[heap_size] = -65535;
	heap_increase(array, heap_size, key);
}
int main(int argc, char const *argv[])
{
	int array[] = {3,2,5,1,6};
	build_max_heap(array, 5);
	insert(array, 5, 4);
	int k=0;
	for(;k<6;k++){
		printf("%d\n", array[k]);
	}
	return 0;
}