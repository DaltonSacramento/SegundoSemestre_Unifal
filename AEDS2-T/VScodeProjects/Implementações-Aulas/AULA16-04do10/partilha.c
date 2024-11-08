#include <stdlib.h>
#include <stdio.h>

typedef struct node_{
    int valor;
    int partilha;
    struct node_ *esq;
    struct node_ *dir;
    int freq;
}node;


// Função para imprimir a árvore (pré-ordem)
void imprimir_arvore(node *raiz) {
    if (raiz != NULL) {
        printf("Chave: %d, Partilha (chave mediana): %d\n", raiz->valor, raiz->partilha);
        imprimir_arvore(raiz->esq);
        imprimir_arvore(raiz->dir);
    }
}

node* construçao(node v[], int inf, int sup){
    node *raiz=NULL;
    if (inf <= sup) {
        int max = inf;
        for (int i = inf + 1; i <= sup; i++) {
            if (v[i].freq > v[max].freq) {
                max = i;
            }
        }

        raiz = malloc(sizeof(node));
        raiz->valor = v[max].valor;
        raiz->freq = v[max].freq;

        // Ajuste do vetor: desloca os elementos para preencher o espaço do elemento removido
        for (int i = max; i < sup; i++) {
            v[i] = v[i + 1];
        }
        sup--;

        int mid = (inf + sup) / 2;
        if (inf <= sup) {
            raiz->partilha = v[mid].valor;
            raiz->esq = construçao(v, inf, mid);
            raiz->dir = construçao(v, mid + 1, sup);
        } else {
            raiz->partilha = -1;
            raiz->esq = NULL;
            raiz->dir = NULL;
        }
    }
    return raiz;
}

void visita(node *raiz){
    printf("Chave: %d, Partilha (chave mediana): %d\n", raiz->valor, raiz->partilha);
}
void preordem(node *raiz){
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

int main() {
    node V[15];

    int x;
    int i=0;
    do{
        printf("\nDigite a opção: ");
        scanf("%d", &x);
        switch(x){
            case 1://Insere
                int k;
                printf("\nDigite o valor do novo no: ");
                scanf("%d", &k);
                V[i].valor=k;
                printf("\nDigite a frequencia do novo no: ");
                scanf("%d", &k);
                V[i].freq=k;
                i++;
                break;

            case 2:
                // Constrói a árvore
                node *raiz = construçao(V, 0, i-1);
                // Imprime a árvore
                printf("Árvore de partilha construída:\n");
                //imprimir_arvore(raiz);
                preordem(raiz);
                break;
        }
    }while(x!=0);

    
    return 0;
}