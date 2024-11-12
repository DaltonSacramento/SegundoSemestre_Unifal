#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_STRING 100

typedef struct vetor_{
    char nome[MAX_STRING];
    char posicao[MAX_STRING];
    char naturalidade[MAX_STRING];
    char clube[MAX_STRING];
    int idade; 
}vetor;


double ord_simples(int instancia_num, FILE *pontarq) {
    double tempo = 0;
    clock_t begin = clock();
    vetor v[2];

    char line[256]; //buffer do fgets
    char *token;
    char *tokens[5];

    // Lendo uma linha do arquivo
    fgets(line, sizeof(line), pontarq);

    int i=0;
    while (fgets(line, sizeof(line), pontarq) != NULL) {
        // Dividindo a linha com strtok (delimitador vírgula)
        char *token = strtok(line, ",");
        int k = 0;

        // Armazenando os tokens no vetor de ponteiros
        while (token != NULL && k < 5) {
            tokens[k++] = token;
            token = strtok(NULL, ",");
        }

        // Atribuindo os tokens à estrutura v[0]
        snprintf(v[i].nome, MAX_STRING, "%s", tokens[0]);
        snprintf(v[i].posicao, MAX_STRING, "%s", tokens[1]);
        snprintf(v[i].naturalidade, MAX_STRING, "%s", tokens[2]);
        snprintf(v[i].clube, MAX_STRING, "%s", tokens[3]);
        v[i].idade = atoi(tokens[4]);  // Convertendo a idade de string para inteiro
    }
    printf("%s,%s,%s,%s,%d\n", v[0].nome, v[0].posicao, v[0].naturalidade, v[0].clube, v[0].idade);

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

    FILE* pontarq = fopen("jogadores.csv", "r");

    if (pontarq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return(1);
    }

    double tempo_ord_simples = ord_simples(instancia_num,pontarq);
    // double tempo_ord_otima = ord_otima(instancia_num);
    // double tempo_ord_linear = ord_tempolinear(instancia_num);

    return 0;
}