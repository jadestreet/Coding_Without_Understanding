#include <stdio.h>
int min_of(const int v[], int n);
void rev_intary(int v[], int n);
void intary_rcpy(int v[], const int v2[], int n);
void print_intary(const int v[], int n);
int main(void)
{
  int x[] = { 1, 2, 3, 4, 5 };
  int y[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
  int z[] = { 11, 22, 33, 44, 55, 66};
  int zr[6] = {0};
  printf("数组X");
  print_intary(x, 5);
  printf("的最小值是: %d\n", min_of(x, 5));
  printf("数组Y");
  print_intary(y, 10);
  printf("的反序是: ");
  rev_intary(y, 10);
  print_intary(y, 10);
  putchar('\n');
  printf("数组Z");
  print_intary(z, 6);
  printf("的反序是: ");
  intary_rcpy(zr, z, 6);
  print_intary(zr, 6);
  putchar('\n');
  return 0;
}
int min_of(const int v[], int n)
{
  int min = v[0];
  for (int i = 1; i < n; i++) {
    if (v[i] < min) {
      min = v[i];
    }
  }
  return min;
}
void rev_intary(int v[], int n)
{
  for (int i = 0; i < n / 2; i++) {
    int t = v[i];
    v[i] = v[n - i - 1];
    v[n - i - 1] = t;
  }
}
void intary_rcpy(int v[], const int v2[], int n)
{
  for (int i = 0; i < n; i++) {
    v[n - i - 1] = v2[i];
  }
}
void print_intary(const int v[], int n)
{
  printf("{ ");
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("}");
}