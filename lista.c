/*Funções usando lista encadeada*/
#ifndef _lista_c_
#define _lista_c_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>   
#include "lista.h"

struct no{ //estrutura de tipo nó representando os elementos da lista
    int info;//inteiro que contém a informação guardada do nó
    struct no* prox;//ponteiro do tipo nó que aponta para o próximo nó
};

struct lista{//estrutura de tipo lista que armazena os elementos(nós)
    struct no* inicio;//ponteiro do tipo nó que sempre aponta para o primeiro elemento da lista
};


No* cria_no(int info){//função para criar nós
    No* n = (No*) malloc(sizeof(No));//alocação dinamica do nó
    if(!n)//verifica se foi alocado
        return NULL;
    n->info = info;//recebimento da informação de acordo com o parâmetro passado
    n->prox = NULL;//o nó aponta para NULL como próximo elemento
    return n;//retorna o nó criado
}

Lista* cria_lista(){//função para criar lista
    Lista* l = (Lista*) malloc(sizeof(Lista));//alocação dinâmica da lista
    if(!l)//verifica se foi alocado
        return NULL;
    l->inicio = NULL;//l->inicio é o primeiro nó da lista e inicialmente está vazio(NULL)
    return l;
}

bool insere_inicio(Lista* l, int info){//função para inserir nó no início da lista
    if(!l)//verifica se a lista é válida
        return NULL;
    No* n = cria_no(info);//criação de um novo nó para ser adicionado à lista
    if(!n)
        return NULL;
    //o nó n será o novo primeiro elemento, então o próximo dele será o antigo primeiro elemento
    n->prox = l->inicio;
    l->inicio = n;
    return true;
}

bool insere_fim(Lista* l, int info){//função para inserir nó no fim da lista
    if(!l)//verifica se a lista é válida
        return NULL;

    No* aux = l->inicio;//um nó auxiliar é criado para percorrer a lista
    while(aux->prox != NULL)//o nó auxiliar percorre a lista até o próximo elemento que ele se encontra for NULL, ou seja, até chegar até o último elemento da lista
        aux = aux->prox;
    
    aux->prox = cria_no(info);//quando o nó auxiliar chega no último elemento da lista, o próx dele aponta para um novo nó que será o novo último nó da lista
    return(aux->prox != NULL);
}

bool remove_inicio(Lista* l){//função para remover nó no início da lista
    if(!l)//verifica se a lista passada como parâmetro é válida
        return NULL;
    if(l->inicio == NULL)//verifica se a lista está vazia
        return false;
    No* aux = l->inicio->prox; //nó auxiliar para armazenar o elemento que será o novo início da lista
    free(l->inicio);//libera o antigo primeiro elemento da lista
    l->inicio = aux;//o primeiro elemento da lista recebe os dados do antigo segundo elemento da lista
    return true;
}

bool remove_fim(Lista *l){//função para remover o nó no fim da lista
    if(!l)//verifica se a lista passada como parâmetro é válida
        return NULL;
    if(l->inicio == NULL)//verifica se a lista está vazia
        return false;
    if(l->inicio->prox == NULL)//verifica se só tem um elemento na lista
        return false;
    No* aux = l->inicio;//nó auxiliar criado para percorrer a lista
    while(aux->prox->prox != NULL)//o nó auxiliar percorre a lista até o penúltimo elemento da lista
        aux = aux->prox;
    free(aux->prox);//remove o último elemento da lista
    aux->prox = NULL;//o antipenúltimo elemento aponta para NULL, o tornando o novo último elemento da lista
    return true;
}

No* busca_no(Lista* l, int info){//função que retorna um nó específico de acordo com a informação contida no nó
    if(!l)//verifica se a lista é válida
        return NULL;
    No* aux = l->inicio;//nó auxiliar para percorrer a lista
    while(aux != NULL)//percorre a lista até o fim ou até o elemento ser encontrado
        if(aux->info == info)//se o valor do nó corresponder com o valor do parâmetro, o nó é retornado
            return aux;
        aux = aux->prox;
    return NULL;//caso contrário, NULL é retornado
}

void imprime_lista(Lista* l){//função para imprimir a lista
    if(!l)//verifica se a lista é válida
        return;
    No* aux = l->inicio;//nó auxiliar para percorrer a lista
    while(aux != NULL){//o nó auxiliar percorre a lista até o fim imprimindo cada elemento
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}



bool modifica_info(Lista* l, int info, int nova_info){//função para modificar a informação de um nó
    No* aux = busca_no(l, info);//nó auxiliar recebe o retorno da função de busca, ou seja, recebe o nó que possui o valor que será alterado
    if(aux == NULL)
        return false;
    aux->info = nova_info;//atribuição da nova informação ao nó
    return true;
}

void libera_lista(Lista** l){//função para liberar a lista da memória
    if(!(*l))//verifica se a lista é válida
        return;
    while((*l)->inicio != NULL)//percorre a lista até o fim para eliminar todo os nós
        remove_inicio(*l);//função de remoção no início
    free(*l);
    *l = NULL;
}

#endif