#include <stdio.h>
#define SIZE 10
void bucketSort( int[], int );
void bucketSort( int toSort[], int arrLen )
{
    if(arrLen <=1)
        return;
    int bucket[SIZE][arrLen];
    int indexes[SIZE] = { 0 };
    int max = toSort[0];
    int i, j, row;
    int modBy = 10;
    int divBy = 1;
    for(i=1; i<arrLen; i++)
        if(toSort[i]>max) {
            max = toSort[i];
        }
    while(divBy < max)
    {
        for(i=0; i<arrLen; i++) {
            indexes[i] = 0;
        }
        for(i=0; i<arrLen; i++)
        {
            row = (toSort[i]/divBy)%modBy;
            bucket[row][indexes[row]]=toSort[i];
            ++indexes[row];
        }
        row = 0;
        for(i=0; i<arrLen; i++)
        {
            for(j=0; j<indexes[i]; j++)
                toSort[row++]=bucket[i][j];
        }
        divBy*=10;
    }
}
int main()
{
    int i;
    int toSort[SIZE] = { 122, 642, 4, 322, 113, 9, 575, 44, 176, 8 };
    for(i=0; i<SIZE; i++)
        printf("%d ",toSort[i]);
    printf("\n");
    bucketSort( toSort , SIZE  );
    for(i=0; i<SIZE; i++)
        printf("%d ",toSort[i]);
    printf("\n");
    return 0;
}