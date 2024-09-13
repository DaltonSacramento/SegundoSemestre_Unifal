#include <stdlib.h>
#include <stdio.h>
#include "encadeada.h"


int main(){

    
    //Declaração do no cabeça e dos ponteiros posicionais
    //Começando com NULL
    no *ptlista=malloc(sizeof(no));
    (*ptlista).post=ptlista;
    (*ptlista).ant=ptlista;
    //no *pont=NULL;
    


    int x=0;
    do{
        printf("\nDigite o caso: ");
        scanf("%d", &x);
        switch(x){

            case 1://Busca
                int k;
                printf("\nChave para buscar: ");
                scanf("%d", &k);
                no *retornoBLDE=buscaListaDE(ptlista,k);
                printf("\nRetorno: %d", (*retornoBLDE).chave);
                break;
            
            case 2://Inserção
                no *aux=malloc(sizeof(no));
                printf("\nNova estrutura: ");
                printf("\nChave: ");
                scanf("%d", &(*aux).chave);
                no *retornoILDE=insereListaDE(ptlista,aux);
                if(retornoILDE==NULL){
                    printf("\nInserido");
                }
                else{
                    printf("\nNao inserido, retorno posterior: %d", (*retornoILDE).chave);
                }
                break;

            case 3://Remoção
                int w;
                printf("\nChave para remover: ");
                scanf("%d", &w);
                no *retornera = removeListaDE(ptlista,w);
                if (retornera == NULL) {
                    printf("\nNulo");
                } else {
                    printf("\nRemovido: %d", (*retornera).chave);
                    
                }
                break;
        }
    }while(x!=0);

    for(no *i=(*ptlista).post;i!=ptlista;){
        printf(" %d", (*i).chave);
        i=(*i).post;
    }
    
    return 0;
}