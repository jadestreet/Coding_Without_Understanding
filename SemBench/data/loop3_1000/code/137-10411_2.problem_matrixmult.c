#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     
# define N 1000         
typedef unsigned long int long_int;
int main(int argc, char *argv[]){
    long_int ** A = (long_int **) malloc( N * sizeof(long_int *) );
    long_int ** B = (long_int **) malloc( N * sizeof(long_int *) );
    long_int ** C = (long_int **) malloc( N * sizeof(long_int *) );
    for(int i=0; i<N; ++i){
        A[i] = (long_int *) malloc( N * sizeof(long_int *) );
        B[i] = (long_int *) malloc( N * sizeof(long_int *) );
        C[i] = (long_int *) malloc( N * sizeof(long_int *) );
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            A[i][j] = B[i][j] = 1;
            C[i][j] = 0;           
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    char validation[10];
    strcpy(validation,"Ok");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if( C[i][j] != N) strcpy(validation, "Fail");
        }
    }
    printf ( "\t%d \t\t\t %s \t\t ", N, validation );
    for(int i=0; i<N; ++i){
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
    return EXIT_SUCCESS;
};