#include <stdlib.h>
#include <stdio.h>

typedef struct noArvore_{
    int valor;
    struct noArvore_ *esq;
    struct noArvore_ *dir;
}noArvore;

noArvore *busca(noArvore* raiz, int k){
    if(raiz==NULL || raiz->valor == k)
        return raiz;
    if(raiz->valor > k)
        return busca(raiz->esq,k);
    else
        return busca(raiz->dir,k);
}

noArvore* insere(noArvore *raiz, noArvore *n){
    if(raiz==NULL) return n;
    if(raiz->valor > n->valor)
        raiz->esq = insere(raiz->esq,n);
    else
        raiz->dir = insere(raiz->dir,n); 
    return raiz;
}

noArvore* buscaPai(noArvore *raiz, noArvore* n){
    if(raiz==NULL || raiz->esq==n || raiz->dir==n)
        return raiz;
    if(raiz->valor > n->valor)
        return buscaPai(raiz->esq,n);
    else
        return buscaPai(raiz->dir,n);
}

noArvore* removeRaiz(noArvore* n){
    if(n->esq==NULL){
        noArvore *temp = n->dir;
        free(n);
        return temp;
    }
    if(n->dir==NULL){
        noArvore *temp = n->esq;
        free(n);
        return temp;
    }
    noArvore* paiSucessor=n;
    noArvore* sucessor=n->esq;//o sucessor começa como o filho a esquerda do nó a ser removido
    while(sucessor->dir!=NULL){//Caminhamento para achar o maior nó da esq
        paiSucessor=sucessor;
        sucessor=sucessor->dir;
    }
    n->valor = sucessor->valor;//n precisa obter o valor do sucessor para ser retornado
    if(paiSucessor==n){
        paiSucessor->esq=sucessor->esq;
    }
    else
        paiSucessor->dir=sucessor->esq;

    free(sucessor);
    return n;//Retorna o n, que obteve o valor do sucessor
}

noArvore* removeNo(noArvore* raiz, int k){
    noArvore* n = busca(raiz,k);
    if(n!=NULL){
        noArvore* pai = buscaPai(raiz,n);
        if(pai!=NULL){
            if(pai->valor > n->valor)
                pai->esq = removeRaiz(n);
            else
                pai->dir = removeRaiz(n);
        }
        else{
            raiz = removeRaiz(n);
        }
    }
    return raiz;
}

void visita(noArvore *raiz){
    printf(" %d", (*raiz).valor);
}
void preordem(noArvore *raiz){
    if(raiz!=NULL){
        visita(raiz);
        if((*raiz).esq!=NULL){
            preordem((*raiz).esq);
        }
        if((*raiz).dir!=NULL){
            preordem((*raiz).dir);
        }
    }
}

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
                raiz=insere(raiz,n);
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

            case 4:
                preordem(raiz);
                break;
        }
    }while(x!=0);

    return 0;
}