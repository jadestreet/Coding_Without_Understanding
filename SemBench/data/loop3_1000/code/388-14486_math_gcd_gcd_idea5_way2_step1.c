#include<stdio.h>
#include<math.h>
int gcd(int a,int b) {
    if(a<0) {
        a=-a;
    }
    if(b<0) {
        b=-b;
    }
    if(a==0) { return b;}
    if(b==0) { return a;}
    int d=0;
    int pow2d=1;
    while (a%2==0 && b%2==0) {
        a=a>>1;
        b=b>>1;
        d=d+1;
	pow2d=pow2d<<1;
    }
    while(a!=b) {
        if(a%2==0) { a=a>>1;
	}
        else if(b%2==0) { b=b>>1;
	}
        else if(a>b) { a=((a-b)>>1);
	}
        else {
		b=((b-a)>>1);
	}
    }
    int g=a;
    return g*pow2d;
}
int main() {
    int i,j;
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            printf("%2d",gcd(i,j));
        }
        printf("\n");
    }
    return 0;
}