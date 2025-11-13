#include <stdio.h>
#include <stdlib.h>
#define N 5
#define C 4
typedef struct processos{
	int id[N];
	int filosofo[N]; 
	int tempo[N];
}processos;
void init(processos *jantar);
void ceia(processos *jantar);
void init(processos *jantar){
	int i;
	for(i=0;i<N;i++){
		printf("%i",i);
		jantar->id[i]=i;
		jantar->filosofo[i]=0;
		jantar->tempo[i]=0;
	}
}
void ceia(processos *jantar){
	int i=0, j=0;
	for(i=0;i<N;i++){
			printf("1 jantar->filosodo[%i]\n", jantar->filosofo[i]);
			if((jantar->filosofo[i]==0)){
			printf("jantar->filosodo[%i]\n", jantar->filosofo[i]);
				if(i=0){
					if(jantar->filosofo[N-1]==0&&jantar->filosofo[1]==0){
						jantar->filosofo[0]=!jantar->filosofo[0];
						jantar->tempo[0]=C;
				}else if(i=(N-1)){
						if(jantar->filosofo[0]==0&&jantar->filosofo[N-2]==0){
							jantar->filosofo[N-1]=!jantar->filosofo[0];
							jantar->tempo[N-1]=C;		
						} 
					}else if(jantar->filosofo[i-1]==0&&jantar->filosofo[i+1]==0){
							jantar->filosofo[i]=!jantar->filosofo[i];
							jantar->tempo[i]=C;
					}
				}
			}
		}puts(" ");
		for(i=0; i<N; i++){
			if(jantar->filosofo[i]){
					printf("Filosofo %i comendo \n", jantar->id[i]);
					jantar->tempo[i]--;
				if(!jantar->tempo[i]){
						jantar->filosofo[i]=0;
						jantar->tempo[i]=C;	
					}
				}else{ 	
					jantar->tempo[i]--;
					printf("Filosofo %i pensando \n", jantar->id[i]);		
				}
		}
}
int main(){
	processos jantar;	
	init(&jantar);
	while(1)
	ceia(&jantar);
}