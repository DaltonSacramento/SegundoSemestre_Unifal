#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "ordenaçoes.h"

//Função para troca de dois itens
void swapJogador(vetor* xp, vetor* yp){
    vetor temp = *xp;
    *xp = *yp;
    *yp = temp;
}
//Algoritmo Simples de ordenação BubbleSort
void bubbleSort(vetor arr[], int n){
    int i, j;//Indices
    bool swapped;//Variável booleana
    for (i = 0; i < n - 1; i++) {//Repetição para percorrer o vetor
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {  //Repetição para ordenar o vetor "i" vezes    
            if (arr[j].nome[0] > arr[j + 1].nome[0]){
                swapJogador(&arr[j], &arr[j + 1]);
                swapped = true;
            }
            for(int l=0; l<40; l++){//Repetição para comparar todas as letras do nome
                if(arr[j].nome[l] == arr[j + 1].nome[l]){//Caso um caracter seja igual o caracter seguinte é comparado
                    if (arr[j].nome[l+1] > arr[j + 1].nome[l+1]){
                        swapJogador(&arr[j], &arr[j + 1]);
                        swapped = true;
                    }
                }
                else{//Caso o caracter comparado não seja igual
                    break;
                }
            }
        }

        // Se não houve a troca de elementos
        if (!swapped)
            break;
    }
}


//Algoritmo Ótimo de Ordenação MergeSort
void merge(vetor arr[], int l, int m, int r){
    //Dimensões dos vetores auxiliares
    int dimL = m-l+1;
    int dimR = r - m;
    vetor L[dimL], R[dimR];

    int i, j, k;//Indices
    //Cópia das posições específicas do vetor principal para os vetores auxiliares
    for(i = 0; i < dimL; i++){
        L[i] = arr[l+i];
    }
    for(j = 0; j < dimR; j++){
        R[j] = arr[m+1+j];
    }


    i = 0; j = 0, k = l;
    while(i < dimL && j < dimR){//Realização das trocas e comparações
        if(L[i].nome[0] <= R[j].nome[0]){
            if(L[i].nome[0]==R[j].nome[0]){
                for(int l=0; l<40; l++){//Comparação de todas as letras do nome
                    if(L[i].nome[l]==R[j].nome[l]){//Usa a mesma logica dos primeiros "if-else" do "while" que estamos
                        if(L[i].nome[l+1] < R[j].nome[l+1]){
                            arr[k] = L[i];
                            i++;
                        }
                        if(L[i].nome[l+1] > R[j].nome[l+1]){
                            arr[k] = R[j];
                            j++;
                        }
                    }else{//Caso o caracter comparado seja diferente
                        break;
                    }
                }
                
            }
            else{//Caso o num seja menor que o outro
                arr[k] = L[i];
                i++;
            }
        }else{//Caso o num seja maior
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < dimL){//Caso sobre mais jogadores no vetor auxiliar L
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < dimR){//Caso sobre mais jogadores no vetor auxiliar R
        arr[k] = R[j];
        j++;    
        k++;
    }
}
void mergeSort(vetor arr[], int l, int r){
    if (l < r) {//Caso a partição do vetor ainda tenha mais de um elemento
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);//"Quebra" do vetor no sentido da esquerda
        mergeSort(arr, m + 1, r);//"Quebra" do vetor no sentido da direita

        merge(arr, l, m, r);//Comparação e troca dos dados
    }
}