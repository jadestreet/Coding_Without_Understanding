#include <stdio.h>
int main01(void)
{
	FILE *p = fopen("D:\\temp\\a.txt", "r");
	if (p == NULL) {
		printf("error\n");
	} else {
		char c = 0;
		while ((c = getc(p)) != EOF) {
			printf("%c", c);
		}
		fclose(p);
	}
	return 0;
}
int main02(void)
{
	FILE *p = fopen("D:\\temp\\a.txt", "w");
	if (p == NULL) {
		printf("error\n");
	} else {
		putc('a', p);
		putc('b', p);
		putc('c', p);
		fclose(p);
	}
	return 0;
}
#define SEC 5
int main03(void)
{
	FILE *p = fopen("D:\\temp\\a.txt", "r");
	FILE *p1 = fopen("D:\\temp\\b.txt", "w");
	if (p == NULL) {
		printf("error\n");
	} else {
		char c = 0;
		while ((c = getc(p)) != EOF) {
			c += SEC;
			putc(c, p1);
		}
		fclose(p);
		fclose(p1);
	}
	return 0;
}
int main(void)
{
	FILE *p = fopen("D:\\temp\\b.txt", "r");
	FILE *p1 = fopen("D:\\temp\\c.txt", "w");
	if (p == NULL) {
		printf("error\n");
	} else {
		char c = 0;
		while ((c = getc(p)) != EOF) {
			c -= SEC;
			putc(c, p1);
		}
		fclose(p);
		fclose(p1);
	}
	return 0;
}