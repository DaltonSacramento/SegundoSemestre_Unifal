#include <stdlib.h>
#include <stdio.h>
#include "encadeada.h"


int main(){

    
    /*
    printf("\nTamanho: ");
    scanf("%d", &num_elementos);
    */
    
    //Declaração do no cabeça e dos ponteiros posicionais
    //Começando com NULL
    no *ptlista=malloc(sizeof(no));
    (*ptlista).prox=NULL;
    no *ant=NULL;
    no *pont=NULL;
    
    /*
    no *ultimo = ptlista;
    for (int i = 1; i <= num_elementos; i++) {  
        no *novo=malloc(sizeof(no));
        novo->chave = i;
        novo->prox = NULL;
        ultimo->prox = novo;
        ultimo = novo;
    }
    no *ptr = ptlista->prox;
    while (ptr != NULL) {
        printf(" %d", ptr->chave);
        ptr = ptr->prox;
    }
    */
    /*
    for(int i=2;i<=num_elementos;i++){
        (*(ptlista + i)).chave=i;
    }
    for(int i=1;i<=num_elementos;i++){
        printf(" %d", (*(ptlista + i)).chave);
    }
    */


    int x=0;
    do{
        printf("\nDigite o caso: ");
        scanf("%d", &x);
        switch(x){

            case 1://Busca
                printf("\nChave: ");
                scanf("%d", &x);
                no *retorno=buscaenc(x,&ant,&pont,ptlista);
                if(retorno==NULL){
                    printf("\nNulo");
                }
                else{
                    printf("\nRetorno: %d", (*retorno).chave);
                }
                break;
            
            case 2://Inserção
                no *aux=malloc(sizeof(no));
                printf("\nNova estrutura: ");
                printf("\nChave: ");
                scanf("%d", &(*aux).chave);
                printf("\nRetorno: %d", insereenc(aux,&ant,&pont,ptlista));
                break;

            case 3://Remoção
                int w;
                printf("\nChave para remover: ");
                scanf("%d", &w);
                no *retornera = removeenc(w,&ant,&pont,ptlista);
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