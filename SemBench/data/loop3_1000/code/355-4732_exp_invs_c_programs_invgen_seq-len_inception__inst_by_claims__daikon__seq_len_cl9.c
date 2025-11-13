#include <assert.h>
int main() {
  int n0 = 1;
  int n1 = 1;
  int n2 = 1;
  int i = 0;
  int k = 0;
  while( i < n0 ) {
    i=1;
    k=1;
  }
  i = 0;
  while( i < n1 ) {
    i=1;
    k=2;
  }
  i = 0;
  while( i < n2 ) {
    i=1;
    k=3;
  }
  i = 0;
  while( i < n2 ) {
    i=1;
    k=2;
  }
  i = 0;
  while( i < n1 ) {
    i=1;
    k=1;
  }
  i = 0;
  while( i < n0 ) {
    i++;
    k--;
  }
  return 0;
}