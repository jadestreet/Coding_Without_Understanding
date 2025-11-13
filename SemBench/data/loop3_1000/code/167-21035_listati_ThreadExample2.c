#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	double *a;
	double *b;
	double sum;
	int veclen;
} DOTDATA;
#define NUMTHREADS 4
#define VECLEN 100
DOTDATA dotstr;
pthread_t callThd[NUMTHREADS];
pthread_mutex_t mutexsum;
void *dotprod(void *arg) {
	int i, start, end, offset;
	double mysum;
	offset = (int) arg;
	start = offset * dotstr.veclen;
	end = start + dotstr.veclen;
	mysum = 0;
	for (i = start; i < end; i++) {
		mysum += (dotstr.a[i] * dotstr.b[i]);
	}
	pthread_mutex_lock (&mutexsum);
	dotstr.sum += mysum;
	pthread_mutex_unlock (&mutexsum);
	pthread_exit((void *)0);
}
int main (int argc, char *argv[]) {
	int i;
	int status;
	dotstr.a = (double*) malloc (NUMTHREADS*VECLEN*sizeof(double));
	dotstr.b = (double*) malloc (NUMTHREADS*VECLEN*sizeof(double));
	for (i=0; i<VECLEN*NUMTHREADS; i++) {
		dotstr.a[i]=1;
		dotstr.b[i]=1;
	}
	dotstr.veclen = VECLEN;
	dotstr.sum=0;
	pthread_mutex_init(&mutexsum, NULL);
	for(i=0;i<NUMTHREADS;i++) {
		pthread_create(&callThd[i], NULL, dotprod, (void *)i);
	}
	for(i=0;i<NUMTHREADS;i++) {
		pthread_join( callThd[i], (void **)&status);
	}
	printf ("Sum = %f \n", dotstr.sum);
	free (dotstr.a);
	free (dotstr.b);
	pthread_mutex_destroy(&mutexsum);
	pthread_exit(NULL);	
}