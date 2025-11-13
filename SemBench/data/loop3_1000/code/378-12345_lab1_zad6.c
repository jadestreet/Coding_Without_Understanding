#include <stdio.h>
int main()
{
  int a,b,c,d;
  a=b=c=d=0;
  printf("A. %d %d %d %d\n", a, b, c, d);
  printf("B. ");
  int i,N=5,tab[5]={0,1,2,3,4};
  for(i=0;i<N;tab[i++]=i)
    printf("%d ", tab[i]);
  printf("\nC. ");
  for(i=0;i<N;tab[++i]=i)
    printf("%d ", tab[i]);
  i=1;
  while((i*=2)<N);
  printf("\nD. %d\n", i);
  return 0;
}