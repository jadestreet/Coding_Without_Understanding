#define NUM 5
int x = 0;
int y = 0;
int z = 0;
#include <pthread.h>
#include <assert.h>
void * t1()
{
  for (int i =0; i<NUM; i++) {
    y = y+1;
  }
  x = 1;
  pthread_exit(NULL);
}
void * t2()
{
  for (int i =0; i<NUM; i++) {
    y = y -1 ;
  }
  while (x != 1) { }
  for (int i =0; i<NUM; i++) {
    y = y - 2;
    if (y < 0) {
      y = NUM;
    }
  }
  for (int i =0; i<NUM; i++) {
    y = y * 2;
    if (y < 0) {
      y = NUM;
    }
  }
}
int main()
{
  pthread_t id1, id2;
  pthread_create(&id1, NULL, t1, NULL);
  pthread_create(&id2, NULL, t2, NULL);
  pthread_join(id1, (void *)0);
  pthread_join(id2, (void *)0);
  assert(y != NUM);
  return 0;
}