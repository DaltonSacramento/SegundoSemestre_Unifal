#include <stdlib.h>
#include <stdio.h>
#include "ordenaçoes.h"

//#define MAX_STRING 100

int main(){

    ///////////////////////////////////////////////////////////
    /////////////////// Leitor de instâncias //////////////////
    ///////////////// Não deve ser modificado /////////////////
    ///////////////////////////////////////////////////////////
    //int instancia_num = -1;

    // instancia_num = atoi(argv[1]);
    // if (instancia_num <= 0 || instancia_num > 10) {
    //     printf("Para evalecutar o código, digite ./arvores val\nonde val é um número entre 1 e 10 que simboliza a instância utilizada\n");
    //     return(0);
    // }

    char caminho[256];// Buffer para armazenar o caminho completo do arquivo
    // Constrói o caminho para o arquivo dentro da pasta "instancias"
    snprintf(caminho, sizeof(caminho), "jogadores/jogador.csv");

    FILE* pontarq = fopen(caminho, "r");

    if (pontarq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return(1);
    }

    double tempo_ord_simples;
    tempo_ord_simples = ord_simples(pontarq);
    // double tempo_ord_otima = ord_otima(instancia_num);
    // double tempo_ord_linear = ord_tempolinear(instancia_num);
    fclose(pontarq);//Fecha o arquivo de texto

    printf("Tempo: %f", tempo_ord_simples);

    return 0;
}