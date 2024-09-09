#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int valor;
    int chave;
    struct no *prox;
}no;

void inserefilaenc(no *novo, no **inicio, no **fim){
    if((*fim)!=NULL){
        (*(*fim)).prox=novo;
    }
    else{
        (*inicio)=novo;
    }
    (*fim)=novo;
}

no *removefilaenc(no **inicio, no **fim){
    no *remove1=NULL;
    if((*inicio)!=NULL){
        remove1=(*inicio);
        (*inicio)=(*(*inicio)).prox;
        if(inicio==NULL){
            (*fim)=NULL;
        }
    }
    return remove1;
}

int main(){

    no *inicio=NULL;
    no *fim=NULL;


    int x=0;
    do{
        printf("\nDigite o caso: ");
        scanf("%d", &x);
        switch(x){

            case 1:
                break;
            
            case 2://Inserção
                no *novo=malloc(sizeof(no));
                printf("\nChave do novo no: ");
                scanf("%d", &(*novo).chave);
                inserefilaenc(novo,&inicio,&fim);
                printf("\nRetorno: %d", (*fim).chave);
                break;

            case 3://Remoção
                no *retornera = removefilaenc(&inicio,&fim);
                if (retornera == NULL) {
                    printf("\nNulo");
                } else {
                    printf("\nRemovido: %d", (*retornera).chave);
                    
                }
                break;
        }
    }while(x!=0);
    
    no *i=inicio;
    while(i!=(*fim).prox){
        printf(" %d", (*i).chave);
        i=(*i).prox;
    }
    printf("\n");

    return 0;
}