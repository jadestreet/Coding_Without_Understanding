#include <stdio.h>
int len(char *a)
{
  int i;
  for (i=0; a[i]!=10; i++);
  return i;
}
void cheng2(char *a)
{
  int i;
  int l = len(a);
  int c=0;
  for (i=0; i<l; i++) {
    a[i] = a[i]*2+c;
    c=0;
    if (a[i] >= 10) {
      a[i] -= 10;
      c=1;
    }
  }
  if (c==1)
    a[l]=1;
}
int sum(char *a)
{
  int l = len(a);
  int i;
  int _sum=0;
  for (i=0; i<l; i++)
    _sum += a[i];
  return _sum;
}
int main()
{
  char a[1000];
  int i;
  for (i=0; i<1000; i++)
    a[i]=10;
  a[0]=1;
  for (i=0; i<1000; i++) {
    cheng2(a);
  }
  printf("%d\n", sum(a));
}