#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct  Pilha  {
	int num ;
	struct Pilha* prox;
			  };
			  
struct Lista_Pilha {		
	
	struct Pilha* Topo;
	int size;
					};
					

typedef  struct Pilha  	Pilha;	
typedef struct  Lista_Pilha  Lista_Pilha; 					
//////////////////////

#define  Tam 10

//////////////

Pilha*  Cria_No( int a )			{
	
  Pilha* p = (Pilha*)malloc(sizeof(Pilha));
  
  if(!p)  { return NULL ; }
  //////////////
  
  p -> num = a;
  p -> prox = NULL;
  ////////////////
  
  return p;															}
  									
 /////////////////////////
  									
  Lista_Pilha*	Cria_Lista_Pilha()  {
  	
    Lista_Pilha* L = (Lista_Pilha*)malloc( sizeof( Lista_Pilha));
    
    if(!L)  { return NULL ;}
    ///////////////
    
    L -> Topo = NULL;
    L -> size = 0;
    
    ///////////
    return L;						}
    
   ///////////////////////////
    
  
   bool Pilha_Vazia( Lista_Pilha* L){
  	
  	if(!L)  { return false; }
  	///////
  	
  	return ( L -> size  == 0);		}
  	////////////////////////
  	
  	
  	//////////////////////////////
  	bool Pilha_cheia( Lista_Pilha* L)     {
  		
  	 if(!L)  { return false; }
  	///////
  	
  	/////////////////////////
  	return ( L -> size == Tam );	}
  	
  	//////////////////////////////
  	
  	int  Topo_Pilha( Lista_Pilha* L){
  		
  		if(!L)  { return false; }
  		
  		if(!( L -> Topo ) )       {
  			puts("Pilha Vazia");
  			return -1;
  								}
  		//////////////////
  	
  		return  L -> Topo -> num;
  									             }					
  	
  	/////////////////////////
    bool  Insere_Pilha( Lista_Pilha* L, int info )				  {
    	
    	if(!L)  {return false; }
    	
    	Pilha* Novo = Cria_No(info);
    	
    	if(!Novo)  return  false;
    	Novo -> prox = L -> Topo;    	
    	L -> Topo = Novo;	
    	L -> size += 1;
    	
    	return true;
    							   }		  														
  	////////////////////////
  bool  Remove_Pilha( Lista_Pilha* L, int* p_int)					{
  	
  	if(!L)  {return false; }
  	
  	if( L -> Topo ==  NULL )      {
  		puts("Lista vazia");
  		return false;
  									}
  	///////////////////////////////
  	
  	*p_int = L -> Topo -> num;
  	///////////
  									
  	Pilha* aux =  L -> Topo;
  	L -> Topo =  L -> Topo -> prox;
  	
   free(aux);
  	//////////	
  		L -> size -= 1;						
  									return true; 	}
  									
  									
  									
  	/////////////////////	
 void Libera_Geral( Lista_Pilha** L){
 	
 	if(!(*L))  {return ;}
 	
 	if( !( (*L) -> Topo ) )       {
 		
 		free(*L);
 		return;
  								}
  	/////////////////////
  								
  	Pilha* aux	=(*L) -> Topo	;	
  									
    while( aux != NULL )          {
    	
     (*L ) -> Topo = (*L ) -> Topo -> prox;
     
     free(aux);
     aux = (*L) -> Topo ;
     
     							}
     free(*L);
     /////////////
     							  }							
   ////////////////////////
  void  Imprime( Lista_Pilha* L)   {
  	
  	if(!L)  {return;}
  	
  	
  	  							   
  	  Pilha*  aux = L -> Topo;		/////////				   
  	  
  	  while(aux != NULL )          {
  	  	
  	  	printf("%d \n", aux -> num);
  	  	aux = aux -> prox;
  	  						    	
  	  	                          }
  	  		return;				  }
  	  /////////////////////