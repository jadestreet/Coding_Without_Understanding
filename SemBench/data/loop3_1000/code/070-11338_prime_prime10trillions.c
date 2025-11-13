#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define ARRAY_SIZE_MAX   (100000000)
#define MAX_N (10000000000000)
char    array[ARRAY_SIZE_MAX];
long long primelistcount;
long long *primelist;
int initprimelist( void );
long long isqrt( long long x );
int main( int ac, char *av[] )
{
    long long base, arraysize, n, i, j, prev;
    if( !initprimelist() )
        return( 0 );
    prev = 0;
    for( base = 2; base < MAX_N; base += ARRAY_SIZE_MAX ) {
        if( MAX_N - base + 1 > ARRAY_SIZE_MAX )
            arraysize = ARRAY_SIZE_MAX;
        else
            arraysize = MAX_N - base + 1;
        for( i = 0; i < arraysize; i++ )
            array[i] = 1;
        for( i = 0; i < primelistcount; i++ ) {
            n = primelist[i];
            if( base <= n )
                j = n;
            else if( base % n == 0 )
                j = base;
            else
                j = ( base / n + 1 ) * n;
            j = j < n * n ? n * n : j;
            for( ; j < base + arraysize; j += n )
                array[j - base] = 0;
        }
        for( n = 0; n < arraysize; n++ ) {
            if( array[n] == 1 ) {
                printf( "%lld\n", base + n - prev );
                prev = base + n;
            }
        }
    }
    return( 0 );
}
int initprimelist( void )
{
    long long n, i;
    long long sqrt_llong_max;
    sqrt_llong_max = isqrt( MAX_N );
    for( i = 0; i <= sqrt_llong_max; i++ )
        array[i] = 1;
    for( n = 2; n <= sqrt_llong_max; n++ ) {
        if( array[n] == 1 ) {
            for( i = n * n; i <= sqrt_llong_max; i+=n ) {
                array[i] = 0;
            }
        }
    }
    primelistcount = 0;
    for( n = 2; n <= sqrt_llong_max; n++ ) {
        if( array[n] == 1 )
            primelistcount++;
    }
    primelist = calloc( primelistcount, sizeof(long long) );
    if( primelist == NULL )
        return( 0 );
    for( n = 2, i = 0; n <= sqrt_llong_max; n++ ) {
        if( array[n] == 1 )
            primelist[i++] = n;
    }
    return( 1 );
}
long long isqrt( long long x )
{
    long long s, t;
    if( x == 0 ) return 0;
    s = 1;
    t = x;
    while( s < t ) {
        s <<= 1;
        t >>= 1;
    }
    do {
        t = s;
        s = ( x / s + s ) >> 1;
    } while( s < t );
    return( t );
}