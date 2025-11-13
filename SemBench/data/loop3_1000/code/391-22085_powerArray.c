#include <stdio.h>
#define POW 3
int fillUpArray(int *a, int size);
int displayArray(int *a, int size);
int power(int base, int n);
int main (){
  const int s = 10;
  int array[s];
  fillUpArray(array, s);
  displayArray(array, s);
  return 1;
}
int fillUpArray(int *a, int size){
  int i;
  for (i = 0 ; i < size ; i++){
    a[i] = power(i, POW);
  }
  return i;
}
int displayArray(int *a, int size){
  int i;
  for (i = 0 ; i < size ; i++){
    printf ("element[%d] = %d\n", i, a[i]);
  }
  return i;
}
int power(int base, int n)
{
   int i, p;
   p = 1;
   for (i = 1; i <= n; ++i)
    p = p * base;
  return p;
}