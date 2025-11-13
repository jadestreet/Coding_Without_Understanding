#include <stdlib.h>
#include <stdio.h>
#define L 5
double sum(double* t,int size){
    double sum = 0;
    for(int i=0;i<size;i++)
        sum+=t[i];
    return sum;
}
double avg(double* t,int size){
    return sum(t,size)/size;
}
double max(double* t,int size){
    double m=t[0];
    for(int i=0;i<size;i++)
        if(t[i]>m)
            m=t[i];
    return m;
}
double min(double* t,int size){
    double m=t[0];
    for(int i=0;i<size;i++)
        if(t[i]<m)
            m=t[i];
    return m;
}
int isSorted(double* t,int size){
    int v =1;
    for(int i=1;i<size;i++)
        if(t[i]<t[i-1]){
            v=0;
        break;
        }
    return v;
}
void toIndex(double* t,int size){
    for(int i=0;i<size;i++)
        t[i]=i;
}
void sumArrays(double* t1,double* t2,int size){
    for(int i=0;i<size;i++)
        t1[i]=t1[i]+t2[i];
}
void printArray(double* t,int size){
    for(int i=0;i<size;i++)
        printf("%f,",t[i]);
}
int main(){
    double i[] = {3.0,2.0,3.0,4.0,5.5};
    double j[] = {3.0,2.0,3.0,4.0,5.5};
    printArray(i,L);
    printf("\n%f\n%f\n%f\n%f\n%d\n",sum(i,L),avg(i,L),max(i,L),min(i,L),isSorted(i,L));
    toIndex(j,L);
    printArray(j,L);
    printf("\n");
    sumArrays(i,j,L);
    printArray(i,L);
    printf("\n");
}