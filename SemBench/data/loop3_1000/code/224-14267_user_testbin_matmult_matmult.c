#include <unistd.h>
#include <stdio.h>
#define Dim 	72	
#define RIGHT  8772192		
int A[Dim][Dim];
int B[Dim][Dim];
int C[Dim][Dim];
int T[Dim][Dim][Dim];
int
main()
{
    int i, j, k, r;
    for (i = 0; i < Dim; i++)		
	for (j = 0; j < Dim; j++) {
	     A[i][j] = i;
	     B[i][j] = j;
	     C[i][j] = 0;
	}
    for (i = 0; i < Dim; i++)		
	for (j = 0; j < Dim; j++)
            for (k = 0; k < Dim; k++)
		T[i][j][k] = A[i][k] * B[k][j];
    for (i = 0; i < Dim; i++)
	for (j = 0; j < Dim; j++)
            for (k = 0; k < Dim; k++)
		C[i][j] += T[i][j][k];
    r = 0;
    for (i = 0; i < Dim; i++)
	    r += C[i][i];
    printf("matmult finished.\n");
    printf("answer is: %d (should be %d)\n", r, RIGHT);
    if (r != RIGHT) {
	    printf("FAILED\n");
	    return 1;
    }
    printf("Passed.\n");
    return 0;
}