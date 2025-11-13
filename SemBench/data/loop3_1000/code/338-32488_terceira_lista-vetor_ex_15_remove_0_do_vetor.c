#include <stdio.h>
#include <stdlib.h>
int main(){
	int vetor[50],i,numero,vetor_compactado[50],k=0,zero=0;
	printf("Vetor na ordem:		");
	for (i=0;i<50;i++){
		vetor[i]=0;
		numero=(rand()%10);
		vetor[i]=numero;
			printf("%d ", vetor[i], i);
	}
	printf("\nVetor compactado:	");
	for (i=0;i<50;i++){
		vetor_compactado[i]=0;
		if (vetor[k]==0){
			k++;
			zero++;
		}
		vetor_compactado[i]=vetor[k];
		k++;
	}
	for (i=51-zero;i<50;i++){
		vetor_compactado[i]=0;
	}
	for (i=0;i<50;i++){
		printf("%d ",vetor_compactado[i]);
	}
	printf("\n");
}