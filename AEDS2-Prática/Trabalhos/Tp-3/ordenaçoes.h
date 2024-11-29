#ifndef _H_ARVORES
#define _H_ARVORES
#include <stdio.h>

typedef struct vetor_{
    char nome[40];
    char posicao[30];
    char naturalidade[30];
    char clube[30];
    int idade; 
}vetor;

//Funções de ordenação simples
void swapJogador(vetor* xp, vetor* yp);
void bubbleSort(vetor arr[], int n, unsigned long int *MT, int *NOC, int *NOT);
double ord_simples(FILE *pontarq, unsigned long int *MT, int *NOC, int *NOT);

//Funções de ordenação ótima
void mergeSort(vetor arr[], int l, int r, unsigned long int *MT, int *NOC, int *NOT);
void merge(vetor arr[], int l, int m, int r, unsigned long int **MT, int **NOC, int **NOT);
double ord_otima(FILE *pontarq, unsigned long int *MT, int *NOC, int *NOT);

//Funções de ordenação com tempo linear
char getCharAt(char *str, int pos, unsigned long int *MT, int *NOC, int *NOT);
void countingSort(vetor arr[], int position, unsigned long int *MT, int *NOC, int *NOT);
void radixxSort(vetor arr[], int ind, unsigned long int *MT, int *NOC, int *NOT);
double ord_tempolinear(FILE *pontarq, unsigned long int *MT, int *NOC, int *NOT);

#endif // _H_ARVORES