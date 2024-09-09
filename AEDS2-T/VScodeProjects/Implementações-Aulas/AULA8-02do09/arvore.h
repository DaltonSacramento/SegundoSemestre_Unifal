#include <stdlib.h>
#include <stdio.h>

typedef struct noArvore_ noArvore;
struct noArvore_{
    int valor;
    noArvore *esq;
    noArvore *dir;
};

noArvore *insere(noArvore **raiz, noArvore *n){
    if((*raiz)==NULL) return n;
    if((*(*raiz)).valor > (*n).valor){
        (*(*raiz)).esq=insere(&(*(*raiz)).esq,n);
    }
    else{
        (*(*raiz)).dir=insere(&(*(*raiz)).dir,n);
    }
    return (*raiz);
}

noArvore *busca(noArvore *raiz, int k){
    if(raiz==NULL || (*raiz).valor==k){
        return raiz;
    }
    if((*raiz).valor > k){
        return busca((*raiz).esq,k);
    }
    else{
        return busca((*raiz).dir,k);
    }
}

noArvore *buscaPai(noArvore *raiz, noArvore *n, noArvore *pai){
    if(raiz==NULL || (*raiz).valor==(*n).valor){
        return pai;
    }
    pai=raiz;
    if((*raiz).valor > (*n).valor){
        return buscaPai((*raiz).esq,n,pai);
    }
    else{
        return buscaPai((*raiz).dir,n,pai);
    }
}

noArvore *min(noArvore *raiz){
    while((*raiz).esq!=NULL){
        raiz=(*raiz).esq;
    }
    return raiz;
}

noArvore *removeRaiz(noArvore *n){
    if (n == NULL) {
        return NULL;
    }
    
    if((*n).esq==NULL && (*n).dir==NULL){
        n=NULL;
        return NULL;
    }

    if((*n).esq==NULL){
        return (*n).dir;
    }
    if((*n).dir==NULL){
        return (*n).esq;
    }

    noArvore *sucessor = min(n->dir);
    n->valor = sucessor->valor;
    n->dir = removeRaiz(sucessor);

    return n;

}

noArvore *removeNo(noArvore *raiz, int valor){
    noArvore *n=busca(raiz,valor);
    if(n){
        noArvore *gg=NULL;
        noArvore *pai=buscaPai(raiz,n,gg);
        if(pai){
            if((*pai).dir==n){
                (*pai).dir=removeRaiz(n);
            }
            else{
                (*pai).esq=removeRaiz(n);
            }
        }
        else{
            raiz=removeRaiz(n);
        }
    }
    return raiz;
}

void visita(noArvore *raiz){
    printf(" %d", (*raiz).valor);
}
void emordem(noArvore *raiz){
    if(raiz!=NULL){
        if((*raiz).esq!=NULL){
            emordem((*raiz).esq);
        }
        visita(raiz);
        if((*raiz).dir!=NULL){
            emordem((*raiz).dir);
        }
    }
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
void posordem(noArvore *raiz){
    if(raiz!=NULL){
        if((*raiz).esq!=NULL){
            posordem((*raiz).esq);
        }
        if((*raiz).dir!=NULL){
            posordem((*raiz).dir);
        }
        visita(raiz);
    }
}