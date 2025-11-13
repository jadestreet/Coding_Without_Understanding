#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct csr_t {
    int  n;      
    double* pr;  
    int* col;    
    int* ptr;    
} csr_t;
void sparse_multiply(csr_t* A, double* x, double* result)
{
    memset(result, 0, A->n * sizeof(double));
    int i,j;
    for(i = 0;i < A->n;i++) {
        for(j =A->ptr[i];j < A->ptr[i+1];j++) {
            result[i] += A->pr[j]*x[A->col[j]];
        }
    }
} 
int main()
{
    int n = 4;
    double pr[7]  = { 1.,-1.,  1.,-1.,  1.,-1.,  1. };
    int col[7]    = { 0,  1,   1,  2,   2,  3,   3  };
    int ptr[5]    = { 0, 2, 4, 6, 7 };
    csr_t A = { n, pr, col, ptr };
    double x[4] = {1., 3., 8., 12.};
    double result[4];
    sparse_multiply(&A, x, result);
    for (int i = 0; i < n; ++i)
        printf(" %g\n", result[i]);
}