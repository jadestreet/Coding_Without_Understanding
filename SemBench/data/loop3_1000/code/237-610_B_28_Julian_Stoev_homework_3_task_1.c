#include <stdio.h>
int main() {
	char symb;
	int counter;
	for (counter=97; counter<=122; ++counter){ 
		symb= counter;
		printf("%c - %d\n", symb , counter);} 
	for (counter=65; counter<=90; ++counter){ 
		symb= counter;
		printf("%c - %d\n", symb , counter);}
	for (counter=48; counter<=57; ++counter){ 
		symb= counter;
		printf("%c - %d\n", symb , counter);}	
	return 0;
}