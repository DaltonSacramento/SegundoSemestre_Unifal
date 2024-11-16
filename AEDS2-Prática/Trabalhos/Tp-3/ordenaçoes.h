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

void swapJogador(vetor* xp, vetor* yp);
void bubbleSort(vetor arr[], int n);
double ord_simples(FILE *pontarq);

double ord_otima(FILE *pontarq);

double ord_tempolinear(FILE *pontarq);

#endif // _H_ARVORES