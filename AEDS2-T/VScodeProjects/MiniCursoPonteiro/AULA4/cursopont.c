#include <stdlib.h>
#include <stdio.h>

void preencher(int *pont, int *n){
    for(int i=0; i<(*n); i++){
        *(pont + i)=i*10;
    }
}

void escever(int *pont, int *n){
    for(int i=0; i<(*n); i++){
        printf("\n%p",(pont + i));
    }
    printf("\n------------------");

    for(int i=0; i<(*n); i++){
        printf("\n%d",*(pont + i));
    }
}

int main(){
    //alocação dinamica de memoria, aritmetica de ponteiros e
    //passagem de oarametro por referencia

    /*O malloc é uma função que aloca uma quantidade me memoria
    desejada e retorna o endereço do inicio da regiao de memoria
    alocada, logo o retorno tem que ser atribuido a um ponteiro*/

    int num_elementos=4;
    int *pont=malloc(num_elementos * sizeof(int));

    /*for(int i=0; i<num_elementos; i++){
        (pont + i);//endereço contido em pont + i*sizeof(int)
    }*/

    preencher(pont,&num_elementos);

    escever(pont,&num_elementos);
    


    //liberação de memoria da regiao alocada
    free(pont);

    return 0;
}