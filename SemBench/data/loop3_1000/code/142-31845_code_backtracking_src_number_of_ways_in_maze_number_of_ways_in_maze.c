#include<stdio.h>
#define MAX_SIZE 10
void solveMaze(char maze[][10],int sol[][10],int i,int j,int m,int n,int *ways){
    if(i==m && j==n){
        sol[m][n] = 1;
        (*ways)++;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                printf("%d ", sol[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return ;
    }
    if (sol[i][j]) {
        return;
    }
    sol[i][j] = 1;
    if(j+1<=n && maze[i][j+1]!='X'){
        solveMaze(maze,sol,i,j+1,m,n,ways);
    }
    if(j-1>=0 && maze[i][j-1]!='X'){
        solveMaze(maze,sol,i,j-1,m,n,ways);
    }
    if(i-1>=0 && maze[i-1][j]!='X'){
        solveMaze(maze,sol,i-1,j,m,n,ways);
    }
    if(i+1<=m && maze[i+1][j]!='X'){
        solveMaze(maze,sol,i+1,j,m,n,ways);
    }
    sol[i][j] =0;
    return;
}
int main(){
    char maze[MAX_SIZE][MAX_SIZE] = {
        "00XXX",
        "00000",
        "0XX00",
        "000X0",
        "0X000"
    };
    int m = 4,n=4;
    int sol[MAX_SIZE][MAX_SIZE];
    int i,j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j <MAX_SIZE; j++) {
            sol[i][j]=0;
        }
    }
    int ways=0;
    solveMaze(maze,sol,0,0,m,n,&ways);
    if(ways){
        printf("Total ways %d\n", ways);
    }
    else{
        printf("No ways\n");
    }
return 0;
}