#ifndef _lista_dup_h_
#define _lista_dup_h_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nod Nod;
typedef struct listad Listad;

Nod* cria_no(int info);
Listad* cria_lista();
bool insere_inicio(Listad* l, int info);
bool insere_fim(Listad* l, int info);
void retira_inicio(Listad* l);
void retira_final(Listad* l);
void imprime_lista_dup(Listad* l);

#endif