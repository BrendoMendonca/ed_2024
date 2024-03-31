#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

int main(){

    Lista* l1 = cria_lista();
    insere_inicio(l1, 5);
    insere_inicio(l1, 3);
    insere_inicio(l1, 14);
    insere_fim(l1 ,21);
    insere_inicio(l1 ,83);
    insere_fim(l1 ,81);

    Lista* l2 = cria_lista();
    insere_inicio(l2, 7);
    insere_inicio(l2, 6);
    insere_inicio(l2, 4);
    
    printf("\nLista 1:\n");
    imprime_lista(l1);

    printf("\nLista 2:\n");
    imprime_lista(l2);

    concatena(l1, l2);
    printf("\nLista concatenada:\n");
    imprime_lista(l1);
    
    l2 = separa(l1, 3);
    printf("\nLista 2:\n");
    imprime_lista(l2);

    printf("\nLista 1 separada:\n");
    imprime_lista(l1);
    
    Lista* l3 = merge(l1, l2);
    printf("\nLista 3:\n");
    imprime_lista(l3);

    inverte(l3);
    printf("\nLista 3 invertida:\n");
    imprime_lista(l3);

    return 0;
}