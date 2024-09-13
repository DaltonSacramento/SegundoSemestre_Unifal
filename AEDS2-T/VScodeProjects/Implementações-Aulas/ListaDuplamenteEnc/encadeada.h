#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int chave;
    int valor;
    struct no *post;//Ponteiro de no numa struct no
    struct no *ant;
}no;

no *buscaListaDE(no *ptlista,int x){
    no *ultimo=(*ptlista).ant;
    if(ultimo != ptlista && x<=(*ultimo).chave){
        no *pont=(*ptlista).post;
        while((*pont).chave<x){
            pont=(*pont).post;
        }
        return pont;
    }
    return ptlista;
}

no *insereListaDE(no *ptlista, no *novo){
    no *pont=buscaListaDE(ptlista,(*novo).chave);
    if(pont==ptlista || (*pont).chave!=(*novo).chave){
        no *anterior=(*pont).ant;
        (*novo).post=pont;
        (*novo).ant=(*pont).ant;
        (*anterior).post=novo;
        (*pont).ant=novo;
        return NULL;
    }
    return pont;
}

no *removeListaDE(no *ptlista,int x){
    no *exclude=NULL;
    if((*ptlista).post!=NULL){
        no *pont=buscaListaDE(ptlista,x);
        if((*pont).chave==x){
            exclude=pont;
            no *anterior=(*pont).ant;
            no *posterior=(*pont).post;
            (*anterior).post=(*pont).post;
            (*posterior).ant=(*pont).ant;
        }

    }
    return exclude;
}

