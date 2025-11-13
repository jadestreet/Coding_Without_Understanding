#include <stdio.h>
int main()
{
    int a[3][4] = {{1,2,3,4},{2,2,3,4},{3,2,3,4}};
    int b[4][3];
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            b[i][j] = a[j][i];
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("b[%d][%d] = %d\t\t",i,j,b[i][j]);
        }
        printf("\n");
    }
    return 0;
}