#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 3
int main()
{
    int m[MAX][MAX];
    int i, j;
    srand(time(NULL));
    for ( i = 0 ; i < MAX ; i++) 
        for ( j = 0 ; j < MAX ; j++)
            m[i][j] = rand() % 10;
    for ( i = 0 ; i < MAX ; i++) 
    {
        for ( j = 0 ; j < MAX ; j++)
        {
            printf("%i ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}