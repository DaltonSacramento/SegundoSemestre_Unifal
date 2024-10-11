#include <stdlib.h>
#include <stdio.h>

typedef struct node_{
    int chave;
    int partilha;
    struct node_ *esq;
    struct node_ *dir;
}node;

typedef struct vet_{
    int chave;
    int freq;
}vet;

node *construirss(vet V[], int m, int n){
    node *no=malloc(sizeof(node));
    if(m==n){
        return NULL;
    }else{
        int y, s;
        y=V[m].freq;
        s=m/2;
        no->chave=y;
        no->partilha=s;
        no->esq=construirss(V,s,n);
        no->dir=construirss(V,n,s);
    }
    return no;
}

node *construir(vet V[], int m, int n) {
    // Verifica se o intervalo é válido
    if (m > n) {
        return NULL;
    }

    // Calcula o ponto de partição (meio do intervalo)
    int s = (m + n) / 2;

    // Aloca um novo nó
    node *no = (node *)malloc(sizeof(node));

    // Inicializa o nó:
    no->chave = V[s].chave;      // A chave do nó é a chave do vetor na posição s
    no->partilha = V[((m+n)-1)/2].chave;   // O campo partilha agora armazena a chave do elemento mediano

    // Chama recursivamente para construir as subárvores
    no->esq = construir(V, m, s - 1); // Subárvore esquerda: elementos menores que a partição
    no->dir = construir(V, s + 1, n); // Subárvore direita: elementos maiores que a partição
    return no;
}

// Função para imprimir a árvore (pré-ordem)
void imprimir_arvore(node *raiz) {
    if (raiz != NULL) {
        printf("Chave: %d, Partilha (chave mediana): %d\n", raiz->chave, raiz->partilha);
        imprimir_arvore(raiz->esq);
        imprimir_arvore(raiz->dir);
    }
}

int main() {
    vet V[] = { {1, 5}, {2, 3}, {3, 7}, {4, 1}, {5, 4} }; // Exemplo de vetor de chaves e frequências
    int n = sizeof(V) / sizeof(V[0]);

    // Constrói a árvore
    node *raiz = construir(V, 0, n - 1);

    // Imprime a árvore
    printf("Árvore de partilha construída:\n");
    imprimir_arvore(raiz);

    return 0;
}