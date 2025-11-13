#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#define MAX_LENGTH	12
void reverse (char s[]) {
	int i, j, c;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}
void itoa_alt (int n, char s[]) {
	int i, sign;
	sign = n;
	i = 0;
	do {
		s[i++] = abs (n % 10) + '0';
	} while ((abs(n /= 10)) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
void itoa (int n, char s[]) {
	int i, sign;
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);	
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
int main (void) {
	int n = INT_MIN;
	char s[MAX_LENGTH] = {0};
	itoa_alt(n,s);
	printf("number character string is \'%s\'\n", s);
	return 0;
}