#include <stdlib.h>
#include <stdio.h>
#include "ordenaçoes.h"

//#define MAX_STRING 100

int main(int argc, char* argv[]){

    char caminho[256];// Buffer para armazenar o caminho completo do arquivo
    // Constrói o caminho para o arquivo dentro da pasta "instancias"
    snprintf(caminho, sizeof(caminho), "jogadores/jogador.csv");

    unsigned long int MT;
    int NOC;
    int NOT;

    int instancia_num = atoi(argv[1]);
    if (instancia_num==1){
        FILE* pontarq = fopen(caminho, "r");
        if (pontarq == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return(1);
        }
        double tempo_ord_simples = ord_simples(pontarq,&MT,&NOC,&NOT);
        fclose(pontarq);//Fecha o arquivo de texto
        
        printf("\nTempo: %f", tempo_ord_simples);
        printf("\nNúmero de Operações de Comparação: %d", NOC);
        printf("\nNúmero de Operações de Troca: %d", NOT);
        printf("\nMemória total gasta: %ld\n", MT);
    }
    if (instancia_num==2){
        FILE* pontarq2 = fopen(caminho, "r");
        if (pontarq2 == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return(1);
        }
        double tempo_ord_otima = ord_otima(pontarq2,&MT,&NOC,&NOT);
        fclose(pontarq2);//Fecha o arquivo de texto

        printf("\nTempo: %f", tempo_ord_otima);
        printf("\nNúmero de Operações de Comparação: %d", NOC);
        printf("\nNúmero de Operações de Troca: %d", NOT);
        printf("\nMemória total gasta: %ld\n", MT);
    }
    if (instancia_num==3){
        FILE* pontarq3 = fopen(caminho, "r");
        if (pontarq3 == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return(1);
        }
        double tempo_ord_tempolinear = ord_tempolinear(pontarq3,&MT,&NOC,&NOT);
        fclose(pontarq3);//Fecha o arquivo de texto
        printf("\nTempo: %f", tempo_ord_tempolinear);
    }

    

    return 0;
}