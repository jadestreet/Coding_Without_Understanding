#include <stdio.h>
void imprime_vetor(int vetor[], int N) {
	int i;
	for (i=0; i<N; i++)
		printf("%d\t", vetor[i]);
	printf("\n");
}
void troca(int *a, int *b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
void bubble_sort(int vetor[], int N) {
	int i;
	int j;
	j = 1;
	while (j==1) {
		j = 0;
		for (i = 0; i < (N-1); i++) {
			if (vetor[i+1] < vetor[i]) {
				troca(&(vetor[i+1]), &(vetor[i]));
				j = 1;
			}
		}
	}
}
void selection_sort(int vetor[], int N) {
	int i;
	int j;
	int k;
	if (N==1) return; 
	j = vetor[0];
	k = 0;
	for (i=0; i<N; i++) {
		if (vetor[i] < j) {
			j = vetor[i];
			k = i;
		}
	}
	troca(&(vetor[k]), &(vetor[0]));
	selection_sort(&(vetor[1]), N-1);
}
void insertion_sort(int vetor[], int N) {
	int n;
	int i;
	for (n=1; n<N; n++) {
		i = n;
		while ( (i>0) && (vetor[i] < vetor[i-1]) ) {
			troca(&(vetor[i]), &(vetor[i-1]));
			i--;
		}
	}
}
void quick_sort(int vetor[], int N) {
	int pivot;
	int j;
	int i;
	if (N<=1) return;
	pivot = vetor[0];
	i = 1;
	j = N-1;
	while (i < j) {
		while (vetor[j] > pivot)
			j--;
		if (vetor[i] > pivot)
			troca(&(vetor[i]), &(vetor[j]));
		i++;
	}
	troca(&(vetor[j]), &(vetor[0]));
	if (N > 3) {
		quick_sort(vetor, j);
		quick_sort(&(vetor[j]), N-j);	
	}
}
int main() {
	int vetor1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int vetor2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int vetor3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int vetor4[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	printf("Vetores originais:\n");
	imprime_vetor(vetor1, 11);
	imprime_vetor(vetor2, 11);
	imprime_vetor(vetor3, 11);
	imprime_vetor(vetor4, 11);
	bubble_sort(vetor1, 11);
	selection_sort(vetor2, 11);
	insertion_sort(vetor3, 11);	
	quick_sort(vetor4, 11);
	printf("Vetores ordenados:\n");
	imprime_vetor(vetor1, 11);
	imprime_vetor(vetor2, 11);
	imprime_vetor(vetor3, 11);
	imprime_vetor(vetor4, 11);
}