#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "pilha.h"

int main(){

    Pilha* p1 = cria_pilha();
    push(p1, 2);
    push(p1, 4);
    push(p1, 6);
    push(p1, 8);

    Pilha* p2 = cria_pilha();
    push(p2, 1);
    push(p2, 3);
    push(p2, 5);
    push(p2, 7);
    
    imprime_pilha(p1);

    pop(p1);
    imprime_pilha(p1);

    printf("Topo da pilha 1: %d", topo(p1));

    concatena_pilhas(p1, p2);
    printf("Pilha 1 concatenada:");
    imprime_pilha(p1);
    
    Pilha* p3 = copia_pilha(p1);
    printf("p3, copia de p1:\n");
    imprime_pilha(p3);
    
    return 0;
}