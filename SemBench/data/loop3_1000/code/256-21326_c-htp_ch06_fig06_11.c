#include <stdio.h>
#define ARR_SIZE 3
void staticArrayInit(void);
void automaticArrayInit(void);
int main(void)
{
	staticArrayInit();
	staticArrayInit();
	automaticArrayInit();
	automaticArrayInit();
	return 0;
}
void staticArrayInit(void)
{
	static int arr1[ARR_SIZE];
	int i;
	for (i = 0; i < ARR_SIZE; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (i = 0; i < ARR_SIZE; i++) {
		arr1[i] = arr1[i] + 5;
		printf("%d ", arr1[i]);
	}
	printf("\n");
}
void automaticArrayInit(void)
{
	int arr2[ARR_SIZE] = {1, 2, 3};
	int i;
	for (i = 0; i < ARR_SIZE; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");
	for (i = 0; i < ARR_SIZE; i++) {
		arr2[i] = arr2[i] + 5;
		printf("%d ", arr2[i]);
	}
	printf("\n");
}