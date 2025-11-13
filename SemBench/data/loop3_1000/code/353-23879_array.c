#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int main() {
    int n[SIZE];
    int j;
    int total;
    for (j=0; j<SIZE; j++) {
        n[j]=2+2*j;
    }
    for (j=0; j<SIZE; j++) {
        total+=n[j];
    }
    printf("%s%13s\n","Elemento","Valor");
    for (j=0; j<SIZE; j++) {
        printf("%8d%13d\n",j,n[j]);
    }
    printf("%8s%13d\n","Total",total);
    return EXIT_SUCCESS;
}