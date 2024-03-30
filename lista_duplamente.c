#ifndef _lista_duplamente_c_
#define _lista_duplamente_c_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>   
#include "lista.h"

struct nod{
    int info;
    struct nod* ant;
    struct nod* prox;
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
        return false;
    Nod* no = cria_no(info);
    if(!no)
        return false;
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
        return false;
    Nod* novo = cria_no(info);
    if(!novo)
        return false;
    
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

void retira_inicio(Listad* l){
    if(!l || l->inicio == NULL)
        return;
    if(l->inicio->prox == NULL){
        l->inicio = NULL;
        l->fim = NULL;
    }
    else{
        Nod* aux = l->inicio->prox;        
        l->inicio = aux;
        l->inicio->ant = NULL;
        free(aux);
    }
}

void retira_final(Listad* l){
    if(!l || l->inicio == NULL)
        return;
    if(l->inicio == l->fim){
        l->inicio = NULL;
        l->fim = NULL;
    }
    else{
        Nod* aux = l->fim;        
        l->fim = l->fim->ant;
        l->fim->prox = NULL;
        free(aux);
    }
}

#endif