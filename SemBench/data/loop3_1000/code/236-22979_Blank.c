#include <stdio.h>
int main ()
{
    int x, xx, xxx;
    for(x = 0; x < 9; x++)
    {
        x += -1;
        for(xx = 0; xx < x; xx++)
        {
            printf(" ");
        }
        for (xxx = 0; xxx < ((2 * x) - 1); xxx++)
        {
            printf ("*");
        }
        printf("\n");
    }
    return 0;
}