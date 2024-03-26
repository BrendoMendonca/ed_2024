#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

int main(){

    Lista* l = cria_lista();
    insere_inicio(l, 5);
    insere_inicio(l, 3);
    insere_inicio(l, 14);
    insere_fim(l ,21);
    insere_inicio(l ,83);
    insere_fim(l ,81);

    imprime_lista(l);
    printf("\nTamanho da lista: %d\n", comprimento(l));
 
    return 0;
}