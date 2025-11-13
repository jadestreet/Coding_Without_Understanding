#include <stdio.h>
#include <stdlib.h>
int maxWeight;
int randomWeight () {
  return 1 + (int) (maxWeight * (rand() / (RAND_MAX + 1.0)));
}
int main (int argc, char **argv) {
  int i, j, k;
  if (argc < 2) {
    printf ("Usage: ./generateBench n\n");
    printf ("       parameter n is used to generate graph with n^2+2 vertices.\n");
    return 0;
  }
  int n = atoi (argv[1]);
  printf ("Benchmark 1 [%d]\n", n);
  maxWeight = n*n;
  int e = n*n*n-n*n+2*n;
  printf ("%d %d directed\n", n*n+2, e);
  for (i = 1; i <= n; i++) {
    printf ("%d,%d,%d\n", 0, i, randomWeight());
  }
  for (i = n*n-n+1; i <= n*n; i++) {
    printf ("%d,%d,%d\n", i, n*n+1, randomWeight());
  }
  i = 1;
  while (i < n*(n-1)) {
    for (j = 0; j < n; j++) {
      for (k = 0; k < n; k++) {
	printf ("%d,%d,%d\n", i+j, i+n+k, randomWeight());
      }
    }
    i += n;
  }
} 