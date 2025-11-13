#include<stdio.h>
int main()
{
	char c;
	c='a';while( c <= 'z' ) { printf("%d - %c\n",c,c); c++; }
	c='A';while( c <= 'Z' ) { printf("%d - %c\n",c,c); c++; }
	c='0';while( c <= '9' ) { printf("%d - %c\n",c,c); c++; }
	return 0;
}