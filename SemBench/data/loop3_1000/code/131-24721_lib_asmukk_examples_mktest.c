#include <stdio.h>
#include <stdlib.h>
char rc(void) {
  int k;
  k = rand()%4;
  if (k==0) { return 'a'; }
  else if (k==1) { return 'c'; }
  else if (k==2) { return 'g'; }
  else if (k==3) { return 't'; }
  return '\0';
}
int main(int argc, char **argv) {
  int i, j, k;
  int n, z;
  double p, P=1.0/100.0;
  long int seed = -1;
  int pair, n_pair = 1;
  char *a, *b;
  n = 10000;
  if (argc>1) { n = atoi(argv[1]); }
  if (argc>2) { seed = atoi(argv[2]); }
  if (argc>3) { P = atof(argv[3]); }
  if (argc>4) { n_pair = atoi(argv[4]); }
  if (seed>=0) { srand((unsigned long int)seed); }
  a = (char *)malloc(sizeof(char)*(n+1));
  a[n] = '\0';
  for (pair=0; pair<n_pair; pair++) {
    for (i=0; i<n; i++) { a[i] = rc(); }
    printf("%s\n", a);
    for (i=0; i<n; i++) {
      p = (double)rand()/(RAND_MAX+1.0);
      if (p<P) {
        k = rand()%3;
        if (k==0) { printf("%c", rc()); }                 
        else if (k==1) { continue; }                      
        else if (k==2) { printf("%c%c", a[i], rc()); }    
      } else {
        printf("%c", a[i]);
      }
    }
    printf("\n");
  }
}