#include <limits.h>
#include <stdio.h>
int main(void)
{
	printf("minimum value for a signed char: %d\n", SCHAR_MIN);
	printf("maximum value for a signed char: %d\n", SCHAR_MAX);
	printf("maximum value for an unsigned char: %d\n", (int) UCHAR_MAX ); 
	printf("minimum value for a char: %d\n", (int) CHAR_MIN );
	printf("maximum value for a char: %d\n", (int) CHAR_MAX );
	if(SCHAR_MIN == CHAR_MIN && SCHAR_MAX == CHAR_MAX)
		printf("The 'char' type seems to be the same as 'signed char' on this machine.\n");
	else if(CHAR_MIN == 0 && UCHAR_MAX == CHAR_MAX)
		printf("The 'char' type seems to be the same as 'unsigned char' on this machine.\n");
	else
		printf("Huh?\n");
	signed char signedH = 'H';
	unsigned char unsignedH = 'H';
	char plainH = 'H';
	printf("SignedH: %c %d\n", signedH, signedH);
	printf("UnsignedH: %c %d\n", unsignedH, unsignedH);
	printf("PlainH: %c %d\n", plainH, plainH);
	signed char signedTwoHund = 200;     
	unsigned char unsignedTwoHund = 200; 
	char plainTwoHund = 200;             
	printf("SignedTwoHund: %c %d\n", signedTwoHund, signedTwoHund);
	printf("UnsignedTwoHund: %c %d\n", unsignedTwoHund, unsignedTwoHund);
	printf("PlainTwoHund: %c %d\n", plainTwoHund, plainTwoHund);
}