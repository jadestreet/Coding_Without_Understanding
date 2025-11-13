#include <stdio.h>
int main()
{
  printf("\nVamos fazer o fatorial de 10 utilizando o while\n");
  int valor=10; 
  int contador = 0;
  int resultadoFatorial = 0;
  do {
    if (contador>=0 && contador<=1) { 
      resultadoFatorial = 1;
    } else {
      resultadoFatorial = resultadoFatorial * contador;
    }
    printf("Vamos fazer o fatorial de %d. Parcial %d.\n", contador, resultadoFatorial);
    contador++;
  } while (valor>=contador);
  printf("O fatorial de %d eh %d\n", valor, resultadoFatorial);
  return 0;
}