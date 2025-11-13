#include <stdio.h>
int main(int argc, char **argv)
{
    int a, b, db, d, s = 0;
    for (a = 2; a < 10000; a++)
    {
        b = 0;
        for (d = 1; d * d <= a; d++)
        {
            if (d == 1 || d * d == a)
                b += d;
            else if (a % d == 0)
                b += d + a / d;
        }
        if (a >= b)
            continue;
        db = 0;
        for (d = 1; d * d <= b; d++)
        {
            if (d == 1 || d * d == b)
                db += d;
            else if (b % d == 0)
                db += d + b / d;
        }
        if (a == db)
        {
            s += a;
            if (b < 10000)
                s += b;
        }
    }
    printf("%d\n", s);
    return 0;
}