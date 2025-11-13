#include "syscall.h"
#define SORTSIZE	256
#define SORTSHIFT	0
int array[SORTSIZE<<SORTSHIFT];
#define	A(i)	(array[(i)<<SORTSHIFT])
void swap(int* x, int* y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
int
main()
{
  int i, j;
  for (i=0; i<SORTSIZE; i++)
    A(i) = (SORTSIZE-1)-i;
  for (i=0; i<SORTSIZE-1; i++) {
    for (j=i; j<SORTSIZE; j++) {
      if (A(i) > A(j))
	swap(&A(i), &A(j));
    }
  }
  for (i=0; i<SORTSIZE; i++) {
    if (A(i) != i)
      return 1;
  }
  return 0;
}