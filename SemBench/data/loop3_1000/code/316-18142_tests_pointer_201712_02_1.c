#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main ( int argc, char * argv [] ) {
    int i = 0;
    int j = 0;
    int k = 0;
    char c = 0;
    char tmp_line [ 100 ];
    printf ( "* ++ argv [ 0 ] = %c;\n", * ++ argv [ 0 ] );
    while ( argc > 0 ) {
        printf ( "* argv [ %d ] = %s;\n", i, * argv  );
        if ( strcmp ( * argv, "123" ) == 0 ) {
            printf ( "Found!!! * argv = 123;\n" );
        }
        if ( * * argv == '1' ) {
            while ( isdigit ( c = * ( ( * argv ) + j ) ) && c != '\0' && c != '\n' ) {
                printf ( "in while c = %c;\n", c );
                j ++;
            }
            if ( c == '\0' || c == '\n' ) {
                printf ( "getted number from string '%s' = %d;\n", * argv, atoi ( * argv ) );
            }
        }
        else {
            if ( * * argv == '-' ) {
                k = 0;
                j = 1;
                while ( isdigit ( c = * ( ( * argv ) + j ) ) && c != '\0' && c != '\n' ) {
                    tmp_line [ k ] = c;
                    printf ( "tmp_line [ %d ] = %c; c = %c;\n", k, tmp_line [ k ], c );
                    j ++;
                    k ++;
                }
                tmp_line [ k ] = '\0';
                printf ( "string after - = %d as digit and %s as string;\n", atoi ( tmp_line ), tmp_line );
            }
        }
        argc --;
        i ++;
        * argv ++;    
    }
    return 0;
}