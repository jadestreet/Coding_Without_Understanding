#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#ifndef MAX
#define  MAX 20
#endif
int array[MAX]={3, 44, 38,  5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48,33,33};
int binary_search(const int arr[], int start, int end, int key) {
	if (start > end)
		return -1;
	int mid = start + (end - start) / 2; 
	if (arr[mid] > key)
		return binary_search(arr, start, mid - 1, key);
	if (arr[mid] < key)
		return binary_search(arr, mid + 1, end, key);
	return mid; 
}
void sort_b(){
    int i_unsorted=MAX;
    int swapped=1;
    while (swapped==1) {
        swapped=0;
        for(int i=0;i<i_unsorted;i++){
            if (array[i+1]<array[i]){
                int temp;
                temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                swapped=1;
            }
        }
        i_unsorted--;
    }
}
int main(int argc, char const *argv[]) {
    for(int i=0;i<MAX;i++){
        printf("%d ", array[i]);
    }
    printf("\n\n" );
    sort_b();
    printf("\n--------after sorted----------\n" );
    for(int i=0;i<MAX;i++){
        printf("%d ", array[i]);
    }
    int index_find;
    index_find=binary_search(array,1,MAX,44);
    printf("\n44 is %d\n",index_find );
    return 0;
}