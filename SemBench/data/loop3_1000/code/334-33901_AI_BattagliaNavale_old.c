#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(int argc){
char *file="navi.txt";
printf("Opening.. %s \n",file);
int righe[10];
int colonne[10];
int caselle[10][10];
caselle[1][2]=10;
int i,j,k;
for (i=0; i<10; i++){
	for (j=0; j<10; j++){
		caselle[i][j]=0;
}
}
printf(" ");
int lettere[14]={2,2,2,2,2,3,4,5,6,6,7,8,10,10};
int numeri[14]={5,6,7,8,9,3,3,3,3,7,7,7,7,8};
for (i=0; i<10; i++){
	for (j=0; j<10; j++){
		for (k=0; k<14; k++){
			if(i==lettere[k] && j==numeri[k]){
				caselle[i][j]=1;
}
}
}
}
for (i=0; i<10; i++){
	for (j=0; j<10; j++){
		printf("%d\t",caselle[i][j]);
}
printf("\n ");
}
srand(time(NULL));
int col = rand() % 10;
col++;
int rig = rand() % 10;
rig++;
int t=1;
int cento[100];
for (t=0;t<100;t++){
	cento[t]=0;
	}
int cas1=1;
int cas=1;
int conto=0;
int contatore;
int ko;
srand(time(NULL));
for (t=0;t<100;t++){
	while(cento[cas1]==2){
	cas = rand() %100;
	cas1=cas-1;
	cas=cas+10;
	}
			for (k=0; k<14; k++){
			if((cas/10)==lettere[k] && (cas%10)==numeri[k]){
				printf("c'hai preso! %d %d \n",cas/10,cas%10);
				conto++;
				for(contatore=1;contatore<6;contatore++){
				if(cento[cas1+contatore]!= 2){
				int preso = 0;
				t++; 
				cento[cas1+contatore]=2;
				for (ko=0; ko<14; ko++){
				if(((cas+contatore)/10)==lettere[ko] && ((cas+contatore)%10)==numeri[ko]){
					printf("c'hai ripreso! %d %d \n",(cas+contatore)/10,(cas+contatore)%10);
					conto++;
					preso=1;
					}
				else{ if(ko==13 && preso==0){
				contatore=6;}
				}
				}
				}
				}
				for(contatore=1;contatore<6;contatore++){
				if(cento[cas1-contatore]!= 2){
				int preso = 0;
				t++; 
				cento[cas1-contatore]=2;
				for (ko=0; ko<14; ko++){
				if(((cas-contatore)/10)==lettere[ko] && ((cas-contatore)%10)==numeri[ko]){
					printf("c'hai ripreso! %d %d \n",(cas-contatore)/10,(cas-contatore)%10);
					conto++;
					preso=1;
					}
				else{ if(ko==13 && preso==0){
				contatore=6;}
				}
				}
				}
				}
				for(contatore=10;contatore<60;contatore=contatore+10){
				if(cento[cas1+contatore]!= 2){
				int preso = 0;
				t++; 
				cento[cas1+contatore]=2;
				for (ko=0; ko<14; ko++){
				if(((cas+contatore)/10)==lettere[ko] && ((cas+contatore)%10)==numeri[ko]){
					printf("c'hai ripreso! %d %d \n",(cas+contatore)/10,(cas+contatore)%10);
					conto++;
					preso=1;
					}
				else{ if(ko==13 && preso==0){
				contatore=60;}
				}
				}
				}
				}
				for(contatore=10;contatore<60;contatore=contatore+10){
				if(cento[cas1-contatore]!= 2){
				int preso = 0;
				t++; 
				cento[cas1-contatore]=2;
				for (ko=0; ko<14; ko++){
				if(((cas-contatore)/10)==lettere[ko] && ((cas-contatore)%10)==numeri[ko]){
					printf("c'hai ripreso! %d %d \n",(cas-contatore)/10,(cas-contatore)%10);
					conto++;
					preso=1;
					}
				else{ if(ko==13 && preso==0){
				contatore=60;}
				}
				}
				}
				}
				if (conto==14){
				printf("%d \n", t+1);}
			}
			}
			cento[cas1]=2;
		}
return 0;
}