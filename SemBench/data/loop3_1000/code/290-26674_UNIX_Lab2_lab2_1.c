#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
typedef struct Vector {
	pthread_mutex_t mutex;
	int* vet;
} Vector;
Vector V;
void merge(int *vet, int left, int middle, int right);
void* threadedMergeSort(int* args);
int main(int argc, char** argv) {
  int i, n;
  int args[2];
  if (argc != 2) {
    fprintf (stderr, "Wrong number of arguments. Syntax: %s dimension\n", argv[0]);
    return -1;
  }
  n = atoi(argv[1]);
  V.vet = (int*)malloc(n*sizeof(int));
  pthread_mutex_init(&V.mutex, NULL);
  srand(n);
  fprintf(stdout, "Array before sorting: ");
  pthread_mutex_lock(&V.mutex);
  for(i = 0; i < n; i++) {
    V.vet[i] = rand() % 100;
		fprintf(stdout, "%d ", V.vet[i]);
  }
	pthread_mutex_unlock(&V.mutex);
	fprintf(stdout, "\n");
	args[0] = 0; 
	args[1] = n-1; 
  threadedMergeSort(args);
  fprintf(stdout, "Array after sorting: ");
  pthread_mutex_lock(&V.mutex);
  for(i = 0; i < n; i++) {
		fprintf(stdout, "%d ", V.vet[i]);
	}
	pthread_mutex_unlock(&V.mutex);
	fprintf(stdout, "\n");
  return 0;
}
void* threadedMergeSort(int* args) {
	int* arg = args;
	int left, middle, right;
	int argsA[2], argsB[2];
	pthread_t threadA, threadB;
	void* retValue;
	left = arg[0];
	right = arg[1];
	if (left < right) {
		middle = left + (right - left)/2;  
		argsA[0] = left;
		argsA[1] = middle;
		pthread_create(&threadA, NULL, (void*)threadedMergeSort, (void*)argsA);
		argsB[0] = middle + 1;
		argsB[1] = right;
		pthread_create(&threadB, NULL, (void*)threadedMergeSort, (void*)argsB);
		pthread_join(threadA, &retValue);
		pthread_join(threadB, &retValue);
		pthread_mutex_lock(&V.mutex);
		merge(V.vet, left, middle, right);
		pthread_mutex_unlock(&V.mutex);
	}
  return (void*)0;
}
void merge(int *vet, int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int L[n1], R[n2];  
    for (i = 0; i <= n1; i++) {  
    	L[i] = vet[left + i];
    }
    for (j = 0; j <= n2; j++) {
      R[j] = vet[middle + 1 + j];
    }
    i = 0; 
    j = 0; 
    k = left; 
    while (i < n1 && j < n2)  {
      if (L[i] <= R[j]) {
        vet[k++] = L[i++];
      } else {
        vet[k++] = R[j++];
      }
    }
    while (i < n1) {
      vet[k++] = L[i++];
    }
    while (j < n2) {
      vet[k++] = R[j++];
    }
    return;
}