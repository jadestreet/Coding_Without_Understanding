#include <stdio.h>
#define TABINC 8
int main( int argc, char *argv[ ] ) {
  FILE *in, *out;
  in = fopen( "output.dat", "r" );
  if ( in == NULL ) {
    perror( "output.dat" );
    return 1;
  }
  out = fopen( "input.dat", "w" );
  if ( out == NULL ) {
    perror( "input.dat" );
    return 1;
  }
  char ch; 
  int nb; 
  int nt; 
  int pos; 
  nb = 0;
  nt = 0;
  for ( pos = 0; (ch = fgetc( in )) != EOF; pos++ ) {
    if ( ch == ' ' ) {
      if ( pos % TABINC != 0 ) {
	nb++; 
      } else {
	nb = 0; 
	nt++;
      }
    } else {
      while ( nt > 0 ) {
	fputc( '\t', out ); 
	nt--;
      }
      if ( ch == '\t' ) {
	nb = 0; 
      } else {
	while ( nb > 0 ) {
	  fputc( ' ', out );
	  nb--;
	}
      }
      fputc( ch, out );
      if ( ch == '\n' ) {
	pos = 0;
      } else if ( ch == '\t' ) {
	pos = pos + ( TABINC - pos % TABINC ) - 1;
      }
    }
  }
  fclose( in );
  fclose( out );
  return 0;
}