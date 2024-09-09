#include <stdlib.h>
#include <stdio.h>

int main(){
    //variaveis x variaveis ponteiro
    int num1=10;

    /*
    *O conteudo de pont1 é o endereço atribuído a ele,
    *já o conteúdo de *pont1, é o conteúdo da variável
    *apontada pelo pont1;
    */
    int *pont1;
    //pont1=num1;//errado
    pont1=&num1;

    //conteudo
    printf("\n%d", num1);

    //endereço
    printf("\n%p", &num1);


    return 0;
}