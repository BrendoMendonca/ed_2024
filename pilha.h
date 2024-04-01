#ifndef _pilha_h_
#define _pilha_h

typedef struct elemento Elemento;
typedef struct pilha Pilha;

Elemento* cria_elemento(int info);
Pilha* cria_pilha();
bool pilha_vazia(Pilha* p);
bool pilha_cheia(Pilha* p);
bool push(Pilha* p, int info);
bool pop(Pilha* p);
void libera_pilha(Pilha** p);
void imprime_pilha(Pilha* p);
int topo(Pilha* p);
void concatena_pilhas(Pilha* p1, Pilha* p2);
Pilha* copia_pilha(Pilha* p);

#endif