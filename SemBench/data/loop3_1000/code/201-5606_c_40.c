#include <stdio.h>
int fdigit(int n)
{
    int i, v;
    int p = 9;
    int d = 1;
    n--;
    while (n >= p * d)
    {
        n -= p * d;
        p *= 10;
        d++;
    }
    v = 1;
    for (i = 0; i < d - 1; i++)
        v *= 10;
    v += n / d;
    for (i = 0; i < d - n % d - 1; i++)
        v /= 10;
    return v % 10;
}
int main(int argc, char **argv)
{
    int i, m, p = 1;
    for (i = 0, m = 1; i < 7; i++, m *= 10)
        p *= fdigit(m);
    printf("%d\n", p);
    return 0;
}