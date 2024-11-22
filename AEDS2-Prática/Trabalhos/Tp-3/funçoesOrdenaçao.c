#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "ordenaçoes.h"

void removeAcentos(char *str) {
    char *acentuados = "áàâãäéèêëíìîïóòôõöúùûüçÁÀÂÃÄÉÈÊËÍÌÎÏÓÒÔÕÖÚÙÛÜÇ";
    char *semAcento = "aaaaaeeeeiiiiooooouuuucAAAAAEEEEIIIIOOOOOUUUUC";
    
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; acentuados[j] != '\0'; j++) {
            if (str[i] == acentuados[j]) {
                str[i] = semAcento[j];
                break;
            }
        }
    }
}

//Função para troca de dois itens
void swapJogador(vetor* xp, vetor* yp){
    vetor temp = *xp;
    *xp = *yp;
    *yp = temp;
}
//Algoritmo Simples de ordenação BubbleSort
void bubbleSort(vetor arr[], int n, unsigned long int *MT, int *NOC, int *NOT){
    (*MT)+=sizeof(int);
    int i, j;//Indices

    (*MT)+=sizeof(bool);
    bool swapped;//Variável booleana

    for (i = 0; i < n - 1; i++) {//Repetição para percorrer o vetor
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {  //Repetição para ordenar o vetor "i" vezes
            //removeAcentos(arr[j].nome);
            //removeAcentos(arr[j].nome);
            (*NOC)++;
            if (arr[j].nome[0] > arr[j + 1].nome[0]){
                (*NOT)++;
                swapJogador(&arr[j], &arr[j + 1]);
                swapped = true;
            }

            for(int l=0; l<40; l++){//Repetição para comparar todas as letras do nome

                (*NOC)++;
                if(arr[j].nome[l] == arr[j + 1].nome[l]){//Caso um caracter seja igual o caracter seguinte é comparado

                    (*NOC)++;
                    if (arr[j].nome[l+1] > arr[j + 1].nome[l+1]){
                        (*NOT)++;
                        swapJogador(&arr[j], &arr[j + 1]);
                        swapped = true;
                    }
                }
                else{//Caso o caracter comparado não seja igual
                    break;
                }
            }
        }

        (*NOC)++;
        // Se não houve a troca de elementos
        if (!swapped)
            break;
    }

    (*MT)+=sizeof(vetor);
}


//Algoritmo Ótimo de Ordenação MergeSort
void merge(vetor arr[], int l, int m, int r, unsigned long int **MT, int **NOC, int **NOT){
    //Dimensões dos vetores auxiliares
    (*(*MT))+=sizeof(int);
    int dimL = m-l+1;
    (*(*MT))+=sizeof(int);
    int dimR = r - m;
    (*(*MT))+=sizeof(vetor);
    (*(*MT))+=sizeof(vetor);
    vetor L[dimL], R[dimR];

    (*(*MT))+=sizeof(int);
    (*(*MT))+=sizeof(int);
    (*(*MT))+=sizeof(int);
    int i, j, k;//Indices
    //Cópia das posições específicas do vetor principal para os vetores auxiliares
    for(i = 0; i < dimL; i++){
        L[i] = arr[l+i];
        (*(*NOC))++;
    }
    for(j = 0; j < dimR; j++){
        R[j] = arr[m+1+j];
        (*(*NOC))++;
    }


    i = 0; j = 0, k = l;
    while(i < dimL && j < dimR){//Realização das trocas e comparações

        (*(*NOC))++;
        if(L[i].nome[0] <= R[j].nome[0]){
            (*(*NOC))++;
            if(L[i].nome[0]==R[j].nome[0]){
                for(int l=0; l<40; l++){//Comparação de todas as letras do nome

                    (*(*NOC))++;
                    if(L[i].nome[l]==R[j].nome[l]){//Usa a mesma logica dos primeiros "if-else" do "while" que estamos

                        (*(*NOC))++;
                        if(L[i].nome[l+1] < R[j].nome[l+1]){
                            (*(*NOT))++;
                            arr[k] = L[i];
                            i++;
                        }

                        (*(*NOC))++;
                        if(L[i].nome[l+1] > R[j].nome[l+1]){
                            (*(*NOT))++;
                            arr[k] = R[j];
                            j++;
                        }

                    }
                    else{//Caso o caracter comparado seja diferente
                        break;
                    }
                    (*(*NOC))++;
                }
                
            }
            else{//Caso o num seja menor que o outro
                (*(*NOT))++;
                arr[k] = L[i];
                i++;
            }
        }else{//Caso o num seja maior
            (*(*NOT))++;
            arr[k] = R[j];
            j++;
        }
        k++;
        (*(*NOC))++;
    }

    while(i < dimL){//Caso sobre mais jogadores no vetor auxiliar L
        arr[k] = L[i];
        i++;
        k++;
        (*(*NOC))++;
    }

    while(j < dimR){//Caso sobre mais jogadores no vetor auxiliar R
        arr[k] = R[j];
        j++;    
        k++;
        (*(*NOC))++;
    }
}
void mergeSort(vetor arr[], int l, int r, unsigned long int *MT, int *NOC, int *NOT){

    (*NOC)++;
    if (l < r) {//Caso a partição do vetor ainda tenha mais de um elemento

        (*MT)+=sizeof(int);
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, MT, NOC, NOT);//"Quebra" do vetor no sentido da esquerda
        mergeSort(arr, m + 1, r, MT, NOC, NOT);//"Quebra" do vetor no sentido da direita

        merge(arr, l, m, r, &MT, &NOC, &NOT);//Comparação e troca dos dados
    }
}