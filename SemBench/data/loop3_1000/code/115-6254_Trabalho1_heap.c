#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100 
void swap(int *a, int *b){
        int c = *a;
        *a = *b;
        *b = c;
}
void heapify(int vetor[], int tam, int i)
{
        int maior = i; 
        int l = 2*i + 1; 
        int r = 2*i + 2; 
        if (l < tam && vetor[l] > vetor[maior])
                maior = l;
        if (r < tam && vetor[r] > vetor[maior])
                maior = r;
        if (maior != i)
        {
                swap(&vetor[i], &vetor[maior]);
                heapify(vetor, tam, maior);
        }
}
void heapSort(int vetor[], int tam)
{
        for (int i = tam/2-1; i >= 0; i--)
                heapify(vetor, tam, i);
        for (int i = tam-1; i >= 0; i--)
        {
                swap(&vetor[0], &vetor[i]);
                heapify(vetor, i, 0);
        }
}
void print(int vetor[], int tam)
{
        for (int i=0; i < tam; i++)
                printf("%d ",vetor[i]);
        printf("\n");
}
int main(int argc, char const *argv[]) {
        int vetor[TAM];
        int i;
        for (i=0; i < TAM; i++) {
                vetor[i] = (rand() % 100); 
        }
        int tam = sizeof(vetor) / sizeof(vetor[0]);
        heapSort(vetor, tam); 
        return 0;
}