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


    imprime_lista(l1);
    printf("\n");
    imprime_lista(l2);
    printf("\nTamanho da lista 1: %d\n", comprimento(l1));
    printf("\nTamanho da lista 2: %d\n", comprimento(l2));
   
    //imprime_lista(merge(l1, l2)); 

    inverte(l1);
    printf("\n");
    imprime_lista(l1);

    copia(l1);
    printf("\ncopia da lista:\n");
    imprime_lista(l1);
 
    return 0;
}