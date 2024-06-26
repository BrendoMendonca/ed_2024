#ifndef _lista_h_
#define _lista_h_

typedef struct no No;
typedef struct lista Lista;

No* cria_no(int info);
Lista* cria_lista();
bool insere_inicio(Lista* l, int info);
bool insere_fim(Lista* l, int info);
bool remove_inicio(Lista *l);
bool remove_fim(Lista *l);
No* busca_no(Lista* l, int info);
bool modifica_info(Lista* l, int info, int nova_info);
void imprime_lista(Lista* l);
void libera_lista(Lista** l);
int comprimento(Lista* l);
int maiores (Lista* l, int x);
int ultimo(Lista* l);
void concatena(Lista* l1, Lista* l2);
void retira_n (Lista* l, int x);
Lista* separa(Lista* l, int x);
Lista* merge (Lista* l1 , Lista* l2 );
void inverte(Lista* l);
Lista* copia(Lista* l);
void para_circular (Lista* l);
void imprime_circular(Lista* l);
void retira_inicio ( Lista* l);
void retira_final (Lista* l);

#endif