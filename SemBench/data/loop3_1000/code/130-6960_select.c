#include <stdio.h>
#define SWAP(a, b)\
do{\
    a = a^b;\
    b = a^b;\
    a = a^b;\
}while(0)
#define LENGTH 8
static int data[LENGTH] = {95, 45, 15, 78, 84, 51, 24, 12};
static void printData(int *pData, int count)
{
    int i;
    for (i=0; i<count; i++)
    {
        printf("data[%d] = %d\n", i, pData[i]);
    }
}
static void sortData(int *pData, int count)
{
    int i, j, minIdx;
    for (i=0; i<count-1; i++)
    {
        minIdx = i;
        for (j=i+1; j<count; j++)
        {
            if ( pData[j] < pData[minIdx] )
            {
                minIdx = j;
            }
        }
        if ( minIdx != i )
        {    
            SWAP( pData[minIdx], pData[i] );
        }
    }
}
int main(void)
{
    sortData(data, LENGTH);
    printData(data, LENGTH);
    return 0;
}