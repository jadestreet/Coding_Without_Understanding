#include <stdio.h>
int main ()
{
	int  num=5170984,n = num;
    int rev = 0,revnum = 0;
	while  (num != 0)
    {
        rev = num % 10 ;
        revnum = revnum * 10 + rev;
        num/=10;
    }
    printf("%d-%d\n",n,revnum);
	printf("\n");
	n = num = 406567;
	rev = 0,revnum = 0;
	while  (num != 0)
    {
        rev = num % 10 ;
        revnum = revnum * 10 + rev;
        num/=10;
    }
    printf("%d-%d\n",n,revnum);
	printf("\n");
	n = num = 368750;
	rev = 0,revnum = 0;
	while  (num != 0)
    {
        rev = num % 10 ;
        revnum = revnum * 10 + rev;
        num/=10;
    }
    printf("%d-%d\n",n,revnum);
	printf("\n");
	n = num = 2369510;
	rev = 0,revnum = 0;
	while  (num != 0)
    {
        rev = num % 10 ;
        revnum = revnum * 10 + rev;
        num/=10;
    }
    printf("%d-%d\n",n,revnum);
	printf("\n");
	n = num = 2183293;
	rev = 0,revnum = 0;
	while  (num != 0)
    {
        rev = num % 10 ;
        revnum = revnum * 10 + rev;
        num/=10;
    }
    printf("%d-%d\n",n,revnum);
    return 0;
}