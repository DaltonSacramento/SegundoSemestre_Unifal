#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "ordenaçoes.h"

void swapJogador(vetor* xp, vetor* yp){
    vetor temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(vetor arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {      
            if (arr[j].nome[0] > arr[j + 1].nome[0]){
                swapJogador(&arr[j], &arr[j + 1]);
                swapped = true;
            }
            for(int l=0; l<40; l++){
                if(arr[j].nome[l] == arr[j + 1].nome[l]){
                    if (arr[j].nome[l+1] > arr[j + 1].nome[l+1]){
                        swapJogador(&arr[j], &arr[j + 1]);
                        swapped = true;
                    }
                }
                else{
                    break;
                }
            }
        }

        // Se não houve a troca de elementos
        if (!swapped)
            break;
    }
}