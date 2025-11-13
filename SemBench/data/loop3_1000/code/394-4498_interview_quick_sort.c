#include <stdlib.h>
#include <stdio.h>
int partition(int* array, int low, int high) {
    int pivot = array[low];
    while (low < high) {
        for (; low < high && pivot <= array[high]; --high) {}
        array[low] = array[high];
        for (; low < high && pivot >= array[low]; ++low) {}
        array[high] = array[low];
    }
    array[low] = pivot;
    return low;
}
void quick_sort(int* array, int low, int high) {
    if (low >= high) {
        return;
    }
    int pivot = partition(array, low, high);
    quick_sort(array, low, pivot - 1);
    quick_sort(array, pivot + 1, high);
}
int main(int argc, char* argv[]) {
    int array[] = {49, 38, 65, 97, 76, 13, 27, 49}; 
    quick_sort(array, 0, sizeof(array) / sizeof(int) - 1);
    int i = 0;
    for (; i < sizeof(array) / sizeof(int); ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}