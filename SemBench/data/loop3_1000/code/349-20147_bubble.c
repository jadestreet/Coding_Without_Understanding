#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    for (i = n; i > 0; i--){
        for (j = 1; j < i; j++){
            if(v[j-1] > v[j]){
                tmp = v[j-1];
                v[j-1] = v[j];
                v[j] = tmp;
            }
        }
    }
    printf ("%f time \n",t,((float)t)/CLOCKS_PER_SEC);
    return 0;
}