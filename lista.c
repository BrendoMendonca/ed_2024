/*Funções usando lista encadeada*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>   

struct no{
    int info;
    struct no* prox;
};

struct lista{
    struct no* inicio;
};

typedef struct no No;
typedef struct lista Lista;

No* cria_no(int info){
    No* n = (No*) malloc(sizeof(No));
    if(!n)
        return NULL;
    n->info = info;
    n->prox = NULL;
    return n;    
}

Lista* cria_lista(){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    if(!l)
        return NULL;
    l->inicio = NULL;
    return l;
}

bool insere_inicio(Lista* l, int info){
    if(!l)
        return NULL;
    No* n = cria_no(info);
    if(!n)
        return NULL;
    n->prox = l->inicio;
    l->inicio = n;
    return true;
}

bool insere_fim(Lista* l, int info){
    if(!l)
        return NULL;

    No* aux = l->inicio;
    while(aux->prox != NULL)
        aux = aux->prox;
    
    aux->prox = cria_no(info);
    return(aux->prox != NULL);
}

bool remove_inicio(Lista* l){
    if(!l)
        return NULL;
    if(l->inicio == NULL)
        return false;
    No* aux = l->inicio->prox;
    free(l->inicio);
    l->inicio = aux;
    return true;
}

bool remove_fim(Lista *l){
    if(!l)
        return NULL;
    if(l->inicio == NULL)
        return false;
    if(l->inicio->prox == NULL)
        return false;
    No* aux = l->inicio;
    while(aux->prox->prox != NULL)
        aux = aux->prox;
    free(aux->prox);
    aux->prox = NULL;
    return true;
}

No* busca_no(Lista* l, int info){
    if(!l)
        return NULL;
    No* aux = l->inicio;
    while(aux != NULL)
        if(aux->info == info)
            return aux;
        aux = aux->prox;
    return NULL;
}

void imprime_lista(Lista* l){
    if(!l)
        return NULL;
    No* aux = l->inicio;
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}

bool modifica_info(Lista* l, int info, int nova_info){
    if(!l)
        return NULL;
    No* aux = busca_no(l, info);
    if(aux == NULL)
        return false;
    aux->info = nova_info;
    return true;
}

void libera_lista(Lista** l){
    if(!(*l))
        return;
    while((*l)->inicio != NULL)
        remove_inicio(*l);
    free(*l);
    *l = NULL;
}