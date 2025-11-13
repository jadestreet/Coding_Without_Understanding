#include <stdio.h>
int quicksort(int lista[], int t);
int quicksorth(int lista[], int f, int l);
int particion(int lista[], int f, int l);
int main()
 {
  int lista[] = {54, 26, 93, 17, 77, 31, 44, 55, 20}, i, t = 9;
  quicksort(lista, t);
  for(i = 0; i < t; i++)
   {
    printf("%i\n", lista[i]);
   }
 }
int quicksort(int lista[], int t)
 {
  int l = t;
  quicksorth(lista, 0, l);
 }
int quicksorth(int lista[], int f, int l)
 {
  int s;
  if(f < l)
   {
    s = particion(lista, f, l);
    quicksorth(lista, f, s);
    quicksorth(lista, s + 1, l);
   }
 }
int particion(int lista[], int f, int l)
 {
  int pivote = lista[f];
  int izq = f + 1;
  int der = l;
  int temp;
  int done = 0;
  while(!done)
   {
    while(izq <= der && lista[izq] <= pivote)
     {
      izq = izq + 1;
     }
    while(lista[der] >= pivote && der >= izq)
     {
      der = der - 1;
     }
    if(der < izq)
     {
      done = 1;
     }
    else
     {
      temp = lista[izq];
      lista[izq] = lista[der];
      lista[der] = temp;
     }
   }
  temp = lista[f];
  lista[f] = lista[der];
  lista[der] = temp;
  return der;
 }