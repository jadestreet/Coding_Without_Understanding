#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <semaphore.h>
typedef struct
{
  pthread_mutex_t mutex1;
  pthread_mutex_t mutex2;
  sem_t sem1;
  sem_t sem2;
  unsigned total;
  unsigned arrived;
  sem_t xxx;
} gomp_barrier_t;
typedef long bool;
void
gomp_barrier_init (gomp_barrier_t *bar, unsigned count)
{
  pthread_mutex_init (&bar->mutex1, NULL);
  pthread_mutex_init (&bar->mutex2, NULL);
  sem_init (&bar->sem1, 0, 0);
  sem_init (&bar->sem2, 0, 0);
  sem_init (&bar->xxx,  0, 0);
  bar->total = count;
  bar->arrived = 0;
}
void
gomp_barrier_destroy (gomp_barrier_t *bar)
{
  pthread_mutex_lock (&bar->mutex1);
  pthread_mutex_unlock (&bar->mutex1);
  pthread_mutex_destroy (&bar->mutex1);
  pthread_mutex_destroy (&bar->mutex2);
  sem_destroy (&bar->sem1);
  sem_destroy (&bar->sem2);
  sem_destroy(&bar->xxx);
}
void
gomp_barrier_reinit (gomp_barrier_t *bar, unsigned count)
{
  pthread_mutex_lock (&bar->mutex1);
  bar->total = count;
  pthread_mutex_unlock (&bar->mutex1);
}
void
gomp_barrier_wait (gomp_barrier_t *bar)
{
  unsigned int n;
  pthread_mutex_lock (&bar->mutex1);
  ++bar->arrived;
  if (bar->arrived == bar->total)
    {
      bar->arrived--;
      n = bar->arrived;
      if (n > 0) 
        {
          { unsigned int i;
            for (i = 0; i < n; i++)
              sem_wait(&bar->xxx); 
          }
          do
            sem_post (&bar->sem1); 
          while (--n != 0);
          sem_wait (&bar->sem2); 
        }
      pthread_mutex_unlock (&bar->mutex1);
    }
  else
    {
      pthread_mutex_unlock (&bar->mutex1);
      sem_post(&bar->xxx);
      sem_wait (&bar->sem1); 
      pthread_mutex_lock (&bar->mutex2);
      n = --bar->arrived; 
      pthread_mutex_unlock (&bar->mutex2);
      if (n == 0)
        sem_post (&bar->sem2); 
    }
}
static gomp_barrier_t bar;
static volatile long unprotected = 0;
void* child ( void* argV )
{
   long myid = (long)argV;
   gomp_barrier_wait( &bar );
   if (myid == 4) {
      unprotected = 99;
   }
   gomp_barrier_wait( &bar );
   if (myid == 3) {
      unprotected = 88;
   }
   gomp_barrier_wait( &bar );
   return NULL;
}
int main (int argc, char *argv[])
{
   long i; int res;
   pthread_t thr[4];
   fprintf(stderr, "starting\n");
   gomp_barrier_init( &bar, 4 );
   for (i = 0; i < 4; i++) {
      res = pthread_create( &thr[i], NULL, child, (void*)(i+2) );
      assert(!res);
   }
   for (i = 0; i < 4; i++) {
      res = pthread_join( thr[i], NULL );
      assert(!res);
   }
   gomp_barrier_destroy( &bar );
   fprintf(stderr, "done, result is %ld, should be 88\n", unprotected);
   return 0;
}