#include <stdio.h>
void itoa(int n, char s[]);
void reverse(char s[]);
int main(void)
{
	char s[100];
	itoa(1234, s);
	printf("Output:%s\n", s);
	return 0;
}
void itoa(int n, char s[])
{
    int i;
    int sign = (n < 0) ? -1 : 1;
    i = 0;
    do {
        s[i++] = sign * (n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
void reverse(char s[])
{
	int i, j, end;
	char c;
	for(i = 0; s[i] != '\0'; i++)
		;
	end = i--;
	for(j = 0; (i != j) && (j < i); j++, i--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	s[end] = '\0';
}