#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 1000000
#define intentos 100
void nAleatorios(double *nums);
double promedio(double *x, int size);
int main() {
  FILE *fout;
  fout = fopen("resultados.txt", "a");
  srand48(time(NULL));
  double *x = (double *) malloc(N*sizeof(double));
  double *y = (double *) malloc(N*sizeof(double));
  double *valores = (double *) malloc(intentos*sizeof(double));
  int j = 0, k=0;
  int cuenta = 0;
  double pi = 0;
  while (k < intentos) {
    nAleatorios(x);
    nAleatorios(y);
    while (j < N) {
      if (x[j]*x[j] + y[j]*y[j] < 1.0) {
        cuenta += 1;
      }
      j +=1;
    }
    valores[k] = (double) 4*cuenta/N;
    k += 1;
  }
  pi = promedio(valores,intentos);
fprintf(fout,"El valor de la constante pi es: %lf\n", pi);
  return 0;
}
double promedio(double *x, int size){
  int i;
  double sum = 0;
  for ( i = 0; i < size; i++) {
    sum += x[i];
  }
  return sum/size;
}
void nAleatorios(double *nums){
  int i;
  for ( i = 0; i < N; i++) {
    nums[i] = drand48()*2 -1;
  }
}