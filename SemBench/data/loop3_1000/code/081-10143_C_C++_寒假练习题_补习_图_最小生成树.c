#include <stdio.h>
#include <string.h>
#define MAXN 100
#define INF 65535
int n = 9;
int G[MAXN][MAXN] =
{
    {0, 10, INF, INF, INF, 11, INF, INF, INF},
    {10, 0, 18, INF, INF, INF, 16, INF, 12},
    {INF, INF, 0, 22, INF, INF, INF, INF, 8},
    {INF, INF, 22, 0, 20, INF, INF, 16, 21},
    {INF, INF, INF, 20, 0, 26, INF, 7, INF},
    {11, INF, INF, INF, 26, 0, 17, INF, INF},
    {INF, 16, INF, INF, INF, 17, 0, 19, INF},
    {INF, INF, INF, 16, 7, INF, 19, 0, INF},
    {INF, 12, 8, 21, INF, INF, INF, INF, 0}
};
void MiniSpanTree_Prim(void)
{
    int min, i, j, k;
    int adjvex[MAXN];   
    int lowcost[MAXN];  
    lowcost[0] = 0;   
    adjvex[0] = 0;   
    for(i = 1; i < n; i ++)      
    {
        lowcost[i] = G[0][i];   
        adjvex[i] = 0;   
    }
    for(i = 1; i < n; i ++)
    {
        min = INF;     
        j = 1;
        k = 0;
        while( j < n )
        {
            if( lowcost[j] != 0 && lowcost[j] < min )    
            {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        printf("(%d, %d) %d\n", adjvex[k], k, lowcost[k]);    
        lowcost[k] = 0;   
        for(j = 1; j < n; j ++)
        {
            if( lowcost[j] != 0 && G[k][j] < lowcost[j] )
            {
                lowcost[j] = G[k][j];    
                adjvex[j] = k;    
            }
        }
    }
}
int main(void)
{
    MiniSpanTree_Prim();
    return 0;
}