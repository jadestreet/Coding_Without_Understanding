#include <stdio.h>
static int count = 0;
static void
foo (void)
{
  int i, j;
  for (j = 0; j < 2; j++)
    {
      for (i = 0; i < 2; i++) 
        count += 1; 
      count += 2; 
    }
}
int
main (void)
{
  foo ();
  printf ("The value of count is %d\n", count);  
  while(1); 
}