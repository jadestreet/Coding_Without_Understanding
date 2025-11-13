#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void clear_line ( char * line, int len );
int main ( int argc, char * argv [] ) {
    char numeric = 0;
    char pos_1 = 0;
    char c = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    char tmp_line [ 100 ];
    while ( argc > 0 ) {
        printf ( "============================================\n" );
        printf ( "* ( * ( argv + i ) ) = %c;\n",* ( * ( argv + i ) ) );
        while ( argc > 0 && ( c = * ( * ( argv + i ) ) ) == '-' ) {
            c = * ( * ( argv + i ) + 1 );
            switch ( c ) {
                case 'n':
                    numeric = 1;
                    printf ( "numeric = 1;\n" );
                    break;
                default:
                    if ( isdigit ( c ) ) {
                        printf ( "Yahooo!!! It's digit! ))\n" );
                        j = 0;
                        k = 0;
                        clear_line ( tmp_line, 5 );
                        while ( isdigit ( c = * ( ( * argv ) + j ) ) && c != '\0' && c != '\n' ) {
                            tmp_line [ k ] = c;
                            printf ( "tmp_line [ %d ] = %c;\n", k, tmp_line [ k ] );
                            k ++;
                            j ++;
                        }
                        tmp_line [ k ] = '\0';
                        pos_1 = atoi ( tmp_line );
                        printf ( "getted pos_1 = %d;\n", pos_1 );
                    }
                    else {
                        printf ( "wrong parameter;\n" );                                                                                                                
                        argc = 0;                                                                                                                                       
                    }
                    break;                                                                                                                                          
            }                                                                                                                                                       
            i ++;
            argc --;
            printf ( "in second while i = %d; argc = %d; * ( argv + %d ) = %s;\n", i, argc, i, * ( argv + i ) );
            printf ( "----------------------\n" );
        }
        printf ( "after ( while c == '-' ) i = %d;", i);
        printf ( " argc = %d;", argc );
        printf ( " * argv = %s;\n", * argv );
        if ( argc > 0 ) { 
            i ++;
            argc --;
        }
    }
    return 0;
}
void clear_line ( char * line, int len ) {
    int i = 0;
    for ( i = 0; i < len; i ++ ) {
        * ( line + i ) = '\0';
    }
}