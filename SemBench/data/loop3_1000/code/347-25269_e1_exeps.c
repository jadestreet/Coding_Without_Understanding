#include <stdio.h>
#define BN_MAXLEN 60
#define TO_NUM 30
#define FROM_NUM 13
typedef struct BigNumber{
    char d[BN_MAXLEN]; 
    int len;    
}BN;
void bPrint( BN n ){
    if (n.len > 0)
    {
        int i = n.len - 1;
        while ( 0 <= i ){
            printf("%c",n.d[i]);
            i--;
        }
    }else if ( 0 == n.len){
        printf("[0]");
    }else{
        printf("[error]");
    }
}
BN bNew( unsigned int i ){
    int k;
    BN n;
    n.len = 0;
    for (k = 0; k<BN_MAXLEN ; k++ )
    {
        n.d[k] = '0';
    }
    while (i > 0 && n.len <= BN_MAXLEN)
    {
        n.len ++;
        n.d[n.len-1] = (char)( i%10 + '0');
        i = i/10;
    }
    return n;
}
void bSetD( BN *b, int i, char c){
    if (i >= BN_MAXLEN ) {
        printf("[error] set digits out of range %d", i );
        return;
    }
    if (b->len <= i)
        b->len = i+1;
    b->d[i] = c;
}
BN bAdd( BN a, BN b){
    BN sum = bNew(0);
    int i = 0;
    int x,y;
    int s;      
    int c = 0 ; 
    while ( i<a.len || i< b.len)
    {
        x = (i<a.len)? (int) (a.d[i] - '0'):0;
        y = (i<b.len)? (int) (b.d[i] - '0'):0;
        c = (int) (sum.d[i]-'0');
        s = x + y + c;
        if ( s > 9){
            c = s/10;
            s %= 10;
        }else {
            c = 0;
        }
        bSetD( &sum, i, s+'0');
        if (c>0)
            bSetD( &sum, i+1, c+'0');
        i++;
    }
    return sum;
}
BN bMul( BN a, BN b){
    BN p = bNew(0);   
    BN tmp  = bNew(0);
    int i,j;
    int x,y;
    int s,c;
    for ( j = 0 ; j< b.len ; j++)
    {
        y = (int)b.d[j] - '0';      
        tmp = bNew(0);
        c = 0;
        for ( i = 0; i < a.len; i++ )       
        {
            x = (int)(a.d[i] - '0');
            c = (int)(tmp.d[i+j]-'0');
            s = x * y + c; 
            if ( s > 9){
                c = s / 10;
                s %= 10;
            }else {
                c = 0;
            }
            bSetD( &tmp, i+j, s + '0' );
            if (c>0)
                bSetD( &tmp, i+j+1, c + '0' );
        }
        p = bAdd( tmp, p );     
    }
    return p;
}
int main(int argc, char * argv[])
{
    int i = 2;
    BN fac = bNew(1);
    for ( i=2; i<=TO_NUM; i++ )
    {
        BN m = bNew(i);
        fac = bMul(fac, m);
        if (i>=FROM_NUM){      
            printf("%d!= ",i);
            bPrint( fac);
            printf("\n");
        }
    }
    return 0;
}