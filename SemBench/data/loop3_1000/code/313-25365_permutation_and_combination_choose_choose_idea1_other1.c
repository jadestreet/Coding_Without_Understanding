int choose(int n, int k) {
    int ans = 1;
    int i;
    for(i=n; i>=(n-k+1); --i)
        ans *= i;
    while(k)
        ans /= k--;
    return ans;
}
#include<stdio.h>
int main() {
    int n,k;
    for(n=0; n<10; n++) {
        for(k=0; k<=n; k++) {
            printf(" %d",choose(n,k));
        }
        printf("\n");
    }
    return 0;
}