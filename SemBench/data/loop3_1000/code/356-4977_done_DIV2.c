#include <stdio.h>
#include <string.h>
int d[1000001];
int b[1000001];
int main () {
	int i, j, k;
	memset(b, 0, sizeof(b));
	d[1] = 1;
	for (i = 2; i <= 1000000; i++)
		d[i] = 2;
	for (i = 2; i <= 1000; i++) {
		j = i * i;
		d[j]++;
		for (j += i; j <= 1000000; j += i)
			d[j] += 2;
	}
	for (i = 2; i <= 1000000; i++)
		for (j = i*2; j <= 1000000; j += i)
			if (d[j] % d[i])
				b[j] = 1;
	k = 0;
	for (i = 1; i <= 1000000; i++) {
		if ((b[i] == 0) && (d[i] > 3)) {
			k++;
			if (k % 108 == 0)
				printf("%d\n", i);
		}
	}
	return 0;
}