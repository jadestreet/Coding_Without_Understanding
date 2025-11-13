#include <stdlib.h>
#include <stdio.h>
int heads()
{
  return rand() < RAND_MAX / 2;
}
int main (int argc, char *argv[])
{
  int i, j, c;
  int N = atoi(argv[1]);
  int M = atoi(argv[2]);
  int *f = malloc ((N+1) * sizeof (int));
  for (j = 0; j <= N; j++)
    f[j] = 0;
  for (i = 0; i < M; i++, f[c]++) {
    for (c = 0, j = 0; j <= N; j++) {
      if (heads())
        c++;
    }
  }
  for (j = 0; j <= N; j++) {
    printf ("%2d ", j);
    for (i = 0; i < f[j]; i += 10)
      printf ("*");
    printf ("\n");
  }
  return 0;
}