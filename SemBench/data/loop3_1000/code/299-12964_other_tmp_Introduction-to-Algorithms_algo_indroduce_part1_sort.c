#include <stdio.h>
#include <math.h>
void printArray(int *A, int len) {
   for(int i = 0; i < len; i++) {
       printf("%d ", A[i]);
   }
}
void swap(int *A, int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}
int * insertionSort(int *A, int len) {
    for (int i = 1; i < len; i++) {
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v) {
            A[j + 1] = A [j];
            j--;
        }
        A[j + 1] = v;
    }
    return A;
}
void merge(int *A, int p, int m, int q) {
    int len1 = m - p + 1;
    int len2 = q - m;
    int L[len1];
    int R[len2];
    for(int i = p; i <= m; i++) {
        L[i - p] = A[i];
    }
    for(int i = m + 1; i <= q; i++) {
        R[i - m - 1] = A[i];
    }
    int k1 = 0;
    int k2 = 0;
    for(int i = p; i <= q; i++) {
        if(k1 >= len1) { 
            A[i] = R[k2++];
        }
        else if(k2 >= len2) { 
            A[i] = L[k1++];
        }
        else if(L[k1] <= R[k2]) {
            A[i] = L[k1++];
        } else {
            A[i] = R[k2++];
        }
    }
}
int * mergeSort(int *A, int p, int q) {
    if(p == q) {
        return A;
    }
    int m = p + floor((q - p) / 2);
    mergeSort(A, p, m);
    mergeSort(A, m + 1, q);
    merge(A, p, m, q);
    return A;
}
int parent(int i) {
    return ceil(i / 2) - 1;
}
int left(int i) {
    return i * 2 + 1;
}
int right(int i) {
    return 2 * i + 2;
}
void maxHeapify(int *A, int heapSize, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l < heapSize && A[l] > A[largest]) {
        largest = l;
    }
    if(r < heapSize && A[r] > A[largest]) {
        largest = r;
    }
    if(largest != i) {
        swap(A, i, largest);
        maxHeapify(A, heapSize, largest);
    }
}
void buildMaxHeap(int *A, int len){
    int m = floor(len / 2) - 1;
    for(int i = m; i >= 0; i--) {
        maxHeapify(A, len, i);
    }
}
int * heapSort(int *A, int len) {
    buildMaxHeap(A, len);
    for(int i = len - 1; i >= 1; i--) {
        swap(A, 0, i);
        maxHeapify(A, i, 0);
    }
    return A;
}
int heap_maximum(int *A) {
    return A[0];
}
int heap_extract_max(int *A, int len) {
    if(len < 1) {
        printf("heap under flow");
        return -1;
    }
    int max = A[0];
    A[0] = A[len - 1];
    len--;
    maxHeapify(A, len, 0);
    return max;
}
void heap_increase_key(int *A, int i, int key) {
    if(key < A[i]) {
        printf("new key is smaller");
        return;
    }
    A[i] = key;
    while(i > 1 && A[parent(i) < A[i]]) {
        swap(A, parent(i), i);
        i = parent(i);
    }
}
void max_heap_insert(int *A, int len, int key) {
    len++;
    A[len - 1] = -65535;
    heap_increase_key(A, len - 1, key);
}
int * quickSort(int *A, int p, int r) {
    if(p >= r) {
        return A;
    }
    int key = A[r];
    int j = p - 1;
    for(int i = p; i <= r - 1; i++) {
        if(A[i] <= key) {
            j ++;
            swap(A, i, j);
        }
    }
    swap(A, j + 1, r);
    int q = j + 1;
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
    return A;
}
int * countingSort(int *A, int *B,int len, int k) {
    int C[k];
    for(int i = 0; i < k; i++) {
        C[i] = 0;
    }
    for(int i = 0; i < len; i++) {
        C[A[i]] = C[A[i]] + 1;
    } 
    for (int i = 1; i < k; i++) {
        C[i] = C[i] + C[i - 1];
    } 
    for (int i = len - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }
    return B;
}
int main (void) {
   int A1[] = { 5, 4, 3, 8, 10, 2 };
    printArray(insertionSort(A1, 6), 6);
    printf("\n");
   int A2[] = { 5, 4, 3, 8, 10, 2 };
    printArray(mergeSort(A2, 0, 5), 6);
    printf("\n");
    int A3[] = { 5, 4, 3, 8, 10, 2 };
    printArray(heapSort(A3, 6), 6);
    printf("\n");
    int A4[] = { 5, 4, 3, 8, 10, 2 };
    printArray(quickSort(A4, 0, 5), 6);
    printf("\n");
    int A5[] = { 5, 4, 3, 8, 10, 2 };
    int B[6];
    printArray(countingSort(A5, B, 6, 11), 6);
}