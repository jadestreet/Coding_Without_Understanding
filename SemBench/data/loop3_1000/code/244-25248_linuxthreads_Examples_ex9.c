#include <errno.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 10
#define NUM_ITERS   500
static void *thread (void *)  __attribute__ ((__noreturn__));
static pthread_barrier_t barrier;
int
main (void)
{
  pthread_t thread_list[NUM_THREADS];
  int i;
  if (pthread_barrier_init (&barrier, NULL, NUM_THREADS + 1) != 0)
    error (EXIT_FAILURE, 0, "cannot initialize barrier");
  for (i = 0; i < NUM_THREADS; i++)
    {
      if (pthread_create (&thread_list[i], NULL, thread, NULL) != 0)
	error (EXIT_FAILURE, 0, "cannot create thread");
    }
  (void) thread (NULL);
  for (i = 0; i < NUM_THREADS; i++)
    {
      pthread_join(thread_list[i], NULL);
    }
  return 0;
}
static void *
thread (void *arg)
{
  int i;
  pthread_t self = pthread_self ();
  static pthread_t last_serial_thread;
  static int linecount; 
  for (i = 0; i < NUM_ITERS; i++)
    {
      switch (pthread_barrier_wait (&barrier))
	{
	case 0:
	  flockfile (stdout);
	  printf ("%04d: non-serial thread %lu\n", ++linecount,
		  (unsigned long) self);
	  funlockfile (stdout);
	  break;
	case PTHREAD_BARRIER_SERIAL_THREAD:
	  flockfile (stdout);
	  printf ("%04d: serial thread %lu\n", ++linecount,
		  (unsigned long) self);
	  funlockfile (stdout);
	  last_serial_thread = self;
	  break;
	default:
	  error (EXIT_FAILURE, 0, "unexpected return value from barrier wait");
	}
    }
  if (pthread_equal (self, last_serial_thread))
  {
    flockfile (stdout);
    printf ("%04d: last serial thread %lu terminating process\n",
	    ++linecount, (unsigned long) self);
    funlockfile (stdout);
  }
  pthread_exit(NULL);
}