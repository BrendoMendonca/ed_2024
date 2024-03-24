#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct nod{
    int info;
    struct no* ant;
    struct no* prox;
};

struct listad{
    struct nod* inicio;
    struct nod* fim;
};

typedef struct nod Nod;
typedef struct listad Listad;

Nod* cria_no(int info){

    Nod* no = (Nod*) malloc(sizeof(Nod));
    if(!no)
        return NULL;
    no->ant = NULL;
    no->prox = NULL;
    no->info = info;
    return no;
}

Listad* cria_lista(){
    Listad* l = (Listad*) malloc(sizeof(Listad));
    if(!l)
        return NULL;
    
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

bool insere_inicio(Listad* l, int info){
    if(!l)
        return NULL;
    Nod* no = cria_no(info);
    if(!no)
        return NULL;
    if(l->inicio == NULL){
        l->inicio = no;
        l->fim = no;
        return true;
    }
    l->inicio->ant = no;
    no->prox = l->inicio;
    l->inicio = no;
    return true;
}

bool insere_fim(Listad* l, int info){
    if(!l)
        return NULL;
    
    Nod* novo = cria_no(info);
    if(!novo)
        return NULL;
    if(l->fim == NULL){
        l->inicio = novo;
        l->fim = novo;
        return true;
    }
    novo->ant = l->fim;
    l->fim->prox = novo;
    l->fim = novo;
    return true;    
}