#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista_dup.h"

int main(){

    Listad* ld1 = cria_lista();
    insere_inicio(ld1, 2);
    insere_inicio(ld1, 4);
    insere_inicio(ld1, 6);
    insere_fim(ld1, 8);

    retira_final(ld1);
    retira_inicio(ld1);

    imprime_lista_dup(ld1);

    return 0;
}