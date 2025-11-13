#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print(int *a,int n);
void swap(int *a, int *b);
int isSane(int *a, int n);
int main(int argc, char *argv[]){
    int n=atoi(argv[1]);
    int *a=(int*)malloc(sizeof(int)*n);
    int i,j,m,flag;
    srand(time(NULL));
    for(i=0;i<n;i++){
        a[i]=rand()%n;
    }
    time_t t=clock();
    t=clock()-t;
    printf("%f %d\n", (double)t/CLOCKS_PER_SEC,n);
    return isSane(a,n);
}
void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void print(int *a,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%3d ",a[i]);
    }
    printf("\n");
}
int isSane(int *a, int n){
    int flag=0,m;
    for(m=1;m<n;m++){
        if(a[m-1]>a[m]){
            flag=1;
        }
    }
    if(flag){
        fprintf(stderr,"ERROR! Data not sorted!!!\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}