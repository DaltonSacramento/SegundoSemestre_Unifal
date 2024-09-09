#include <stdlib.h>
#include <stdio.h>

int main(){

    // criando a variável ponteiro para o arquivo
    FILE *pontarq;
  
    //abrindo o arquivo
    pontarq = fopen("labirinto1.txt", "r");
    
    if (pontarq == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    char c[10][10];
    for (int i = 0; i < 10; i++) {
        for (int y = 0; y <= 10; y++) {
            c[i][y] = getc(pontarq);
            // Verificar se chegou ao fim do arquivo
            if (c[i][y] == EOF) {
                break;
            }
            // Exibe o caractere lido na tela
            printf("%c", c[i][y]);  
        }
    }
    printf("\n");

    char aux[10][10];
    for (int i = 0; i < 10; i++) {
        for (int y = 0; y <= 10; y++) {
            aux[i][y] = c[i][y];
            // Verificar se chegou ao fim do arquivo
            if (c[i][y] == EOF) {
                break;
            }
        }
    }

    char aux[10][10];
    for (int i = 0; i < 10; i++) {
        for (int y = 0; y <= 10; y++) {
            

            if (aux[i][y] == EOF) {
                break;
            }
        }
    }


    // fechando arquivo
    fclose(pontarq);

    return 0;
}