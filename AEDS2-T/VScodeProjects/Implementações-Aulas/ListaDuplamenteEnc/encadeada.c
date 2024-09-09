#include <stdlib.h>
#include <stdio.h>
#include "encadeada.h"


int main(){

    
    //Declaração do no cabeça e dos ponteiros posicionais
    //Começando com NULL
    no *ptlista=malloc(sizeof(no));
    (*ptlista).prox=NULL;
    //no *pont=NULL;
    


    int x=0;
    do{
        printf("\nDigite o caso: ");
        scanf("%d", &x);
        switch(x){

            case 1://Busca
            /*
                printf("\nChave: ");
                scanf("%d", &x);
                no *retorno=buscaenc(x,ptlista);
                if(retorno==NULL){
                    printf("\nNulo");
                }
                else{
                    printf("\nRetorno: %d", (*retorno).chave);
                }
                break;*/
            
            case 2://Inserção
                no *aux=malloc(sizeof(no));
                printf("\nNova estrutura: ");
                printf("\nChave: ");
                scanf("%d", &(*aux).chave);
                printf("\nRetorno: %d", insereenc(aux,ptlista));
                break;

            case 3://Remoção
                int w;
                printf("\nChave para remover: ");
                scanf("%d", &w);
                no *retornera = removeenc(x,ptlista);
                if (retornera == NULL) {
                    printf("\nNulo");
                } else {
                    printf("\nRemovido: %d", (*retornera).chave);
                    
                }
                break;
        }
    }while(x!=0);

    escrita(ptlista);
    
    return 0;
}