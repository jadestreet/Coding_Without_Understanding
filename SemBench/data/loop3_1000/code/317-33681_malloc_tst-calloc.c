#include <errno.h>
#include <error.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#define N 50000
static void
fixed_test (int size)
{
  char *ptrs[N];
  int i;
  for (i = 0; i < N; ++i)
    {
      int j;
      ptrs[i] = (char *) calloc (1, size);
      if (ptrs[i] == NULL)
	break;
      for (j = 0; j < size; ++j)
	{
	  if (ptrs[i][j] != '\0')
	    error (EXIT_FAILURE, 0,
		   "byte not cleared (size %d, element %d, byte %d)",
		   size, i, j);
	  ptrs[i][j] = '\xff';
	}
    }
  while (i-- > 0)
    free (ptrs[i]);
}
static void
random_test (void)
{
  char *ptrs[N];
  int i;
  for (i = 0; i < N; ++i)
    {
      int j;
      int n = 1 + random () % 10;
      int elem = 1 + random () % 100;
      int size = n * elem;
      ptrs[i] = (char *) calloc (n, elem);
      if (ptrs[i] == NULL)
	break;
      for (j = 0; j < size; ++j)
	{
	  if (ptrs[i][j] != '\0')
	    error (EXIT_FAILURE, 0,
		   "byte not cleared (size %d, element %d, byte %d)",
		   size, i, j);
	  ptrs[i][j] = '\xff';
	}
    }
  while (i-- > 0)
    free (ptrs[i]);
}
int
main (void)
{
  fixed_test (15);
  fixed_test (5);
  fixed_test (17);
  fixed_test (6);
  fixed_test (31);
  fixed_test (96);
  random_test ();
  return 0;
}