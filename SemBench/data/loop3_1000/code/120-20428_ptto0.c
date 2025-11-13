#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    int sz;
    char **pca; 
} ca_t;
typedef struct 
{
    int sz;
    ca_t **c; 
} aca_t;
void reall_pca(ca_t *c)
{
    c->sz=10;
    (*c->pca)=realloc((*c->pca), c->sz*sizeof(char));
    return;
}
void prt_aca(aca_t *ac)
{
    int i, j;
    for(i=0;i<ac->sz;++i) {
        printf("ac#%i: ", i);
        for(j=0;j<(*ac->c)[i].sz;j++)
            printf("%c ", (*(*ac->c)[i].pca)[j]);
        printf("\n"); 
    }
    return;
}
void assign_c(ca_t *c)
{
    int j;
    c->sz = 5;
    c->pca = malloc(sizeof(char*));
    (*c->pca) = malloc(c->sz*sizeof(char));
    for(j=0;j<c->sz;j++)
        (*c->pca)[j] =(char)(j+65);
    return;
}
int main(int argc, char *argv[])
{
    int i, j;
    aca_t *ac=malloc(sizeof(aca_t));
    ac->sz=3;
    ac->c=malloc(sizeof(ca_t*));
    (*ac->c)=malloc(ac->sz*sizeof(ca_t));
    for(i=0;i<ac->sz;++i) {
        assign_c((*ac->c)+i);
    }
    prt_aca(ac);
    for(i=0;i<ac->sz;++i) {
        free((*(*ac->c)[i].pca));
        free((*ac->c)[i].pca);
    }
    free((*ac->c));
    free(ac->c);
    free(ac);
    return 0;
}