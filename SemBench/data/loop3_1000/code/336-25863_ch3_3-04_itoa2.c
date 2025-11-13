#include <stdio.h>
#include <string.h>
#include <limits.h>
void reverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
void itoa(int n, char s[]) {
	int i, sign, min; 
	if ((sign = n) < 0) {
		if (n == INT_MIN) {
			n += 1;
			min = 1;
		}
		n = -n;
	}
	i = 0;
	do {
		if (i == 0 && min == 1) {
			s[i++] = n % 10 + '1';
		} else {
			s[i++] = n % 10 + '0';
		}
	} while ((n /= 10) > 0);
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}
int main() {
	int tests[5] = {INT_MIN, INT_MAX, -300, 172, 38478235};
	char st[101] = "";
	int i;
	for (i = 0; i < 5; i++) {
		itoa(tests[i], st);
		printf("%12d in string form is %12s\n", tests[i], st);
	}
	return 0;
}