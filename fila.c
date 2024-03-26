#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define _TAM_ 40
struct fila{
    int info[_TAM_];
    int inicio;
    int n;
};

typedef struct fila Fila;

Fila* cria_fila(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if(!f)
        return NULL;
    f->inicio = -1;
    f->n = 0;
    return f;
}

int tamanho_fila(Fila* f){
    if(!f)
        return -1;
    return f->n;    
}

bool esta_cheia(Fila* f){
    if(!f)
        return false;
    return (f->n == _TAM_);
}

bool esta_vazia(Fila* f){
    if(!f)
        return false;
    return(f->n == 0);
}

bool insere(Fila* f, int info){
    if(!f)
        return false;
    if(f->n == _TAM_)
        return false;

    f->inicio ++;

    if(f->inicio == _TAM_)
        f->inicio = 0;
    
    f->info[f->inicio] = info;
    f->n++;
    return true;
}

bool retira(Fila* f, int* info){
    if(!f || !info)
        return false;
    int pos = f->inicio - f->n+1;
    if (pos < 0)
        pos += f->n;
    *info = f->info[pos];
    f->n--;
    return true;
}