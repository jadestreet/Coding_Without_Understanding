#include <stdio.h>
int factor_num(int n)
{
  int i, j, sum = 1;
  for (i=2; i<=n; i++) {
    if (n%i == 0) {
      for(j=0; n%i==0; j++)
	n /= i;
      sum *= j+1;
    }
  }
  return sum;
}
int triangle(int n)
{
  return n*(n+1)/2;
}
int main()
{
  int i;
  for (i=2; factor_num(triangle(i)) <= 500; i++);
  printf("%d\n", triangle(i));
}