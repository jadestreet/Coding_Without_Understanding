#include <stdio.h>
#include <string.h>
void print_matrix(const char *name, int mat[3][3])
{
	printf("Matriz %s;\n", name);
	for (int i = 0; i < 3; i++) {
		printf("  ");
		for (int j = 0; j < 3; j++)
			printf("%04d ", mat[i][j]);
		printf("\n");
	}
	printf("\n\n");
}
void scalar_product(int mat[3][3], float factor)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			mat[i][j] = (int) (mat[i][j] * factor);
}
void vector_product(int a[3][3], int b[3][3], int result[3][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int result_i_j = 0;
			printf("calculando el valor de la celda result[%d][%d]...\n",
				i, j);
			for (int k = 0; k < 3; k++)
				result_i_j += a[k][j] * b[i][k];
			result[i][j] = result_i_j;
		}
	}
}
int main(void)
{
	int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int B[3][3] = {{11, 12, 13}, {14, 15, 16}, {17, 18, 19} };
	int C[3][3];
	print_matrix("A inicialmente", A);
	print_matrix("B inicialmente", B);
	scalar_product(A, 2);
	scalar_product(B, 2);
	print_matrix("A = A * 2", A);
	print_matrix("B = B * 2", B);
	vector_product(A, B, C);
	print_matrix("A x B", C);
	return 0;
}