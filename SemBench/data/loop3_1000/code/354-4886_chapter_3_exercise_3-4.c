#include <stdio.h>
#include <string.h>
#include <limits.h>
void myitoa(int n, char s[]);
void shortreverse(char s[]);
int main() {
    char string1[100];
    int number = INT_MIN;
    myitoa(number, string1);
    printf("%s\n", string1);
}
void myitoa(int n, char s[])
{
    int i, sign, minflag;
    minflag = 0;
    if ((sign = n) < 0) {
        if (n == INT_MIN)
            n++, minflag++;
        n = -n;         
    }
    i = 0;
    do {    
        s[i++] = n % 10 + '0'; 
    } while ((n /= 10) > 0);
    if (sign < 0){
        if(minflag)
            s[0]++;
        s[i++] = '-';
    }
    s[i] = '\0';
    shortreverse(s);
}
void shortreverse(char s[])
{
    int c, i ,j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}