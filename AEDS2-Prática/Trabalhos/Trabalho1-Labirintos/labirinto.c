#include <stdlib.h>
#include <stdio.h>

int main(){
    // criando a variável ponteiro para o arquivo
    FILE *pontarq;
  
    //abrindo o arquivo
    pontarq = fopen("labirinto1.txt", "r");
    
    char c;
    for(int i=1; i<=10; i++){
        for(int y=1; y<=10; y++){
            c = fgetc(pontarq);
    
            //exibe o caracter lido na tela
            printf("%c" , c);  
        }
    }

    // fechando arquivo
    fclose(pontarq);
  
    //mensagem para o usuário
    printf("O arquivo foi criado com sucesso!");
    
    return 0;
}