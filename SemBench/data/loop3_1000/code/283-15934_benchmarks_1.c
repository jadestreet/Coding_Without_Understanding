#define NUM 9
#define SUM (3*NUM)
int x = 0;
int y = 0;
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>
void * t1()
{
  x = 1;
  while ( x != 1) { }
  for (int i =0; i<NUM; i++) {
    y = y+2;
    if (y > NUM) {
      y = 0;
    }
  }
  x = 0;
  x = 1;
  while ( x != 1) { }
  for (int i =0; i<NUM; i++) {
    y = y-2;
    if (y < 0) {
      y = 2*NUM;
    }
  }
  x = 0;
  pthread_exit(NULL);
}
void * t2()
{
  x = 0;
  while (x != 0) { }
  for (int i =0; i<NUM; i++) {
    y = y+1;
  }
  x = 1;
  x = 0;
  while (x != 0) { }
  for (int i =0; i<NUM; i++) {
    y = y-1;
  }
  x = 1;
}
int main()
{
  pthread_t id1, id2;
  pthread_create(&id1, NULL, t1, NULL);
  pthread_create(&id2, NULL, t2, NULL);
  pthread_join(id1, (void *)0);
  pthread_join(id2, (void *)0);
  assert(y > 0);
  return 0;
}