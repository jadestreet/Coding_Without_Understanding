#include <stdio.h>
#define TAM 6
int main(){
int lista[TAM]={12,10,5,6,1,3};	 
int temp=0; 			 
int i,j;			 
printf("La lista DESORDENADA es: \n");
for (i=0;i<TAM;i++)
   printf("%3d",lista[i]);	
for (i=1;i<TAM;i++)
{
	for (j=0;j<TAM-1;j++)
	{
            if (lista[j] > lista[j+1])	 
            {
                    temp = lista[j];	 
                    lista[j]=lista[j+1];  
                    lista[j+1]=temp;	
            }
      }
}
printf("\nLos valores ORDENADOS de lista son: \n");
for(i=0;i<TAM;i++)
    printf("%3d",lista[i]);
return 0;
}