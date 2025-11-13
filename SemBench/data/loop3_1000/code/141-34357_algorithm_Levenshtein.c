#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int min (int a, int b, int c) 
{
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}
int main(int argc, char *argv[]) 
{
    char *s = argv[1], *t = argv[2];
    int n = strlen(s), m = strlen(t), d[m+1][n+1], cost;
    int i,j;
    for (i=1; i<=m; i++) d[i][0] = i;
    for (j=1; j<=n; j++) d[0][j] = j;
    d[0][0] = 0;
    for (i=1; i<=m; i++) {
        for (j=1; j<=n; j++) {
            cost = t[i-1] == s[j-1] ? 0 : 1;
            d[i][j] = min(d[i][j-1]+1, d[i-1][j]+1, d[i-1][j-1]+cost);
        }
    }
    printf("    ");
    for (i=0; i<n; i++) printf("%c ", s[i]);
    printf("\n");
    for (i=0; i<=m; i++) {
        char c = i > 0 ? t[i-1] : ' ';
        printf("%c ", c);
        for (j=0; j<=n; j++) printf("%d ", d[i][j]);
        printf("\n");
    }
    return 0;
}