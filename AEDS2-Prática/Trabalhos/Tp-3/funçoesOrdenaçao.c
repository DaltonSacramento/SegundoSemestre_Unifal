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
void bubbleSort(vetor arr[], int n, unsigned long int *MT, int *NOC, int *NOT){
    (*MT)+=sizeof(int);
    int i, j;//Indices

    (*MT)+=sizeof(bool);
    bool swapped;//Variável booleana

    for (i = 0; i < n - 1; i++) {//Repetição para percorrer o vetor
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {  //Repetição para ordenar o vetor "i" vezes
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

    (*MT)+=sizeof(vetor);//Para os swaps do algoritmo
}


//Algoritmo Ótimo de Ordenação MergeSort
void merge(vetor arr[], int l, int m, int r, unsigned long int **MT, int **NOC, int **NOT){
    (*(*MT)) += sizeof(int);
    int dimL = m - l + 1;//dimensao L

    (*(*MT)) += sizeof(int);
    int dimR = r - m;//dimensão R

    // Alocação dinâmica para os vetores auxiliares
    vetor *L = (vetor *)malloc(dimL * sizeof(vetor));
    vetor *R = (vetor *)malloc(dimR * sizeof(vetor));

    (*(*MT)) += dimL * sizeof(vetor);
    (*(*MT)) += dimR * sizeof(vetor);

    (*(*MT)) += sizeof(int);
    (*(*MT)) += sizeof(int);
    (*(*MT)) += sizeof(int);
    int i, j, k;//indices

    // Copia os elementos para os vetores auxiliares
    for (i = 0; i < dimL; i++) {
        L[i] = arr[l + i];
        (*(*NOC))++;
    }
    for (j = 0; j < dimR; j++) {
        R[j] = arr[m + 1 + j];
        (*(*NOC))++;
    }

    i = 0;
    j = 0;
    k = l;

    // Merge dos dois sub-vetores
    while (i < dimL && j < dimR) {
        (*(*NOC))++;

        // Comparação dos primeiros caracteres do nome
        (*(*MT)) += sizeof(int);
        int comp = strncmp(L[i].nome, R[j].nome, 40);

        if (comp <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        (*(*NOT))++;
        k++;
        (*(*NOC))++;

    }

    // Caso ainda restem elementos no vetor L
    while (i < dimL) {
        (*(*NOT))++;
        arr[k] = L[i];
        i++;
        k++;
        (*(*NOC))++;
    }

    // Caso ainda restem elementos no vetor R
    while (j < dimR) {
        (*(*NOT))++;
        arr[k] = R[j];
        j++;
        k++;
        (*(*NOC))++;
    }

    // Libera a memória alocada
    free(L);
    free(R);
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

//Algortimo de tempo linear
// Função para obter o caractere de uma string em uma posição específica
char getCharAt(char *str, int pos, unsigned long int *MT, int *NOC, int *NOT) {
    // Retorna o caractere ou '\0' se a posição ultrapassar o comprimento da string
    (*NOC)++;
    if (pos < strlen(str)) {
        return str[pos]; // Retorna o caractere da posição solicitada
    }
    else {
        return '\0'; // Retorna '\0' se a posição for maior que o comprimento da string
    }
}

// Função para executar o Counting Sort para uma posição específica
void countingSort(vetor arr[], int position, unsigned long int *MT, int *NOC, int *NOT) {
    (*MT)+=sizeof(vetor);
    vetor output[1150]; // Vetor temporário para armazenar o resultado
    (*MT)+=sizeof(int);
    int count[256] = {0}; // Contador para cada caractere

    // Contagem de ocorrências de cada caractere na posição 'position'
    (*MT)+=sizeof(int);
    for (int i = 0; i < 1150; i++) {
        count[getCharAt(arr[i].nome, position, MT, NOC, NOT)]++;
        (*NOC)++;
    }

    // Transformação para posição cumulativa
    (*MT)+=sizeof(int);
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
        (*NOC)++;
    }

    // Construção do vetor ordenado
    (*MT)+=sizeof(int);
    for (int i = 1150 - 1; i >= 0; i--) {
        int index = getCharAt(arr[i].nome, position, MT, NOC, NOT);
        output[count[index] - 1] = arr[i];
        count[index]--;
        (*NOC)++;
        (*NOT)++;
    }

    // Copia o vetor ordenado de volta para o vetor original
    (*MT)+=sizeof(int);
    for (int i = 0; i < 1150; i++) {
        arr[i] = output[i];
        (*NOC)++;
    }
}

// Função principal do Radix Sort
void radixxSort(vetor arr[], int ind, unsigned long int *MT, int *NOC, int *NOT) {
    // Determina o comprimento máximo entre os nomes
    (*MT)+=sizeof(int);
    int maxLen = 0;

    (*MT)+=sizeof(int);
    for (int i = 0; i < ind; i++) {//Repetição para encontrar o comprimento máximo
        (*NOC)++;
        if (strlen(arr[i].nome) > maxLen) {//Calcula o comprimento do nome e compara
            maxLen = strlen(arr[i].nome);
        }
        (*NOC)++;
    }

    // Ordena da posição menos significativa até a mais significativa
    (*MT)+=sizeof(int);
    for (int pos = maxLen - 1; pos >= 0; pos--) {
        countingSort(arr, pos, MT, NOC, NOT);
        (*NOC)++;
    }
}