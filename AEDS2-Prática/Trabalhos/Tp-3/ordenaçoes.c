#include <stdlib.h>
#include <stdio.h>
#include "ordenaçoes.h"

//#define MAX_STRING 100

int main(int argc, char* argv[]){

    char caminho[256];// Buffer para armazenar o caminho completo do arquivo
    // Constrói o caminho para o arquivo dentro da pasta "instancias"
    snprintf(caminho, sizeof(caminho), "jogadores/jogador.csv");

    int instancia_num = atoi(argv[1]);
    if (instancia_num==1){
        FILE* pontarq = fopen(caminho, "r");
        if (pontarq == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return(1);
        }
        double tempo_ord_simples = ord_simples(pontarq);
        fclose(pontarq);//Fecha o arquivo de texto
        printf("Tempo: %f", tempo_ord_simples);
    }
    if (instancia_num==2){
        FILE* pontarq2 = fopen(caminho, "r");
        if (pontarq2 == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return(1);
        }
        double tempo_ord_otima = ord_otima(pontarq2);
        fclose(pontarq2);//Fecha o arquivo de texto
    }
    if (instancia_num==3){
        FILE* pontarq3 = fopen(caminho, "r");
        if (pontarq3 == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return(1);
        }
        double tempo_ord_tempolinear = ord_tempolinear(pontarq3);
        fclose(pontarq3);//Fecha o arquivo de texto
    }

    

    return 0;
}