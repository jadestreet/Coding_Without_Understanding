#include <stdio.h>
int main(void)
{
    int i, j, a;
    for (i = 0; i < 5; i++)
    {
        for (a = 0; a < i; a++)
            printf(" ");
        for (j = 0; j < 5; j++)
            printf("* ");
        printf("\n");
    }
}