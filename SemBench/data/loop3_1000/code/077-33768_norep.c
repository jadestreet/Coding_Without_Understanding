#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define L_MAX 100
#define N_SR 6
void norep(int num[]);
int sorteio();
void imprime(int num[],int lin);
int main()
{
    int  num[N_SR];
    srand( time(NULL));
    printf("tabela com os numero sem repeticao de 1 a 6\n");
    printf("a tabela se repetira por 100 vezes\n\n");
    norep(num);
    return 0;
}
void norep(int num[])
{
    int j,i,k;
    for(k=0;k<L_MAX;k++)
    {
        for(j=0;j<N_SR;j++) 
        {
            num[j]=0;
        }
        for(j=0;j<N_SR;j++)
        {    
            num[j]=sorteio();
            for(i=0;i<j;i++)
            {
                if(num[i]==num[j])
                {
                    j--;
                    break;
                }
            }
        }
        imprime(num,k+1);
    }
    return;
}
int sorteio()
{
    int num;
    num= (rand()%N_SR)+1;
    return num;
}
void imprime(int num[],int lin)
{
    int i;
    printf("Linha %d ",lin);
    for(i=0;i<N_SR;i++)
    {
        printf("|%d\t",num[i]);
    }
    printf(" \n");
    return ;
}