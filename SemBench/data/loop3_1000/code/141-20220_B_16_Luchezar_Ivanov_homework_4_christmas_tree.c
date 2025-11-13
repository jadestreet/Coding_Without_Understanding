#include <stdio.h>
void christmastree(int height)
{
int i,j,stars,k,space;
stars=1;
space=height;
for(i=1;i<=height;i++)
	{
	for(k=space-1;k>0;k=k-1)
		{
		printf(" ");
		}
	for(j=1;j<=stars;j++)
		{
		printf("*");
		}
	stars=stars+2;
	space=space-1;
	printf("\n");
	}
}
int main()
{
christmastree(4);
christmastree(7);
christmastree(11);
return 0;
}