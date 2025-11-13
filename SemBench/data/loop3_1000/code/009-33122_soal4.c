#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void *faktorial(void *arg);
int main(int argc, char *argv[])
{
  pthread_t tid[argc];
	for(int i=1; i<argc;i++)
	{
		int num = atoi(argv[i]);
		pthread_create(&tid[i],NULL,&faktorial,(void *)num);
  }
  for (int i = 1; i<argc; i++)
  {
    pthread_join(tid[i],NULL);
  }
return 0;
}
void *faktorial(void *arg)
{
  int awal = (int)arg;
  int top=(int) arg;
  long long result=1;
	while(top>0)
  {
	 result*=top;
   top--;
  }
  printf("Hasil %d! = %d\n", awal, result);
}