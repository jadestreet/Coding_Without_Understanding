#include <stdlib.h>
#include <stdio.h>
int main (int argc, char **argv)
{
  for ( int i = 0; i < 10; i++ ) {
    printf("%d\n", i );
  }
  printf ( "\n" );
  for ( int i = 0; i < 10; i++ ) 
    printf("%d\n", i );
  printf ( "\n" );
  for ( int i = 0; i < 10; i++ ) printf("%d\n", i );
  return (EXIT_SUCCESS);
}