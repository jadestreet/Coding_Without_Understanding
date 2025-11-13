#include <stdio.h>
int main ( int argc, char * argv [] ) {
    int i = 0;
    int j = 2;
    while ( i < argc ) {
        printf ( "i = %d; ", i );
        printf ( "argv [ %d ] = %s;\n", i, argv [ i ] );
        i ++;
    }
    i = 0;
    while ( i < argc ) {
        printf ( "* ( argv + %d ) = %s;\n", i, * ( argv + i ) );
        printf ( "* ( ( argv + %d ) + %d ) = %c;\n", i, j, * ( ( argv + i ) + j ) );
        i ++;        
    }
    while ( argc > 0 ) {
        printf ( "argc = %d;", argc );
        printf ( " i = %d;", i );
        printf ( " * argv = %s;", * argv );
        printf ( " argv [ %d ] = %s;", i, argv [ i ] );
        printf ( "\n" );
        i ++;
        argc --;    
        * argv ++;
    }
    return 0;
}