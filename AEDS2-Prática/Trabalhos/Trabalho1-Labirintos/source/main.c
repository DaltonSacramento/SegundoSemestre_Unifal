#include <stdlib.h>
#include <stdio.h>

// Tamanho das linhas e colunas da matriz
#define N 10
#define M 10

// Estrutura para a topoP
typedef struct no{
    int x;
    int y;
    struct no *prox;
}no;

//Estrutura das posições das coordenadas
typedef struct pos{
    char argumento;
}pos;

// Função para imprimir a topoP
void escritaPilha(no *topoP) {
    no *aux=topoP;
    while (aux!=NULL) {
        printf("(%d, %d)\n", (*aux).x, (*aux).y);
        aux=(*aux).prox;
    }
}

// Função para adicionar um nó no final da topoP
void insertionPilha(no **topo, no *novo) {
    (*novo).prox=(*topo);
    (*topo)=novo;
}

//Tranferencia da pilha principal para uma pilha de exibição do caminho
void transferenciadepilha(no **topoP2, no *topoP){
    no *aux=topoP;
    while (aux!=NULL){
        no *aux2=malloc(sizeof(no));
        (*aux2).x=(*aux).x;
        (*aux2).y=(*aux).y;
        insertionPilha(topoP2,aux2);
        aux=(*aux).prox;
    }
}

// Função para remover o último nó da topoP
void removePilha(no **topo) {
    if((*topo)!=NULL){
        (*topo)=(*(*topo)).prox;
    }
}

// Função para encontrar a saída do labirinto
void encontrarSaida(no **topoP, pos lab[N][M], int *retorno) {
    //Criação da coordenada auxiliar
    no *aux=*topoP;
    int x=(*aux).x;
    int y=(*aux).y;

    if (lab[x][y].argumento=='S') {
        no *novoS=malloc(sizeof(no));
        (*novoS).x=x+1;
        (*novoS).y=y;
        insertionPilha(topoP,novoS);
        *retorno=2;
    }

    lab[x][y].argumento='X'; // Marcar como visitado

    // Movimentos possíveis: baixo, direita, esquerda, cima
    //Baixo
    if (x+1<N && (lab[x+1][y].argumento!='X' || lab[x+1][y].argumento=='S')) {
        no *novoB=malloc(sizeof(no));
        (*novoB).x=x+1;
        (*novoB).y=y;
        insertionPilha(topoP,novoB);
        if(*retorno==2||topoP==NULL){
            return;
        }
        encontrarSaida(topoP,lab,retorno);
        return;
    }
    //Direita
    if (y+1<M && (lab[x][y+1].argumento=='0' || lab[x][y+1].argumento=='S')) {
        no *novoD=malloc(sizeof(no));
        (*novoD).x=x;
        (*novoD).y=y+1;
        insertionPilha(topoP,novoD);
        if(*retorno==2||topoP==NULL){
            return;
        }
        encontrarSaida(topoP,lab,retorno);
        return;
    }
    //Esquerda
    if (y-1>=0 && (lab[x][y-1].argumento=='0' || lab[x][y-1].argumento=='S')) {
        no *novoE=malloc(sizeof(no));
        (*novoE).x=x;
        (*novoE).y=y-1;
        insertionPilha(topoP,novoE);
        if(*retorno==2||topoP==NULL){
            return;
        }
        encontrarSaida(topoP,lab,retorno);
        return;
    }
    //Cima
    if (x-1>=0 && (lab[x-1][y].argumento=='0' || lab[x-1][y].argumento=='S')) {
        no *novoC=malloc(sizeof(no));
        (*novoC).x=x-1;
        (*novoC).y=y;
        insertionPilha(topoP,novoC);
        if(*retorno==2||topoP==NULL){
            return;
        }
        encontrarSaida(topoP,lab,retorno);
        return;
    }

    //Remove um elemento da pilha se nao conseguir avançar
    removePilha(topoP);
    if(*retorno==2||topoP==NULL){
            return;
    }
    else{
        encontrarSaida(topoP,lab,retorno);
    }
}

void leituramatriz(pos lab[N][M], FILE *pontarq) {
    // Leitura da matriz
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            lab[i][j].argumento = fgetc(pontarq);
        }
        fgetc(pontarq);
    }

    // Exibe o labirinto lido
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", lab[i][j].argumento);
        }
        printf("\n");
    }
}

/*Função para encontrar as coordenadas da entrada*/
void entrada(pos lab[N][M], no *novo){
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (lab[i][j].argumento == 'E') {
                (*novo).x=i;
                (*novo).y=j;
            }
        }
    }
}

int main(int argc, char* argv[]) {

    //Análise da entrada de argumento dos parâmetros
    if(argc != 2){
        printf("\nVocê utilizou um número inválido de argumentos!");
        return 1;
    }else{
        printf("\nLabirinto lido: \n\n");
    }

    //Abertura do arquivo
    FILE* pontarq = fopen(argv[1], "r");
    if(pontarq == NULL){
        printf("O arquivo procurado não existe!\n");
        return 1;
    }

    //Inicialização da matriz
    pos lab[N][M];
    leituramatriz(lab,pontarq);

    //Inicialização da Pilha
    no *topoP=NULL;
    //Descobrir entrada e adiciona-la a pilha
    no *novo=malloc(sizeof(no));
    entrada(lab,novo);
    insertionPilha(&topoP, novo);


    // Busca pela saída
    int retorno=0;
    encontrarSaida(&topoP, lab, &retorno);

    //Verificação
    if (retorno==2) {
        no *topoP2=NULL;
        transferenciadepilha(&topoP2,topoP);
        printf("Solução: \n");
        escritaPilha(topoP2);
    }
    else {
        printf("\nLabirinto sem solução\n");
    }

    return 0;
}
