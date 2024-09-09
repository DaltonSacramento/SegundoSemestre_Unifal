#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

typedef struct no{
    int valor;
    int chave;
    int tamanho;
    struct no *prox;
}no;

no *buscapilha(int chave, no **topo){
    no *aux=(*topo);
    while(aux!=NULL){
        if((*aux).chave==chave){
            return aux;
        }
        aux=(*aux).prox;
    }
    return NULL;
}

void push(no *novo, no **topo){
    (*novo).prox=(*topo);
    (*topo)=novo;
}

no *pop(no **topo){
    no *remove1=NULL;
    if((*topo)!=NULL){
        remove1=(*topo);
        (*topo)=(*(*topo)).prox;
    }
    return remove1;
}

int main(){

    no *topo=NULL;



    int x=0;
    do{
        printf("\nDigite o caso: ");
        scanf("%d", &x);
        switch(x){

            case 1://Busca
                int z;
                printf("\nChave para buscar: ");
                scanf("%d", &z);
                no *retorno=buscapilha(z,&topo);
                if(retorno==NULL){
                    printf("\nChave não encontrada");
                }
                else{
                    printf("\nChave encontrada: %d", (*retorno).chave);
                }      
                break;
            
            case 2://Inserção
                no *novo=malloc(sizeof(no));
                printf("\nChave do novo no: ");
                scanf("%d", &(*novo).chave);
                push(novo,&topo);
                printf("\nInserido: %d", (*topo).chave);
                break;

            case 3://Remoção
                no *retornera = pop(&topo);
                if (retornera == NULL) {
                    printf("\nPilha vazia");
                } else {
                    printf("\nRemovido: %d", (*retornera).chave);
                    
                }
                break;
        }
    }while(x!=0);

    no *i=topo;
    while(i!=NULL){
        printf(" %d", (*i).chave);
        i=(*i).prox;
    }
    printf("\n");


    return 0;
}