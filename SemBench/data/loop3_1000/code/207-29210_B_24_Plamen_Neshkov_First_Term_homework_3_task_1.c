#include <stdio.h>
int main() {
	int i;
	char x;
	for (i=97; i<=122; i++) {
		x = i;
		printf("%c - %d\n",x,i);	
	}
	for (i=65; i<=90; i++) {
		x = i;
		printf("%c - %d\n",x,i);	
	}
	for (i=48; i<=57; i++) {
		x = i;
		printf("%c - %d\n",x,i);	
	}
	return 0;
}