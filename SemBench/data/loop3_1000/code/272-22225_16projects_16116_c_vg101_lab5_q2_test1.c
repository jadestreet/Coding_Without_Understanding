#include "stdio.h"
#include "stdlib.h"
#include "math.h"
 void five(void**);
int main() {
 int a[5][5];
    void **op=(void **)a;
    five(op);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf("%11.2d|-%p-|  ",*(*((int **)op+i)+j),(*((int **)op+i)+j));
        }
        printf("\n" );
    }
}
void five(void **op){
    int **opp=(int **)op;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            *(*(opp+3)+j)=8888;
        }
    }
}