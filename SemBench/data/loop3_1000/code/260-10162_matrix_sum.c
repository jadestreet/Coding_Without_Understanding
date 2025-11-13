#include <stdio.h>
#define ROW 4
#define COL 4
int M[ROW][COL]={2,3,4,5,0,1,5,8,9,6,45,3,1,3,5,0};
int mdm[ROW][COL];
void fill_mdm()	{
	int i,j,k,sum;
	for(i=0;i<ROW;i++)	{
		for(j=0;j<COL;j++)	{
			sum=0;
			for(k=0;k<=j;k++) {	
				sum+=M[i][k];
			}
	if(i>0)	
		mdm[i][j]=mdm[i-1][j]+sum;
	else
		mdm[i][j]=sum;
}
}
}
void matprint()	{
	int i,j;
	for(i=0;i<ROW;i++)	{
		for(j=0;j<COL;j++)	{
			printf("%d,",mdm[i][j]);
		}
	}
	printf("\n");
}
int getsum(int r1,int r2,int c1,int c2)	{
	int sum=0;
	sum+=mdm[r2][c2];
	if(r1>0)	{ sum-=mdm[r1-1][c2]; }
	if(c1>0)	{ sum-=mdm[r2][c1-1]; }
	if(r1>0 && c1>0)	{
		sum+=mdm[r1-1][c1-1];
	}
	return sum;
}
int main()	{
	fill_mdm();
	matprint();
	printf("%d",getsum(1,2,1,2));
}