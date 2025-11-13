#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#define MATRIX_SIZE 16
#define NUM_THREADS 8
#define RAN 10
void fillMatrix(double ** m);
void sliceMatrix(double*** threadData, double ** data);
typedef struct sThreadData{
	double ** a;
	double ** b;
	double ** c;
} sThreadData;
int main(void) {
	srand(time(NULL));
	double **a, **b, **c;
	double *aBlock, *bBlock, *cBlock; 
	a = (double **)malloc(MATRIX_SIZE*sizeof(double *));
	b = (double **)malloc(MATRIX_SIZE*sizeof(double *));
	c = (double **)malloc(MATRIX_SIZE*sizeof(double *));
	aBlock = (double *)malloc(MATRIX_SIZE*MATRIX_SIZE*sizeof(double));
	bBlock = (double *)malloc(MATRIX_SIZE*MATRIX_SIZE*sizeof(double));
	cBlock = (double *)malloc(MATRIX_SIZE*MATRIX_SIZE*sizeof(double));
	for(int i = 0; i < MATRIX_SIZE; i++){
		a[i] = aBlock+i*MATRIX_SIZE;
	}
	for(int i = 0; i < MATRIX_SIZE; i++){
		b[i] = bBlock+i*MATRIX_SIZE;
	}
	for(int i = 0; i < MATRIX_SIZE; i++){
		c[i] = cBlock+i*MATRIX_SIZE;
	}
	fillMatrix(a);
	fillMatrix(b);
	pthread_t *threads;
	threads = (pthread_t*)malloc(sizeof(pthread_t)*NUM_THREADS);
	double *** aThreadData = (double ***)malloc(NUM_THREADS*sizeof(double **));
	double *** bThreadData = (double ***)malloc(NUM_THREADS*sizeof(double **));
	double *** cThreadData = (double ***)malloc(NUM_THREADS*sizeof(double **));
	for(int i = 0; i < NUM_THREADS; i++){
		aThreadData[i] = (double **)malloc((MATRIX_SIZE/NUM_THREADS)*sizeof(double*));
	}
	for(int i = 0; i < NUM_THREADS; i++){
		bThreadData[i] = (double **)malloc((MATRIX_SIZE/NUM_THREADS)*sizeof(double*));
	}
	for(int i = 0; i < NUM_THREADS; i++){
		cThreadData[i] = (double **)malloc((MATRIX_SIZE/NUM_THREADS)*sizeof(double*));
	}
	sliceMatrix(aThreadData, a);
	sliceMatrix(bThreadData, b);
	sliceMatrix(cThreadData, c);
	sThreadData *tData = (sThreadData*)malloc(NUM_THREADS*sizeof(sThreadData));
	for(int i = 0; i < NUM_THREADS; i++){
		tData[i].a = aThreadData[i];
		tData[i].b = bThreadData[i];
		tData[i].c = cThreadData[i];
	}
	printf("Data stored: \n");
	for(int i = 0; i < MATRIX_SIZE; i++){
		for(int j = 0; j < MATRIX_SIZE; j++){
			printf("%.2f ",a[i][j]);			
		}
		printf("\n");
	}
	printf("\nData stored in pthread: \n");
	for(int l = 0; l < NUM_THREADS; l++){
		printf("\nptr: %d\n",l);
		for(int i = 0; i < MATRIX_SIZE/NUM_THREADS; i++){
			for(int j = 0; j < MATRIX_SIZE; j++){
				printf("%.2f ",tData[l].a[i][j]);
			}
			printf("\n");
		}
	}
	for(int i = 0; i < NUM_THREADS; i++){
	}
	free(a);
	free(b);
	free(c);
	free(aBlock);
	free(bBlock);
	free(cBlock);
	free(threads);
	for(int i = 0; i < NUM_THREADS; i++){
		free(aThreadData[i]);
	}
	for(int i = 0; i < NUM_THREADS; i++){
		free(bThreadData[i]);
	}
	for(int i = 0; i < NUM_THREADS; i++){
		free(cThreadData[i]);
	}
	free(aThreadData);
	free(bThreadData);
	free(cThreadData);
	free(tData);
	return 0;
}
void fillMatrix(double **m){
	for(int i = 0; i < MATRIX_SIZE; i++){
		for(int j = 0; j < MATRIX_SIZE; j++){
			m[i][j] = (1 + rand() % RAN);
		}
	}
}
void sliceMatrix(double*** threadData, double ** data){
	int k = 0;
	for(int i = 0; i < NUM_THREADS; i++){
		for(int j = 0; j < MATRIX_SIZE/NUM_THREADS; j++){
			threadData[i][j] = data[k++];
		}
	}
}