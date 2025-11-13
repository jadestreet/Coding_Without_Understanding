#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void quickk (int *a, int n);
void swap(int *a, int *b);
void printvet(int *v, int n)
{
    int i;
    for (i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}
int main (int argc, char *argv[])
{
    clock_t t;
    time_t timer;
    srand(time(NULL));
    if (argc < 2){ printf ("Entre com o tamanho do vetor\n"); return 1;}
    int tmp,i,j, r, n = atoi(argv[1]);
    int *v = (int*)malloc(n*sizeof(int));
    for (i = 0; i < n; i++){
        r = rand()%n;
        v[i] = r;
    }
    t = clock();
	quickk(v,n);
    printf ("%f time \n",t,((float)t)/CLOCKS_PER_SEC);
    for(i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    return 0;
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void quickk (int *a, int n) {
    int i, j, p, t;
    if (n < 2)
        return;
    p = a[n / 2];
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
		swap(&a[i], &a[j]);
    }
    quickk(a, i);
    quickk(a + i, n - i);
}