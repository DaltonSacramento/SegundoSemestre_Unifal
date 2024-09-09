#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int chave;
    int valor;
    struct no *prox;//Ponteiro de no numa struct no
    struct no *ant;
}no;

/*Busca encadeada*//*
no *buscaenc(int x, no *ptlista){
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
}*/

int insereenc(no *x, no *ptlista){
    int insere1=-1;
    (*x).prox=ptlista;
    if(ptlista==NULL){
        (*ptlista).ant=x;
    }
    ptlista=x;
    (*x).ant=NULL;
    return insere1;
}


int removeenc(no *x, no *ptlista){
    if((*x).ant!=NULL){
        ((*x).ant).prox=(*x).prox;
    }
    else{
        ptlista=(*x).prox;
    }
    if((*x).prox!=NULL){
        ((*x).prox).ant=(*x).ant;
    }
    return 0;
}

void escrita(no *ptlista){
    no *ptr = ptlista->prox;
    while (ptr != NULL) {
        printf(" %d", ptr->chave);
        ptr = ptr->prox;
    }
    printf("\n");
}