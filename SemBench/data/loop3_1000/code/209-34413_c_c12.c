#include <stdio.h>
#define MAX 500
long nextTriang();
int numdivs(int num);
int main()
{
    int divs, max;
    long triang;
    max = 0;
    do {
        triang = nextTriang();
        divs = numdivs(triang);
        if (divs > max) {
            max = divs;
            printf("max num of divs: %i\n", max);
        }
    } while (divs < MAX);
    printf("%i has %i divisors\n", triang, divs);
}
long nextTriang()
{
    static long lasttriang = 0, num = 1;
    long triang;
    triang = lasttriang + num;
    lasttriang = triang;
    num++;
    return triang;
}
int numdivs(int num) {
    int i;
    int divs;
    for (i = 1, divs = 0; i <= num; i++) {
        if (num % i == 0)
            divs++;
    }
    return divs;
}