#include <stdlib.h>
#include <stdio.h>
#include "ordenaçoes.h"

//#define MAX_STRING 100

int main(int argc, char* argv[]){

    char caminho[256];// Buffer para armazenar o caminho completo do arquivo
    // Constrói o caminho para o arquivo dentro da pasta "instancias"
    snprintf(caminho, sizeof(caminho), "jogadores/jogadores.csv");

    //Contadores
    unsigned long int MT;//Contador de uso de memória
    int NOC;//Contador do num de operações de comparação
    int NOT;//Contador do num de operações de troca

    int instancia_num = atoi(argv[1]);//Converte o argumento em inteiro

    //Algoritmo simples
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

    //Algortimo ótimo
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
    
    //Algoritmo de tempo linear
    if (instancia_num==3){
        FILE* pontarq3 = fopen(caminho, "r");
        if (pontarq3 == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return(1);
        }
        double tempo_ord_tempolinear = ord_tempolinear(pontarq3,&MT,&NOC,&NOT);
        fclose(pontarq3);//Fecha o arquivo de texto

        printf("\nTempo: %f", tempo_ord_tempolinear);
        printf("\nNúmero de Operações de Comparação: %d", NOC);
        printf("\nNúmero de Operações de Troca: %d", NOT);
        printf("\nMemória total gasta: %ld\n", MT);
    }

    

    return 0;
}