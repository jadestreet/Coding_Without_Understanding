#include <stdio.h>
int main()
{
    int i, j, x=0;
    printf("1. nested for loop is contained inside the external for loop\n");
    for(i=0; i<5; i++) {
        for(j=0; j<i; j++)
            x += i + j - 1;
            printf("%d ", x);
            break;
    }
    printf("\nx = %d", x);
    printf("\n\n");
    printf("2. nested for loop is contained outside the external for loop\n");
    for(i=0; i<5; i++)
        for(j=0; j<i; j++) {
            x += i + j - 1;
            printf("%d ", x);
            break;
        }
    printf("\nx = %d", x);
    return 0;
}