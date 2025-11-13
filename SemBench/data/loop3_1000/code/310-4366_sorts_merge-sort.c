#include <stdio.h>
void merge(int A[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int left[n1 + 1];
	int right[n2 + 1];
	for (int i = 0; i < n1; i++)
		left[i] = A[p + i];
	for (int i = 0; i < n2; i++)
		right[i] = A[q + i + 1];
	left[n1] = 2147483647;
	right[n2] = 2147483647;
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++) {
		if (left[i] <= right[j]) {
			A[k] = left[i];
			i++;
		}
		else {
			A[k] = right[j];
			j++;
		}
	}
}
void merge_sort(int A[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}
int main(void)
{
	int A[] = {5,0,2,4,5,7,1,6,3,6,2,9};
	int n = sizeof(A) / sizeof(int);
	merge_sort(A, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d", A[i]);
	printf("\n");
	return 0;
}