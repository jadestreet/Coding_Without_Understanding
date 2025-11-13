#include <stdio.h>
#include <stdlib.h>
typedef struct no {
	int valor;
	struct no *prox;	
}No;
typedef struct no Lista;
void newList(Lista **l) {
	*l = NULL;
}
void add(Lista **l, int valor) {
	No *no;
	if ( !(no = malloc(sizeof(No))) ) {
		printf("Error in function add\n");
		return;
	} else {
		no->valor 	= valor;
		no->prox 	= *l;
		*l		 	= no;
	}
}
void addSort(Lista **l, int valor) {
	No *aux = *l, *ant = NULL, *no = NULL;
	if ( !(no = malloc(sizeof(No))) ) {
		printf("Error in function addSort\n");
		return; 
	} else {
		no->valor = valor;
	}
	while (aux != NULL && valor > aux->valor ) {
		ant = aux;
		aux = aux->prox;
	}
	if (ant == NULL) {
		no->prox = *l;
		*l		 = no;
	} else {
		ant->prox = no;
		no->prox  = aux;
	}
}
char empty(Lista **l) {
	return *l == NULL;
}
void toRemove(Lista **l, int valor) {
	No *aux = *l, *ant = NULL;
	while (aux != NULL && aux->valor != valor) {
		ant = aux;
		aux = aux->prox;
	}
	if (!ant) 
		*l = (*l)->prox;
	else if (aux != NULL) 
		ant->prox = aux->prox;
	free(aux);	
}
void toRemoveR(Lista **l, int valor) {
	if (*l != NULL ) toRemoveR(&(*l)->prox, valor);
	if ( *l != NULL && (*l)->valor == valor)	printf("%d", (*l)->valor);
}
void freeList(Lista **l) {
	if (!empty(l)) {
		freeList(&(*l)->prox);
		free(*l);
	}		
}
void viewList(Lista **l) {
	if (!empty(l)) {
		viewList(&(*l)->prox);
		printf("%2d", (*l)->valor);
	}
}
void viewListSort(Lista **l) {
	for (No *i = *l; i != NULL; i = i->prox)
		printf("%2d", i->valor);
}
int main() {
	Lista *p;
	newList(&p);
	add(&p, 3);
	add(&p, 5);
	add(&p, 1);
	add(&p, 2);
	add(&p, 4);
	add(&p, 6);
	toRemoveR(&p, 3);
	return 0;
}