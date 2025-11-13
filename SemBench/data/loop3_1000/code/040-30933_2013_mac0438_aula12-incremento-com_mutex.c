#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <semaphore.h>
#define NUM_THREADS     50
int a;
sem_t mutex;
void *TaskCode(void *argument)
{
   int tid;
   int i;
   tid = *((int *) argument);
      sem_wait(&mutex); 
   for (i=0;i<100000;i++) {
      a++;
   }
      sem_post(&mutex); 
   fprintf(stderr,"[Olah, eu sou a thread %d e a=%d!]\n", tid,a);
   return NULL;
}
int main(void)
{
   pthread_t threads[NUM_THREADS];
   int thread_args[NUM_THREADS];
   int rc,i;
   a=0;
   sem_unlink("mutex");
   sem_init(&mutex,0,1);
   for (i=0; i<NUM_THREADS; ++i) {
      thread_args[i] = i;
      rc = pthread_create(&threads[i], NULL, TaskCode, (void *) &thread_args[i]);
      assert(0==rc); 
   }
   for (i=0; i<NUM_THREADS; ++i) {
      rc = pthread_join(threads[i], NULL);
      assert(0 == rc);
   }
   sem_destroy(&mutex); 
   fprintf(stderr,"[Valor final de a=%d]\n",a);
   return(0);
}