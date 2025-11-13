#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
void itoa(int n, char s[]);
void reverse(char s[]);
int main(void)
{
    char s[100];
    itoa(INT_MIN, s);
    printf("%s\n", s);
}
void itoa(int n, char s[])
{
    int i, sign;
    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
        printf("%d %d\n", n % 10, n / 10);
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
void reverse(char s[])
{
    int i, j, temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}