#include <stdio.h>
void selection_sort(int A[], int n) {
	for (int i = 0; i < n; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[min_index]) {
				min_index = j;
			}
		}
		int temp = A[i];
		A[i] = A[min_index];
		A[min_index] = temp;
	}
}
int main(void)
{
	int A[] = {-2, 12, 1, 3, 4, 22, 432, 423423, 3};
	int n = sizeof(A) / sizeof(int);
	selection_sort(A, n);
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
	return 0;
}