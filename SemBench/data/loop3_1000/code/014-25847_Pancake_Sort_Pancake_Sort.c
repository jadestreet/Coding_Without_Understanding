#include <stdlib.h> 
#include <stdio.h> 
void flip (int arr[], int n) { 
    int temp, start = 0; 
    while (start < n) { 
        temp = arr[start]; 
        arr[start] = arr[n]; 
        arr[n] = temp; 
        start++; 
        n--; 
    } 
} 
int max_ind (int arr[], int n) { 
    int index = 0, i; 
    for (i = 0; i < n; ++i) 
        if (arr[i] > arr[index]) 
            index = i; 
    return index; 
} 
int pancakeSort (int arr[], int n) { 
    int size, max;
    for (size = n; size > 1; size--) { 
        max = max_ind(arr, size); 
        if (max != size-1) { 
            flip(arr, max);  
            flip(arr, size-1); 
        } 
    } 
}
int main() { 
    int arr[] = {-10, 1, 99, 10, -2, 0, 5, 6}; 
    int n, i;
    n = sizeof(arr)/sizeof(arr[0]); 
    printf("Unsorted Array: ");
    for(i = 0; i < n; i++)
    	printf("%d ", arr[i]);
    pancakeSort(arr, n); 
    printf("\nSorted Array: "); 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    return 0; 
} 