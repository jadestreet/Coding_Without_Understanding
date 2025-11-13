#include <stdio.h>
#define INF 32767
#define N 6
void floyd(int g[N][N], int path[N][N], int dist[N][N])
{
    int i, j, k, l;
    for (i=0; i < N; i++){
        path[i][i] = i;
        for (j=0; j<N; j++) {
            dist[i][j] = g[i][j];   
            if (dist[i][j] < INF) {
                path[i][j] = i;
            }
        }
    }
    for (k=0; k<N; k++){
        for(i=0; i< N; i++) {
            for (j=0; j<N; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}
void printPath(int path[N][N], int v0, int vt)
{
    int k;
    k = path[v0][vt];
    if (k != v0 && k!=vt){
        printPath(path, v0, k);
        printf(",");
        printPath(path, k, vt);
    }
    else {
        printf("%d->%d", v0, vt);
    }
}
int main(void)
{
    int g[N][N] = {
            {0, 7, 9, INF, INF, 16},
            {7, 0, 10, 15, INF, INF},
            {9, 10, 0, 11, INF, 2},
            {INF, 15, 11, 0, 6, INF},
            {INF, INF, INF, 6, 0, 9},
            {14, INF, 2, INF, 9, 0}
    };
    int path[N][N];
    int dist[N][N];
    int i,j;
    floyd(g, path, dist);
    for (i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%d->%d %d  ", i, j, dist[i][j]);
            printPath(path, i, j);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}