#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#define LENGTH 50000000
int numThreads;
int  array[LENGTH];
int count = 0;
pthread_t * threadArray;
int * threadNum;
int debug = 0;
sem_t lockCount;
void * count3_thread(void * id)
{
    int * tID = (int *) id;
    int lengthPerThread = LENGTH/numThreads;
    int start = *tID * lengthPerThread;
    int i;
    if(debug)
        printf("starting work thread with ID %d\n", *tID);
    int end = start+lengthPerThread;
    if (*tID == numThreads-1)
        end = LENGTH;
    for(i = start; i<end; i++)
    {
        if(array[i]==3)
        {
            sem_wait(&lockCount);
            count++;
            sem_post(&lockCount);
        }
    }
    return NULL;
}
void count3()
{
    int j;
    for(j = 0; j < numThreads; j++)
    {
        if(debug)
            printf("Creating thread with ID %d\n", j);
        pthread_create(&threadArray[j], NULL, count3_thread, &threadNum[j]);
    }
    for(j = 0; j < numThreads; j++)
    {
        if(debug)
            printf("Joining on thread %d\n", j);
        pthread_join(threadArray[j], NULL);
    }
    return;
}
int main(int argc, char const *argv[])
{
    int i;
    numThreads = 1;
    for(i=0; i < argc; i++){
        char * test = strdup(argv[i]);
        char * v1 = "-v";
        char * v2 = "--verbose";
        char * v3 = "-t";
        char * v4 = "--threads";
        if(strcmp(test,v1)==0 || strcmp(test,v2)==0)
            debug=1;
        if(strcmp(test,v3)==0 || strcmp(test,v4)==0)
        {
            numThreads = atoi(argv[++i]);
        }
    }
    threadArray = (pthread_t *) malloc(numThreads * sizeof(pthread_t));
    threadNum = (int *) malloc(numThreads * sizeof(int));
    for(i = 0; i<numThreads; i++)
        threadNum[i] = i;
    int real_count = 0;
    for (i = 0; i<LENGTH; i++)
    {
        array[i] = (rand() % 3)+1;
        if (array[i] == 3)
            real_count++;
    }
    printf("\nNumber of threads %d\n",numThreads );
    printf("Real count: %d\n", real_count);
    sem_init(&lockCount, 0, 1);
    struct timespec start_time;
    struct timespec end_time;
    double diff;
    if(numThreads==0)
    {
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        for (i = 0; i<LENGTH; i++)
            if(array[i] == 3)
                count++;
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        diff = ((double) end_time.tv_sec + 1.0e-9*end_time.tv_nsec)
             - ((double) start_time.tv_sec + 1.0e-9*start_time.tv_nsec);
        printf("Serial Count: %d\n",count );
        printf("Serial Time(sec): %f\n", diff );
    }
    else {
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        count3();
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        diff = ((double) end_time.tv_sec + 1.0e-9*end_time.tv_nsec)
             - ((double) start_time.tv_sec + 1.0e-9*start_time.tv_nsec);
        printf("Threaded Count: %d\n",count);
        printf("Threaded Time(sec): %f\n", diff);
    }
    sem_close(&lockCount);
    FILE * fp;
    fp = fopen("data/count3semaphor.csv","a");
    fprintf(fp, "%d, %f\n",numThreads, diff);
    fclose(fp);
    return 0;
}