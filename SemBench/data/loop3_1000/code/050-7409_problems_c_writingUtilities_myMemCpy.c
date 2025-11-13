#include <stdio.h>
int mymemcpy(unsigned int *wdst, unsigned int *wsrc, int words)
{
	int i;
	if ((wsrc + words > wdst) && (wsrc < wdst)) {
		for (i = words-1; i>=0; i--) {
			*(wdst + i) = *(wsrc + i);
		}
	} else {
		for (i = 0 ; i <words ; i++) {
			*(wdst + i) = *(wsrc + i);
		}
	}
	printf("\n");
	return 0;
}
int mymemcmp(unsigned int *wdst, unsigned int *wsrc, int words)
{
	int i;
	for (i=0; i < words; i++) {
		if (*(wdst+i) != *(wsrc+i)) {
			return (*(wdst+i) - *(wsrc+i));
		}
	}
	return 0;
}
#define MAXSIZE 4096
unsigned int original[MAXSIZE], myarray[MAXSIZE];
void initialize()
{
	int i;
	for (i=0; i<MAXSIZE; i++) {
		original[i] = myarray[i] = i;
	}
}
void printArray(unsigned int *arr, int words)
{
	int i;
	printf("Position %p\n", arr);
	for (i=0; i<words; i++) {
		printf("%4d", *(arr+i));
	}
	printf("\n");
}
int main(int argc, char **argv)
{
	int i;
	initialize();
	mymemcpy(myarray, myarray+100, 50);
	if (mymemcmp(myarray, original+100, 50) == 0) {
		printf("Case 1: Copy success\n");
	} else {
		printf("Case 1: Copy failure.\n");
	}
	initialize();
	mymemcpy(myarray, myarray+100, 200);
	if (mymemcmp(myarray, original+100, 200) == 0) {
		printf("Case 2: Copy success\n");
	} else {
		printf("Case 2: Copy failure.\n");
	}
	initialize();
	mymemcpy(myarray+100, myarray, 200);
	if (mymemcmp(myarray+100, original, 200) == 0) {
		printf("Case 3: Copy success\n");
	} else {
		printf("Case 3: Copy failure.\n");
	}
}