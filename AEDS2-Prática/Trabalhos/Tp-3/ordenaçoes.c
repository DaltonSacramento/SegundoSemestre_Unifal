#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

//#define MAX_STRING 100

typedef struct vetor_{
    char nome[40];
    char posicao[30];
    char naturalidade[30];
    char clube[30];
    int idade; 
}vetor;

void swapJogador(vetor* xp, vetor* yp){
    vetor temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapVc(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void copiaVetor(vetor v1[], int Vc[]){
    int aux2;
    char *aux;
    for (int j = 0; j < 10; j++) {
        aux=v1[j].nome;
        aux2=*aux;
        Vc[j]=aux2;
    }
}

void bubbleSort(vetor arr[], int n){
    int i, j;
    bool swapped;
    int Vc[10];
    //Cria
    copiaVetor(arr,Vc);
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {      
            if (Vc[j] > Vc[j + 1]) {
                swapJogador(&arr[j], &arr[j + 1]);
                swapVc(&Vc[j], &Vc[j+1]);
                swapped = true;
            }
        }

        // Se não houve a troca de elementos
        if (!swapped)
            break;
    }
}


double ord_simples(int instancia_num, FILE *pontarq) {
    double tempo = 0;
    clock_t begin = clock();
    vetor v[1150];

    char line[256]; //buffer do fgets
    char *token;
    char *tokens[5];

    // Lendo uma linha do arquivo
    fgets(line, sizeof(line), pontarq);

    int i=0;
    int k;
    while (fgets(line, sizeof(line), pontarq) != NULL) {
        // Dividindo a linha com strtok (delimitador vírgula)
        token = strtok(line, ",");
        k = 0;

        // Armazenando os tokens no vetor de ponteiros
        while (token != NULL && k < 5) {
            tokens[k++] = token;
            token = strtok(NULL, ",");
        }
        // Atribuindo os tokens à estrutura v[0]
        //snprintf(v[i].nome, 40, "%s", tokens[0]);
        strcpy(v[i].nome, tokens[0]);
        strcpy(v[i].posicao, tokens[1]);
        strcpy(v[i].naturalidade, tokens[2]);
        strcpy(v[i].clube, tokens[3]);
        v[i].idade = atoi(tokens[4]);  // Convertendo a idade de string para inteiro
        i++;
    }

    bubbleSort(v,10);
    for(int k=0; k<10; k++){
        printf("%s,%s,%s,%s,%d\n", v[k].nome, v[k].posicao, v[k].naturalidade, v[k].clube, v[k].idade);
    }

    clock_t end = clock();
    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    return (tempo);
}

double ord_otima(int instancia_num) {
    double tempo = 0;
    clock_t begin = clock();


    clock_t end = clock();
    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    return (tempo);
}

double ord_tempolinear(int instancia_num) {
    double tempo = 0;
    clock_t begin = clock();


    clock_t end = clock();
    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    return (tempo);
}

int main(){

    ///////////////////////////////////////////////////////////
    /////////////////// Leitor de instâncias //////////////////
    ///////////////// Não deve ser modificado /////////////////
    ///////////////////////////////////////////////////////////
    int instancia_num = -1;

    // instancia_num = atoi(argv[1]);
    // if (instancia_num <= 0 || instancia_num > 10) {
    //     printf("Para evalecutar o código, digite ./arvores val\nonde val é um número entre 1 e 10 que simboliza a instância utilizada\n");
    //     return(0);
    // }

    FILE* pontarq = fopen("jogador.csv", "r");

    if (pontarq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return(1);
    }

    double tempo_ord_simples = ord_simples(instancia_num,pontarq);
    // double tempo_ord_otima = ord_otima(instancia_num);
    // double tempo_ord_linear = ord_tempolinear(instancia_num);

    return 0;
}