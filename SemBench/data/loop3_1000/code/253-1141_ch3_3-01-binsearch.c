#include <stdio.h>
#include <time.h>
int binsearch_one_test(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
	mid = (low + high) / 2;
    while (low <= high && v[mid] != x) {
        mid = (low + high) / 2;
        if (x <= v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (v[mid] == x) {
        return mid;
    } else {
        return -1;
    }
}
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}
int main()
{
	int i;
    int v[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = 10;
	clock_t begin, end;
	double runtime;
	begin = clock();
	for (i = 0; i < n; i++) {
		printf("expected: %d, actual: %d\n", i, binsearch_one_test((i + 1) * 10, v, n));
	}
	end = clock();
	runtime = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("time: %lf\n", runtime);
	begin = clock();
	for (i = 0; i < n; i++) {
		printf("expected: %d, actual: %d\n", i, binsearch((i + 1) * 10, v, n));
	}
	end = clock();
	runtime = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("time: %lf\n", runtime);
    return 0;
}