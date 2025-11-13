#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i, j,max,min;
    int mas[10][10];
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
            mas[i][j] = rand() % 100;
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d\t", mas[i][j]);
        }
        printf("\n");
    }
    min = mas[0][0];
    max = mas[0][0];
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (mas[i][j] < min)
                min = mas[i][j];
            if (mas[i][j] > max)
                max = mas[i][j];
        }
    }
    printf("%s%i\n","Min = ", min);
    printf("%s%i","Max = ", max);
    return 0;
}