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


#endif