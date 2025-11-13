# include <stdio.h>
int main() 
{ 
    int processes[] = { 1, 2, 3, 4}; 
    int n = sizeof processes / sizeof processes[0]; 
    int bt[]={3, 6, 9, 3};
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    wt[0] = 0; 
    for (int  i = 1; i < n; i++ ) 
        wt[i] =  bt[i-1] + wt[i-1] ;
    for (int  i = 0; i < n; i++) 
        tat[i] = bt[i] + wt[i]; 
    printf( "Processes\tBurst time\tWaiting time\tTurn around time \n"); 
    for (int  i = 0; i < n ; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        printf("%d\t\t %d \t\t %d \t\t %d\n",i+1 ,bt[i] , wt[i], tat[i] ); 
    } 
    printf( "Average waiting time = %f", (float)total_wt / (float)n); 
    printf( "\nAverage turn around time = %f", (float)total_tat / (float)n);       
    return 0; 
}