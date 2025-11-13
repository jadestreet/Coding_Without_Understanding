#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define maxclassi 5
#define maxstud 30
typedef struct { 
	char nomestud[10];
	char cognstud[10];
	int eta; 
} Studente;
typedef struct { 
	char lingua[10] ;
	int liv;
	int numiscritti;
	char nomeinsegn[15];
	Studente alunno [maxstud];
} Classe ;
Classe ScuolaLingue[maxclassi]= {
	{"inglese",1,2,"maestr1","alice","ferrari",8,"luca","bianchi",8,},
	{"inglese",2,2,"maestr2","guzzi","tommi",18,"gialli","fede",18},
	{"inglese",1,2,"maestr3","innoi","ldddd",10,"sssss","ddddd",10},
	{"spagnolo",2,2,"maestr4","ducai","ddddd",5, "wwwww","qqqqq",5}
};
int main () { 
	int i,j,cont=0;
	float somma=0;
	char linIng[]="inglese";
	for (i=0;i<maxclassi;i++)
		for(j=0;j<ScuolaLingue[i].numiscritti;j++)
			printf("\n %s %s eta':%d", 
			ScuolaLingue[i].alunno[j].nomestud,
			ScuolaLingue[i].alunno[j].cognstud,
			ScuolaLingue[i].alunno[j].eta);
	for (i=0;i<maxclassi;i++) { 
		if(strcmp(linIng,ScuolaLingue[i].lingua)==0){
			for(j=0;j<ScuolaLingue[i].numiscritti;j++) {
				cont++; 
				somma= 	somma+ScuolaLingue[i].alunno[j].eta; 
			}
		}
	}
	if (cont>0) 
		printf("\nl'eta' media e':%f", somma/cont);
	else 
		printf("\nnessun studente dei corsi di %s",linIng);
	system("pause"); 
	return 0;
}