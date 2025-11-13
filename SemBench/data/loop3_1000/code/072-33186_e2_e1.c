#include <stdio.h>
int main(int argc, char * argv[])
{
    int a[10][10]={};
    int i,j;
    for (i=1;i<10 ;i++ )
    {
        for (j=1;j<=i ;j++ ){
            a[i][j] = i+j;
        }
    }
    for (i=1;i<10 ;i++ )
    {
        for (j=1;j<=i ;j++ ){
            printf("%d+%d=%2d; ",j,i,a[i][j] );
        }
        printf("\n");
    }
    return 0;
}