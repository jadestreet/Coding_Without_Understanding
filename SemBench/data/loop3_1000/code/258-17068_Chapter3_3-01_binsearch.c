#include <stdio.h>
#include <time.h>
#define MASSIVE_SIZE 1000000
int binsearch(int x, int v[], int n) {
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high)/2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
int binsearch_alt(int x, int v[], int n) {
	int low, high, mid;
	low = 0;
	high = n-1;
	while(low < high) {
		mid = (low + high) / 2;
		if(x <= v[mid])
			high = mid;
		else
			low = mid+1;
	}
	return (x == v[low]) ? low : -1;
}
int main (void) {
	clock_t timer;
	int pos = 0;
	int i;
	int v[MASSIVE_SIZE] = {0};
	for (i = 0; i < MASSIVE_SIZE; ++i)
		v[i] = i;
	timer = clock();
	for (i = 0; i < MASSIVE_SIZE; ++i) {
		pos = binsearch(-1, v, MASSIVE_SIZE);
	}
	timer = clock() - timer;
	printf("originl results:\n\ttimer: %lu clocks or %lu seconds\n", timer, timer/CLOCKS_PER_SEC);
	timer = clock();
	for (i = 0; i < MASSIVE_SIZE; ++i) {
		pos = binsearch_alt(-1, v, MASSIVE_SIZE);
	}
	timer = clock() - timer;
	printf("alternative results:\n\ttimer: %lu clocks or %lu seconds\n", timer, timer/CLOCKS_PER_SEC);
	return 0;
}