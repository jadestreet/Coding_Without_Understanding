#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#ifndef MAX
#define MAX 1000000
#endif
void printArray(int *a, int size)
{
    for(int i=0;i<size;i++) printf("%d ",a[i]);
}
void countingSort(int *a,int size)
{
    int output[size];
    memset(output,0,size);
    int count[MAX];
    for(int i=0;i<MAX;i++) count[i] = 0;
    for(int i=0;i<size;i++)
    {
        count[a[i]]++;
    }
    for(int i=1;i<MAX;i++)
        count[i] += count[i-1];
    for(int i=size-1;i>=0;i--)
    {
        output[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }
    printArray(output,size);
    printf("\n");
}
void square(int *a, int size)
{
    for(int i=0;i<size;i++) a[i] = a[i]*a[i];
}
int main(void)
{
    int a[] = {-5,-4,-3,-2};
    int size = sizeof(a)/sizeof(*a);
    int b[] = {-2,-1,0,1,2};
    int n = sizeof(b)/sizeof(*b);
    square(a,size);
    square(b,n);
    countingSort(a,size);
    countingSort(b,n);
    return 0;
}