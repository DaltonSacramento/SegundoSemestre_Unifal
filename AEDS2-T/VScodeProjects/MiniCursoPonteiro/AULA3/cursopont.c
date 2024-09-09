#include <stdlib.h>
#include <stdio.h>

void triplo(int *n){
    (*n)=(*n)*3;
    printf("\nConteudo apontado por n: %d", *n);
    printf("\nConteudo de n: %p", n);
}

int main(){
    //passagem de parametro por valor x por referencia

    int num1=10;

    //triplo(num1);//passagem de parametro por valor

    triplo(&num1);//por referencia
    printf("\nValor de num1: %d", num1);

    /*O endereço de n e num1 sao diferenetes, por isso
    o valor nao é alterado globalmente*/
    printf("\nEndereço de num1: %p", &num1);


    return 0;
}