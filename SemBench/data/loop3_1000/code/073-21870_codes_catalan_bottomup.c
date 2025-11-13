#include <stdio.h>
#include <stdlib.h>
long int catalanDP(int n){
    int i;
    long int catalan[n+1];
    catalan[0] = catalan[1] = 1;
    for (int i=2; i<=n; i++){
        catalan[i] = 0;
        for (int j=0; j<i; j++)
            catalan[i] += catalan[j] * catalan[i-j-1];
    }
    return catalan[n];
}
int main(int argc, char **argv){
    int i;
    int count = atoi(argv[1]) + 1;
    for (i = 0; i < count; i++)
        printf("%ld ", catalanDP(i));
    return 0;
}