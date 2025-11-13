#include <stdio.h>
#include <stdlib.h>
void insert_sort(int *arr, int total_n) {
    int i, j, current;
    for (i = 0; i < total_n; i++) {
        current = arr[i];
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] <= current) {
                break;                }
                arr[j+1] = arr[j];
            }
            arr[j+1] = current;
        }
    }
    int main(){
        int a[8] = {83,72,555,23,12,9,1000};
        printf("the unsorted array is: \n");
        int i = 0;
        for(i = 0;i<8;i++){
            printf("\t%d", a[i]);
        }
        printf("\n");
        insert_sort(a, 8);
        printf("the sorted array is: \n");
        for(i=0;i<8;i++){
            printf("\t%d", a[i]);
        }
        printf("\n");
    }