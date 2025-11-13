#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define SD 10
#define NUMS 20
#define BITS 4
#define BITS2 3
#define P ((1L<<BITS)-1) 
#define P2 ((1L<<BITS2)-1) 
int main(void)
{
    setlocale(LC_NUMERIC, "");
    srand(SD);
    int i;
    int *NA=malloc(NUMS*sizeof(int));
    int *NA2=malloc(NUMS*sizeof(int));
    float *FA=malloc(NUMS*sizeof(float));
    for(i=0;i<NUMS;++i) {
        NA[i]=rand(); 
        NA[i] &= (0xff<<24); 
        NA[i] >>= 24; 
        NA[i] &= P;
        NA[i] -= 1L<<(BITS-1); 
        FA[i]= (float)NA[i]/(float)P;
        FA[i] *= 2.0;
        FA[i] -= 1.0;
    }
    for(i=0;i<NUMS;++i)
        printf("%i ", NA[i]);
    printf("\n"); 
    for(i=0;i<NUMS;++i) 
        printf("%6.4f ", FA[i]);
    printf("\n"); 
    for(i=0;i<NUMS;++i) {
        NA2[i] = NA[i]>>(BITS-BITS2);
        FA[i]= (float)NA2[i]/(float)P2;
        FA[i] *= 2.0;
        FA[i] -= 1.0;
    }
    for(i=0;i<NUMS;++i) 
        printf("%i ", NA2[i]);
    printf("\n"); 
    for(i=0;i<NUMS;++i) 
        printf("%6.4f ", FA[i]);
    printf("\n"); 
    free(NA2);
    free(NA);
    free(FA);
    return 0;
}