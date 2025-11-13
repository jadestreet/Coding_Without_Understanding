#include <pthread.h>
#include <stdio.h>
#include <assert.h>
#ifndef PARAM1
#define PARAM1 9
#endif
#ifndef PARAM2
#define PARAM2 6
#endif
#define T PARAM1 
#define K PARAM2 
pthread_mutex_t m[K];
void *th(void *arg)
{
 unsigned id = (unsigned long) arg;
 int i = id;
 int j = 1;
 while (i < K && j < 4) {
   pthread_mutex_lock(&m[i]);
   i+=j;
   j++;
 }
 while (i > id) {
   j--;
   i-=j;
   pthread_mutex_unlock(&m[i]);
 }
 return NULL;
}
int main()
{
 pthread_t ids[T];
 for (int i = 0; i < K; i++)
 {
   pthread_mutex_init(&m[i], NULL);
 }
 for (int i = 0; i < T; i++)
 {
   pthread_create(&ids[i],  NULL, th, (void*) (long) i);
 }
 for (int i = 0; i < T; i++)
 {
   pthread_join(ids[i],NULL);
 }
 return 0;
}