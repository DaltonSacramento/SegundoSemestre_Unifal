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
noArvore *min(noArvore *raiz){
    while((*raiz).esq!=NULL){
        raiz=(*raiz).esq;
    }
    return raiz;
}

noArvore *buscaPai(noArvore *raiz, noArvore *n){
    if(raiz==NULL || (*raiz).esq==n || (*raiz).dir==n){
        return raiz;
    }
    if((*raiz).valor > (*n).valor){
        return buscaPai((*raiz).esq,n);
    }
    else{
        return buscaPai((*raiz).dir,n);
    }
}



noArvore *removeRaiz(noArvore *n) {

    // Caso 2: nó só tem filho direito
    if (n->esq == NULL) {
        noArvore *temp = n->dir;
        free(n);
        return temp;
    }
    
    // Caso 3: nó só tem filho esquerdo
    if (n->dir == NULL) {
        noArvore *temp = n->esq;
        free(n);
        return temp;
    }

    // Caso 4: nó tem dois filhos
    // Encontra o sucessor (menor valor da subárvore direita)
    noArvore *paiSucessor = n;
    noArvore *sucessor = n->esq;
    
    // Encontra o sucessor (continua indo para esquerda)
    while (sucessor->dir != NULL) {
        paiSucessor = sucessor;
        sucessor = sucessor->dir;
    }

    // Copia o valor do sucessor para o nó atual
    n->valor = sucessor->valor;

    // Remove o sucessor
    if (paiSucessor == n) {
        // Se o sucessor é filho direto do nó a ser removido
        paiSucessor->esq = sucessor->esq;
    } else {
        // Se o sucessor está mais profundo na árvore
        paiSucessor->dir = sucessor->esq;
    }

    free(sucessor);
    return n;
}

noArvore *removeNo(noArvore *raiz, int valor){
    noArvore *n=busca(raiz,valor);
    if(n!=NULL){
        noArvore *pai=buscaPai(raiz,n);
        if(pai!=NULL){
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

            case 4:
                preordem(raiz);
                break;
        }
    }while(x!=0);

    

    return 0;
}