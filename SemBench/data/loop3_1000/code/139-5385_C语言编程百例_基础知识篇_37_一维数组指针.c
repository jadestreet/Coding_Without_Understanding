#include <stdio.h>
void inv(int *x, int n);
int main(int argc, char **argv) {
  int i;
  int array[10] = {1, 3, 9, 11, 0, 8, 5, 6, 14, 98};
  printf("source array: \n");
  for (i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  inv(array, 10);
  printf("reverse array is: \n");
  for (i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}
void inv(int *x, int n) {
  int *p, *i, *j;
  int t;
  int m = (n - 1) / 2;
  i = x;
  j = x + n - 1;
  p = x + m;
  for (; i <= p; i++, j--) {
    t = *i;
    *i = *j;
    *j = t;
  }
}