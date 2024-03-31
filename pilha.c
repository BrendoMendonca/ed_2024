#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define  TAM 10

struct elemento{
    int info;
    struct elemento* prox;
};

struct pilha{
    struct elemento* topo;
    int tamanho;
};

typedef struct elemento Elemento;
typedef struct pilha Pilha;

Elemento* cria_elemento(int info){
    Elemento* e = (Elemento*) malloc(sizeof(Elemento));
    if(!e)
        return NULL;
    e->info = info;
    e->prox = NULL;
    return e;
}

Pilha* cria_pilha(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if(!p)
        return NULL;
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

bool pilha_vazia(Pilha* p){
    if(!p)
        return false;
    return (p->tamanho == 0);
}

bool pilha_cheia(Pilha* p){
    if(!p)
        return false;
    return (p->tamanho == TAM);
}

bool push(Pilha* p, int info){
    if(!p)
        return false;
    if(pilha_cheia(p))
        return false;
    
    Elemento* e = cria_elemento(info);
    if(!e)
        return false;

    e->prox = p->topo;
    p->topo = e;
    p->tamanho+=1;     
    return true;
    
}

bool pop(Pilha* p){
    if(!p)
        return false;
    if(pilha_vazia(p))
        return false;
    Elemento* aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
    return true;
}

void libera_pilha(Pilha** p){
    if(!(*p))
        return;

    Elemento* aux = (*p)->topo;
    while((*p)->topo != NULL){
        pop(*p);
    }
    free(*p);
    *p = NULL;
}

void imprime_pilha(Pilha* p){
    if(!p)
        return;
    Elemento* aux = p->topo;
    while(aux != NULL){
        printf("%d \n", aux->info);
        aux = aux->prox;
    }
}

int topo(Pilha* p){
    if(!p)
        return;
    if(pilha_vazia(p))
        return;
    
    return p->topo->info;    
}

void concatena_pilhas(Pilha* p1, Pilha* p2){
    if(!p1 || !p2)
        return;
    if(pilha_vazia(p2))
        return;
    Elemento* aux = p2->topo;
    while(aux->prox != NULL)
        aux = aux->prox;
    aux->prox = p1->topo;
    p1->topo = p2->topo;
    p2->topo = NULL;

    p1->tamanho += p2->tamanho;
    p2->tamanho = 0;
}

Pilha* copia_pilha(Pilha* p){
    if(!p)
        return NULL;
    Pilha* p_aux = cria_pilha();
    Elemento* aux = p->topo;
    while(aux != NULL){
        push(p_aux, aux->info);
        aux = aux->prox;
    }
    Pilha* p_copia = cria_pilha();
    aux = p_aux->topo;
    while(aux != NULL){
        push(p_copia, aux->info);
        aux = aux->prox;
    }
    libera_pilha(&p_aux);
    return p_copia;
}