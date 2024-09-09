#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int chave;
    int valor;
    struct no *prox;//Ponteiro de no numa struct no
}no;

/*Busca encadeada*/
no *buscaenc(int x,no **ant,no **pont, no *ptlista){
    *ant=ptlista;
    *pont=NULL;
    no *ptr=(*ptlista).prox;
    //Condição se o vetor for nulo, *ptr=primeiro no
    while(ptr!=NULL){
        //Se ptr->chave < chavebuscada, ptr aponta para o prox no
        if((*ptr).chave<x){
            *ant=ptr;
            ptr=(*ptr).prox;
        }
        else{
            //se ptr==x pont retorna o no buscado
            if((*ptr).chave==x){
                *pont=ptr;
                return (*pont);
            }
            else break;
        }
    }
    return (*pont);
}

int insereenc(no *aux, no **ant, no **pont, no *ptlista){
    int insere1=-1;
    no *returnado=buscaenc((*aux).chave,ant,pont,ptlista);
    if(returnado==NULL){
        (*aux).prox=(*(*ant)).prox;
        (*(*ant)).prox=aux;
        int reenc=0;
        return reenc;
    }
    return insere1;
}


no *removeenc(int x,no **ant,no **pont, no *ptlista){
    no *remove1=NULL;
    buscaenc(x,ant,pont,ptlista);
    if(pont!=NULL){
        (*(*ant)).prox=(*(*pont)).prox;
        remove1=(*pont);
    }
    return (remove1);
}

void escrita(no *ptlista){
    no *ptr = ptlista->prox;
    while (ptr != NULL) {
        printf(" %d", ptr->chave);
        ptr = ptr->prox;
    }
    printf("\n");
}