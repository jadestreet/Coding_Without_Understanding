#include "stdio.h"
#include "stdlib.h"
struct TNo {
  struct TNo *ant;
  int numero;
  struct TNo *prox;
};
struct TLista {
  struct TNo *primeiro;
  int quantidade;
  struct TNo *ultimo;
};
typedef struct TLista TLista;
typedef struct TNo TNo;
int vazia (TNo *pLista) {
  if (pLista == NULL) {
    return 1;
  } else {
    return 0;
  }
}
TNo *incluiCabeca (TNo *pLista, int pValor) {
  TNo *pNovoNo;
  pNovoNo = (TNo*) malloc(sizeof(TNo));
  pNovoNo->numero = pValor;
  pNovoNo->ant = NULL;
  if (!vazia(pLista)) {
    pNovoNo->prox = pLista;
    pLista->ant = pNovoNo;
    pLista = pNovoNo;
    return pLista;
  }
  pNovoNo->prox = NULL;
  return pNovoNo;
}
TNo *incluiCalda (TNo *pLista, int pValor) {
  TNo *pNovoNo, *pAux;
  pNovoNo = (TNo*) malloc(sizeof(TNo));
  pNovoNo->numero = pValor;
  pNovoNo->prox = NULL;
  pAux = pLista;
  while (pAux->prox != NULL) {
    pAux = pAux->prox;
  }
  pAux->prox = pNovoNo;
  pNovoNo->ant = pAux;
  return pLista;
}
TNo *incluiChave (TNo *pLista, int pChave, int pValor) {
  TNo *pNovoNo, *pAux;
  pNovoNo = (TNo*) malloc(sizeof(TNo));
  pNovoNo->numero = pValor;
  pAux = pLista;
  while (pAux->prox->numero != pChave) {
    pAux = pAux->prox;
  }
  pNovoNo->prox = pAux->prox;
  pNovoNo->ant = pAux;
  pAux->prox = pNovoNo;
  pNovoNo->prox->ant = pNovoNo;
  return pLista;
}
TNo *excluiCabeca (TNo *pLista) {
  pLista = pLista->prox;
  free(pLista->ant);
  pLista->ant = NULL;
  return pLista;
}
TNo *excluiCalda (TNo *pLista) {
  TNo *pAux;
  pAux = pLista;
  while (pAux->prox->prox != NULL) {
    pAux = pAux->prox;
  }
  free(pAux->prox);
  pAux->prox = NULL;
  return pLista;
}
TNo *excluiChave (TNo *pLista, int pChave) {
  TNo *pAux;
  pAux = pLista;
  while (pAux->numero != pChave) {
    pAux = pAux->prox;
  }
  pAux->ant->prox = pAux->prox;
  pAux->prox->ant = pAux->ant;
  free(pAux);
  return pLista;
}
void imprimeLista (TNo *pLista) {
  TNo *pAux;
  int posicao = 0;
  pAux = pLista;
  while (pAux != NULL) {
    printf("TNo[%d] = %d\n", posicao, pAux->numero);
    posicao++;
    pAux = pAux->prox;
  }
  return;
}
int main(int argc, char const *argv[]) {
  TNo *pLista;
  pLista = NULL;
  pLista = incluiCabeca(pLista, 2);
  pLista = incluiCabeca(pLista, 3);
  pLista = incluiCabeca(pLista, 4);
  pLista = incluiCabeca(pLista, 8);
  pLista = incluiCabeca(pLista, 10);
  pLista = incluiCabeca(pLista, 12);
  imprimeLista(pLista);
  printf("\n\n");
  pLista = incluiCalda(pLista, 0);
  pLista = incluiCalda(pLista, -1);
  pLista = incluiCalda(pLista, -3);
  imprimeLista(pLista);
  printf("\n\n");
  pLista = incluiChave(pLista, 0, 1);
  imprimeLista(pLista);
  printf("\n\n");
  pLista = excluiCabeca(pLista);
  imprimeLista(pLista);
  printf("\n\n");
  pLista = excluiCalda(pLista);
  imprimeLista(pLista);
  printf("\n\n");
  pLista = excluiChave(pLista, 3);
  imprimeLista(pLista);
  printf("\n");
  return 0;
}