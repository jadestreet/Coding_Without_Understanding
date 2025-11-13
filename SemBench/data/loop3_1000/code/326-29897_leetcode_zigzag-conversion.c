#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char* convert(char* s, int numRows) {
    if(numRows <= 1)
        return s;
    int len = strlen(s);
    char *ans = (char*)malloc(sizeof(char)*(len+1));
    int i=0;
    int j=0;
    int k=0;
    int m = (numRows-1)<<1;
    for(i=0; i<len; i+=m)
        ans[j++] = s[i];
    for(i=1; i<numRows-1; i++){
        int x = i*2;
        for(k=i; k<len; k+=x){
            ans[j++] = s[k];
            x = m-x;
        }
    }
    for(i=numRows-1; i<len; i+=m){
        ans[j++] = s[i];
    }
    ans[j] = 0;
    return ans;
}
int main ( int argc, char *argv[] )
{
    printf ( "%s\n", convert("ABC", 3) );
    return 0;
}				