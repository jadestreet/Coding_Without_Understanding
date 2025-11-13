#include <stdio.h>
#include <stdlib.h>
int main() {
  int *deck = (int *)malloc(52 * sizeof(int)) ;
  int *outdeck = (int *)malloc(52 * sizeof(int)) ;
  int i;
  srand(123);
  printf("\n");
  for (i =0; i < 52; i++) {
    deck[i] = i ;
    printf("%d ", deck[i]);
  }
  printf("\n");
  int len = 52;
  int j;
  for (i =0; i < 52; i++) {
    int deckIdx = rand() %  len;
    outdeck[ i ] = deck[deckIdx];
    for (j = deckIdx+1; j < len; j++) {
      deck[j-1] = deck[j];
    }
    len--;
  }
  printf("\n naive");
  for (i =0; i < 52; i++) {
    printf("%d ", outdeck[i]);
  }
}