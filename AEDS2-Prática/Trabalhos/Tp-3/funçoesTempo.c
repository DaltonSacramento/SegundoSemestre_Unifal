#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "ordenaçoes.h"

double ord_simples(FILE *pontarq, unsigned long int *MT, int *NOC, int *NOT) {
    double tempo = 0;
    clock_t begin = clock();
    

    vetor v[1150];//Vetor com os campos da struct
    char line[256]; //buffer do fgets
    char *token;
    char *tokens[5];//Vetor de tokens para armazenar o campo de maneira formatada

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

    bubbleSort(v,i,MT,NOC,NOT);
    for(int k=0; k<10; k++){
        printf("%s,%s,%s,%s,%d\n", v[k].nome, v[k].posicao, v[k].naturalidade, v[k].clube, v[k].idade);
    }


    clock_t end = clock();
    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    return (tempo);
}

double ord_otima(FILE *pontarq, unsigned long int *MT, int *NOC, int *NOT) {
    double tempo = 0;
    clock_t begin = clock();


    vetor v[1150];//Vetor com os campos da struct
    char line[256]; //buffer do fgets
    char *token;
    char *tokens[5];//Vetor de tokens para armazenar o campo de maneira formatada

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

    //Função de ordenação
    mergeSort(v,0,i-1,MT,NOC,NOT);
    printf("\n");
    for(int k=0; k<10; k++){
        printf("%s,%s,%s,%s,%d\n", v[k].nome, v[k].posicao, v[k].naturalidade, v[k].clube, v[k].idade);
    }


    clock_t end = clock();
    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    return (tempo);
}

double ord_tempolinear(FILE *pontarq, unsigned long int *MT, int *NOC, int *NOT) {
    double tempo = 0;
    clock_t begin = clock();

    vetor v[1150];//Vetor com os campos da struct
    char line[256]; //buffer do fgets
    char *token;
    char *tokens[5];//Vetor de tokens para armazenar o campo de maneira formatada

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

    clock_t end = clock();
    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    return (tempo);
}