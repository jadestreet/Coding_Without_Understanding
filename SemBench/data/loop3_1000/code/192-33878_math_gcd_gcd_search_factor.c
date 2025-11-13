#include<stdio.h>
#define MAX 100
int main() {
	int i;
	int a=54;
	for(i=1;i<=a;i++) {
		if (a % i == 0) {
			printf(" %d",i);
		}
	}
	printf("\n");
	int b=24;
	for(i=1;i<=b;i++) {
		if (b % i == 0) {
			printf(" %d",i);
		}
	}
	printf("\n");
	int factor[MAX];
	int factors=0;
	for(i=1;i<=b || i<=a;i++) {
		if (a % i == 0 && b % i == 0) {
			printf(" %d",i);
			if (factors>=MAX) {
				printf("两个整数公因数的个数超过了预设的值%d\n",MAX);
				printf("请修改MAX的值来达到你的要求\n");
				return 1;
			}
			factor[factors]=i;
			factors++;
		}
	}
	printf("\n");
	for(i=0;i<factors;i++) {
			printf(" %d",factor[i]);
	}
	printf("\n");
	printf("gcd(%d,%d)=%d\n",a,b,factor[factors-1]);
	return 0;
}