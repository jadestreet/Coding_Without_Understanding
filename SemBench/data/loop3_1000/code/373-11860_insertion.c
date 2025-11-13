#include <stdio.h>
#include <stdlib.h>
void insertion_sort(int * array, int length){
    int key, i, j;
    for (i = 1; i < length; i ++) {
        j = i - 1;
        key = array[i];
        while (j >= 0 & array[j] > key){
            array[j+1] = array[j];
            j = j - 1;
        }
        array[j+1] = key;
    }
    for (i = 0; i < length; i ++) {
        printf("array[%d] = %d, ", i, array[i]);
    }
}
int main(){
    int array[] = {0, 1, 2, -1, 4, 2, 3};
    insertion_sort(array, 7);
    return 0;
}