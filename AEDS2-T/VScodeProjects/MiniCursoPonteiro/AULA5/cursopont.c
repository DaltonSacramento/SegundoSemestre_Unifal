#include <stdlib.h>
#include <stdio.h>

int main(){
    //relação entre ponteiros e dimensões

    int num_colunas=4;
    int num_linhas=2;

    int **pont;

    pont=malloc(num_linhas * sizeof(int *));

    //alocação das linhas e inicialização da matriz
    for(int i=0; i<num_linhas; i++){
        *(pont + i)=malloc(num_colunas * sizeof(int));
        for(int j=0; j<num_colunas; j++){
            *(*(pont + i) + j) = i+j;
        }
    }
    
    //escrita da matriz
    for(int i=0; i<num_linhas; i++){
        for(int j=0; j<num_colunas; j++){
            printf("%4d", *(*(pont + i) + j));
        }
        printf("\n");
    }
    printf("\n");


    //liberação de memoria da regiao alocada
    for(int i=0; i<num_linhas; i++){
        free(*(pont + i));
    }
    free(pont);

    return 0;
}