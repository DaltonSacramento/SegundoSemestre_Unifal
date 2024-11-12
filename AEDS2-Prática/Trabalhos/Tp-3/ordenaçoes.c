#include <stdlib.h>
#include <stdio.h>
#include <time.h>


double ord_simples(int instancia_num) {
    double tempo = 0;
    clock_t begin = clock();


    clock_t end = clock();
    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    return (tempo);
}

double ord_otima(int instancia_num) {
    double tempo = 0;
    clock_t begin = clock();


    clock_t end = clock();
    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    return (tempo);
}

double ord_tempolinear(int instancia_num) {
    double tempo = 0;
    clock_t begin = clock();


    clock_t end = clock();
    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    return (tempo);
}

int main(int argc, char* argv[]){

    ///////////////////////////////////////////////////////////
    /////////////////// Leitor de instâncias //////////////////
    ///////////////// Não deve ser modificado /////////////////
    ///////////////////////////////////////////////////////////
    int instancia_num = -1;

    instancia_num = atoi(argv[1]);
    if (instancia_num <= 0 || instancia_num > 10) {
        printf("Para evalecutar o código, digite ./arvores val\nonde val é um número entre 1 e 10 que simboliza a instância utilizada\n");
        return(0);
    }

    double tempo_ord_simples = ord_simples(instancia_num);
    double tempo_ord_otima = ord_otima(instancia_num);
    double tempo_ord_linear = ord_tempolinear(instancia_num);

    return 0;
}