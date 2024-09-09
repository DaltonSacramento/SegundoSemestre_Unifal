#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"


int main(){

    noArvore *raiz=NULL;

    int x;
    do{
        printf("\nDigite a opção: ");
        scanf("%d", &x);
        switch(x){
            case 1://Insere
                noArvore *n=malloc(sizeof(noArvore));
                (*n).esq=NULL;
                (*n).dir=NULL;
                printf("\nDigite o valor do novo no: ");
                scanf("%d", &(*n).valor);
                raiz=insere(&raiz,n);
                break;

            case 2:
                int k;
                printf("\nChave para buscar: ");
                scanf("%d", &k);
                noArvore *retornera=busca(raiz,k);
                if(retornera!=NULL){
                    printf("\nRetornera: %d", (*retornera).valor);
                }
                break;

            case 3:
                int z;
                printf("\nValor para remover: ");
                scanf("%d", &z);
                noArvore *retornado=removeNo(raiz,z);
                if(retornado!=NULL){
                    printf("\nRetornado: %d", (*retornado).valor);
                }
                break;
        }
    }while(x!=0);

    emordem(raiz);

    return 0;
}