#include <assert.h>
int main() {
  int n0 = -1073741824;
  int n1 = 1;
  int n2 = 1;
  int i = 0;
  int k = 0;
  while( i < n0 ) {
    i++;
    k++;
  }
  i = 0;
  while( i < n1 ) {
    i=1;
    k=1;
  }
  i = 0;
  while( i < n2 ) {
    i=1;
    k=2;
  }
  i = 0;
  while( i < n2 ) {
    i=1;
    k=1;
  }
  i = 0;
  while( i < n1 ) {
    i++;
    k--;
  }
  i = 0;
  while( i < n0 ) {
    i++;
    k--;
  }
  return 0;
}