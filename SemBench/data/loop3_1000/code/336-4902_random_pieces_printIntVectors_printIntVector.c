#include <stdlib.h>
#include <stdio.h>
void vprint (int *v, const size_t size);
void vprintl (int *v, const size_t size);
int main (int argc, char **argv)
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
  for (int i = 0; i <= 10; i++) {
    vprint (a, i);
    printf ("\n");
  }
  printf ("\n");
  for (int i = 0; i <= 10; i++) vprintl (a, i);
  return (EXIT_SUCCESS);
}
void vprint (int *v, const size_t size) 
{
  printf ("[");
  if (size != 0) {
    for (int i = 0; i < size; i++)
      printf ("%i%s", v[ i ], (i != size -1) ? ", " : "]" );
  } else {
    printf ("]");
  }
}
void vprintl (int *v, const size_t size)
{
  printf ("[");
  if (size != 0) {
    for (int i = 0; i < size; i++)
      printf ("%i%s", v[ i ], (i != size -1) ? ", " : "]" );
  } else {
    printf ("]");
  }
  printf("\n");
}