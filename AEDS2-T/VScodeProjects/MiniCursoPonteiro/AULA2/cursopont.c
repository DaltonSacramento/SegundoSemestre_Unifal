#include <stdlib.h>
#include <stdio.h>

int main(){
    //variaveis ponteiro de ponteiro
    int num1=10;
    /*Variaveis ponteiro de ponteiro armazenam endereço
    de variaveis ponteiro, que por sua vez armazenam 
    endereço de variaveis comuns*/
    int *pont1=&num1;
    int **pont2=&pont1;

    //conteudo de pont2==endereço de pont1
    printf("\n%p", pont2);
    printf("\n%p", &pont1);
    printf("\n-----------");

    //pont2 aponta para o endereço armazenado
    //*pont2==pont1==&num1
    printf("\n%p", *pont2);
    printf("\n%p", &num1);

    //*pont1==num1
    printf("\n%d", *pont1);
    printf("\n%d", num1);

    //**pont2==*pont1==num1
    printf("\n%d", **pont2);



    return 0;
}