#include <stdio.h>
#include <stdlib.h>
int comparator(const void *a, const void *b){
	int f = *(int *)a;
	int s = *(int *)b;
	return f-s; 
}
int main(int argc, char *argv[]){
	int a[] = {4, 5, 2, 6, 1};
	int size = sizeof(a)/sizeof(a[0]);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	int count = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = i+1; j < size; ++j)
		{
			if(a[i] > a[j])
				count++;
		}
	}
	printf("\nThe number of inversion parirs are %d\n", count);
	printf("\n");
	return 0;
}