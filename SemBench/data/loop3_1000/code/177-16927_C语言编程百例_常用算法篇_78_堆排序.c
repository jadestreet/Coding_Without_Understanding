#include <stdio.h>
#define MARK 0
static int a[11] = { MARK, 25, 4, 36, 1, 60, 10, 58, 14, 47, 18 };
int count = 1;
void heap(int n);           
void adjust(int i, int n);  
int main(int argc, char **argv) {
  int i;
  printf("source data : ");
  for (i = 1; i < 11; i++) {
    printf("%5d", a[i]);
  }
  printf("\n");
  heap(10);
  printf("\nsorted array is : ");
  for (i = 1; i < 11; i++) {
    printf("%5d", a[i]);
  }
  printf("\n");
  return 0;
}
void heap(int n) {
  int i, j, t;
  for (i = n/2; i > 0; i--) {
    adjust(i, n);
  }
  printf("\ninit heap==> ");
  for (i = 1; i < 11; i++) {
    printf("%5d", a[i]);
  }
  printf("\n");
  for (i = n - 1; i > 0; i--) {
    t = a[i + 1];
    a[i + 1] = a[1];
    a[1] = t;
    adjust(1, i); 
    printf("\n第%2d步操作结果===>", count++);
    for (j = 1; j < 11; j++) {
      printf("%5d", a[j]);
    }
  }
}
void adjust(int i, int n) {
  int j, k, r;
  int done = 0;
  k = r = a[i];
  j = 2 * i;
  while ( (j <= n) && (done == 0) ) {
    if (j < n) {
      if (a[j] < a[j + 1]) j++;
    }
    if (k >= a[j]) {
      done = 1;
    } else {
      a[j/2] = a[j];
      j = 2 * j;
    }
  }
  a[j/2] = r;
}