#include<stdio.h>
#include<string.h>
#define GAMESIZE 20
int blockval(int box[][GAMESIZE],int i,int j){
	int res=box[i][j];
	if(i>0)
		res^=box[i-1][j];
	if(j>0)
		res^=box[i][j-1];
	if(j<GAMESIZE-1)
		res^=box[i][j+1];
	return res;
}
int tryi(long long val){
	int gamebox[GAMESIZE][GAMESIZE];
	memset(gamebox,0,sizeof(gamebox));
	int i;	
	for(i=0;i<GAMESIZE;i++)
		gamebox[0][i]=(val>>i)%2;
	int j;
	for(i=1;i<GAMESIZE;i++){
		for(j=0;j<GAMESIZE;j++){
			if(!blockval(gamebox,i-1,j)){
				gamebox[i][j]=1;
			}
		}
	}
	for(i=0;i<GAMESIZE;i++)
		if(!blockval(gamebox,GAMESIZE-1,i))
			return 0;
	printf("\n");
	for(i=0;i<GAMESIZE;i++){
		for(j=0;j<GAMESIZE;j++){
			printf("%d ",gamebox[i][j]);
		}
		printf("\n");
	}
	return 1;
}
void printres(long long val){
	int s=GAMESIZE;
	printf("First line:\n");
	while(s-->0){
		printf("%d ",(int)(val%2));
		val/=2;
	}
	printf("\n");
	return ;
}
int main(){
	long long i,maxi=((long long)1)<<GAMESIZE;
	for(i=0;i<maxi;i++){
		if(tryi(i))
			break;
	}
	printf("\n");
	if(i==maxi)
		printf("No solution\n");
	else
		printres(i);
	return 0;
}