#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define THREAD_NUMBER 4
#define NUMBER_OF_AREA 10
void* f1(void*);
void* f2(void*);
void* f3(void*);
void* f4(void*);
struct thread_data{
  size_t last_thread_on_that_zone[NUMBER_OF_AREA];
  int picture[NUMBER_OF_AREA];
  pthread_mutex_t* mutex_data;
  pthread_cond_t* vcond_data;
};
void init_thread_data(struct thread_data* p){
  for(size_t i=0;i<THREAD_NUMBER;++i){
    p->last_thread_on_that_zone[i]=0;
  }
  p->mutex_data=malloc(sizeof(pthread_mutex_t)*NUMBER_OF_AREA);
  p->vcond_data=malloc(sizeof(pthread_cond_t)*NUMBER_OF_AREA);
  for(size_t i=0;i<NUMBER_OF_AREA;++i){
    pthread_mutex_init(&(p->mutex_data[i]),NULL);
    pthread_cond_init(&(p->vcond_data[i]),NULL);
  }
}
void destroy_thread_data(struct thread_data* p){
  free(p->mutex_data);
  free(p->vcond_data);
}
void* f1(void* p){
  struct thread_data* param=(struct thread_data*)p;
  size_t my_function_number=1;
  for(size_t i=0;i<NUMBER_OF_AREA;++i){
    pthread_mutex_lock(&(param->mutex_data[i]));
    while(param->last_thread_on_that_zone[i]!=my_function_number){
      pthread_cond_wait(&(param->vcond_data[i]),&(param->mutex_data[i]));
    }
    printf("thread number %zu proudly working on area #%zu\n",my_function_number,i);
    sleep(.5);
    param->last_thread_on_that_zone[i]++;
    pthread_cond_broadcast(&(param->vcond_data[i]));
    pthread_mutex_unlock(&(param->mutex_data[i]));
  }
  pthread_exit(NULL);
}
int main(){
  struct thread_data* param;
  param=malloc(sizeof(struct thread_data));
  init_thread_data(param);
  pthread_t idt[THREAD_NUMBER];
  pthread_create(&idt[0],NULL,f1,(void*)param);
  pthread_create(&idt[1],NULL,f2,(void*)param);
  pthread_create(&idt[2],NULL,f3,(void*)param);
  pthread_create(&idt[3],NULL,f4,(void*)param);
  for(size_t i=0;i<NUMBER_OF_AREA;++i){
    pthread_mutex_lock(&(param->mutex_data[i]));
    sleep(.5);
    printf("main thread proudly working on area #%zu\n",i);
    param->last_thread_on_that_zone[i]++;
    pthread_cond_broadcast(&(param->vcond_data[i]));
    pthread_mutex_unlock(&(param->mutex_data[i]));
  }
  printf("main is done and waiting for his slow coworkers is finally done!\n");
  for(size_t i=0;i<THREAD_NUMBER;++i){
    pthread_join(idt[i],NULL);
    printf("thread #%zu is finally done!\n",i+1);
  }
  destroy_thread_data(param);
  free(param);
  return 0;
}
void* f2(void* p){
  struct thread_data* param=(struct thread_data*)p;
  size_t my_function_number=2;
  for(size_t i=0;i<NUMBER_OF_AREA;++i){
    pthread_mutex_lock(&(param->mutex_data[i]));
    while(param->last_thread_on_that_zone[i]!=my_function_number){
      pthread_cond_wait(&(param->vcond_data[i]),&(param->mutex_data[i]));
    }
    printf("thread number %zu proudly working on area #%zu\n",my_function_number,i);
    sleep(.5);
    param->last_thread_on_that_zone[i]++;
    pthread_cond_broadcast(&(param->vcond_data[i]));
    pthread_mutex_unlock(&(param->mutex_data[i]));
  }
  pthread_exit(NULL);
}
void* f3(void* p){
  struct thread_data* param=(struct thread_data*)p;
  size_t my_function_number=3;
  for(size_t i=0;i<NUMBER_OF_AREA;++i){
    pthread_mutex_lock(&(param->mutex_data[i]));
    while(param->last_thread_on_that_zone[i]!=my_function_number){
      pthread_cond_wait(&(param->vcond_data[i]),&(param->mutex_data[i]));
    }
    printf("thread number %zu proudly working on area #%zu\n",my_function_number,i);
    sleep(.5);
    param->last_thread_on_that_zone[i]++;
    pthread_cond_broadcast(&(param->vcond_data[i]));
    pthread_mutex_unlock(&(param->mutex_data[i]));
  }
  pthread_exit(NULL);
}
void* f4(void* p){
  struct thread_data* param=(struct thread_data*)p;
  size_t my_function_number=4;
  for(size_t i=0;i<NUMBER_OF_AREA;++i){
    pthread_mutex_lock(&(param->mutex_data[i]));
    while(param->last_thread_on_that_zone[i]!=my_function_number){
      pthread_cond_wait(&(param->vcond_data[i]),&(param->mutex_data[i]));
    }
    printf("thread number %zu proudly working on area #%zu\n",my_function_number,i);
    sleep(.5);
    param->last_thread_on_that_zone[i]++;
    pthread_cond_broadcast(&(param->vcond_data[i]));
    pthread_mutex_unlock(&(param->mutex_data[i]));
  }
  pthread_exit(NULL);
}