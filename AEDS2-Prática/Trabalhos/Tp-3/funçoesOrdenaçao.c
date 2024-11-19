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



void merge(vetor arr[], int l, int m, int r){
    
    int dimL = m-l+1;
    int dimR = r -m;
    vetor L[dimL], R[dimR];

    int i, j, k;
    for(i = 0; i < dimL; i++){
        L[i] = arr[l+i];
    }
    for(j = 0; j < dimR; j++){
        R[j] = arr[m+1+j];
    }

    i = 0; j = 0, k = l;
    while(i < dimL && j < dimR){
        if(L[i].nome[0] <= R[j].nome[0]){
            if(L[i].nome[0]==R[j].nome[0]){
                for(int l=0; l<40; l++){
                    if(L[i].nome[l]==R[j].nome[l]){
                        if(L[i].nome[l+1] < R[j].nome[l+1]){
                            arr[k] = L[i];
                            i++;
                        }
                        if(L[i].nome[l+1] > R[j].nome[l+1]){
                            arr[k] = R[j];
                            j++;
                        }
                    }else{
                        break;
                    }
                }
                
            }
            else{
                arr[k] = L[i];
                i++;
            }
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < dimL){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < dimR){
        arr[k] = R[j];
        j++;    
        k++;
    }
}
void mergeSort(vetor arr[], int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}