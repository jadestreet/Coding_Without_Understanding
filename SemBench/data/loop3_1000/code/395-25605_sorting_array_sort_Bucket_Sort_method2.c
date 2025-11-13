#include<stdio.h>
#define N 100
int main() {
    int a[6]= {3,2,4,2,3,5};
    int b[N];
    int i;
    for(i=0; i<N; i++) {
        b[i]=0;
    }
    for(i=0; i<6; i++) {
        b[a[i]]++;
    }
    for(i=0; i<N; i++) {
        while(b[i]>0) {
		printf(" %d",i);
		b[i]--;
	}
    }
    printf("\n");
    return 0;
}