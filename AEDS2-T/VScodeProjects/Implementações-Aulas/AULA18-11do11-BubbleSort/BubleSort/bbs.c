#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int TAM=10;

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // Se não houve a troca de elementos
        if (!swapped)
            break;
    }
}

int main(){
    int arr[TAM];
    srand(time(NULL));

    int x;
    do{
        printf("\nDigite o caso: ");
        scanf("%d", &x);
        switch(x){
            case 1://Usuário insere
                int ins;
                for(int i=0; i<10; i++){
                    printf("\nDigite o elemento a inserir no vetor: ");
                    scanf("%d", &ins);
                    arr[i]=ins;
                }
                break;

            case 2://Aleatório
                for(int k=0; k<10; k++){
                    arr[k]=rand()%100;
                }
                break;

            case 3://Exibição
                for(int k=0; k<10; k++){
                    printf("%d ", arr[k]);
                }
                break;

            case 4://Ordenação
                bubbleSort(arr,TAM);
                break;

        }
    }while(x!=0);


    return 0;
}