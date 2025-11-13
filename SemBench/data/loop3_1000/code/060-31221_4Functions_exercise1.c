#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ARRAY 100
int  myArray[100];
int myMax;
int max (int first, int second) {
    int max;
   if (first > second)
   {
       max = first;
   }
   else
   {
       max = second;
   }
 return max;   
}
int sum(int localArray[])
{
    int mySum;
    for (int ii = 0; ii < 100; ii++)
    {
     mySum = mySum + localArray[ii];   
    }
    return mySum;
}
int main() {
    int mySum;
    srand(time(NULL));
    for (int ii = 0; ii < 100 ; ii++) 
    {
        myArray[ii] = (rand() % 100) + 1;
    }
    printf("Completed initializing array\n");
    for (int ii = 0; ii < 100; ii++)
    {
     myMax  = max(myArray[ii],myMax );
    }
    printf("This is the max: %d", myMax);    
    for (int ii = 0; ii < 100; ii++)
    {
        mySum = mySum + myArray[ii];
    }
    printf("The sum is: %d", mySum);
    printf("new sum %d", sum(&myArray));
 return 0;   
}