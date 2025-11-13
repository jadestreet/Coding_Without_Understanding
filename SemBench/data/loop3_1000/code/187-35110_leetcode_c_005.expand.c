#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* longestPalindrome(char* s) {
    int length = strlen(s);
    int imax, lmax = 0;
    int i = 0;
    int j, k, tmax;
    while (s[i] != '\0') {
        if (length - i < lmax / 2)
            break;
        j = i;
        k = i;
        while (s[k] == s[i])
            k++;
        i = k;
        while (j >= 0 && s[j] == s[k-1]) {
            j--;
            k++;
        }
        tmax = k - j - 2;
        if (tmax > lmax) {
            lmax = tmax;
            imax = j + 1;
        }
    }
    char* p = (char*)malloc((lmax + 1) * sizeof(char));
    memmove(p, s+imax, lmax);
    p[lmax] = '\0';
    return p;
}
int main() {
    printf("%s", longestPalindrome("dddddddddddd"));
    return 0;
}