#include <stdio.h>
void HeapAdjust(int array[],int i,int nLength)
{
    int nChild;
    int nTemp;
    for(;2*i+1<nLength;i=nChild)
    {
        nChild=2*i+1;
        if(nChild < nLength - 1 && array[nChild+1] > array[nChild])
            ++nChild;
        if(array[i]<array[nChild])
        {
            nTemp=array[i];
            array[i]=array[nChild];
            array[nChild]=nTemp; 
        }
        else 
            break; 
    }
}
void HeapSort(int array[],int length)
{
    int i;
    for(i=length/2-1;i>=0;--i)
        HeapAdjust(array,i,length);
    for(i=length-1;i>0;--i)
    {
        array[i]=array[0]^array[i];
        array[0]=array[0]^array[i];
        array[i]=array[0]^array[i];
        HeapAdjust(array,0,i);
    }
}
int main()
{
    int i;
    int num[]={6, 1, 9, 5, 7, 3, 0, 4, 2, 8};
    HeapSort(num,sizeof(num)/sizeof(int));
    for(i=0;i<sizeof(num)/sizeof(int);i++)
    {
        printf("%d ",num[i]);
    }
    printf("\nok\n");
    return 0;
}