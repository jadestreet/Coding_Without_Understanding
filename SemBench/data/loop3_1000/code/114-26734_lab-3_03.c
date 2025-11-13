#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double randomDouble(int point,int max){
    return (double)(rand()%(point*max)/(double)point);
}
void seedArray(double d[],int size,int point,int max){
    for(int i=0;i<size;i++)
        d[i]=randomDouble(point,max);
}
void printArray(double d[],int size){
    for(int i=0;i<size;i++)
        printf("%f\n",d[i]);
}
double sumArray(double d[],int size){
    double sum=0;
    for(int i=0;i<size;i++)
        sum+=d[i];
    return sum;
}
double roundArray(double d[],int size){
    return sumArray(d,size)/(double)size;
}
int main(){
    srand( time(NULL));
    double d[10];
    seedArray(d,10,1000,1000);
    printArray(d,10);
    printf("srednia = %f\n",roundArray(d,10));
}