/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Pichau
 *
 * Created on 10 de agosto de 2024, 19:28
 */

#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <string>
#include <valarray>


using namespace std;

typedef struct{
    int chave;
    int valor;
}ff;

ff v[1000];

void funçaoescrita(int tam){
    int x, y;
    y=1;
    for(x=1;x<=tam;x++,y++){
        v[x].chave=y;
    }
    
    for(x=1;x<=tam;x++){
        printf(" %d", v[x].chave);
    }
}

int funçaobusca1(int tam, int z){
    int i, busca1;
    busca1=0;
    for(i=1;i<=tam;){
        if(v[i].chave==z){
            busca1=i;
            i=tam+1;
        }
        else{
            i++;
        }
    }
    return busca1;
}

int funçaobusca2(int tam, int z){
    int i, busca1;
    
    v[tam+1].chave=z;
    busca1=0;
    for(i=1;v[i].chave!=z;){
        i++;
    }
    if(i!=(tam+1)){
        busca1=i;
    }
    else busca1=0;
    
    return busca1;
}

int buscaord(int tam, int z){
    int i, busca1;
    
    v[tam+1].chave=z;
    for(i=1;v[i].chave<z;){
        i++;
    }
    if(i==tam+1 || v[i].chave!=z){
        busca1=0;
    }
    else{
        busca1=i;
    }
    
    return busca1;
}

/*
 * Função para buscar um valor a partir do meio
 */
int buscabin(int tam, int z){
    int i, buscabin, inf, sup, meio;
    
    sup=tam;
    buscabin=0;
    for(inf=1;inf<=sup;){
        meio=((inf+sup)/2);
        if(v[meio].chave==z){
            buscabin=meio;
            inf=sup+1;
        }
        else{
            if(v[meio].chave<z){
                inf=meio+1;
            }
            else{
                sup=meio-1;
            }
        }
    }
    
    return buscabin;
}

/*
 * 
 */
int main(int argc, char** argv) {
        
    int x, y, z, num, tam;
    
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &tam);
    
    funçaoescrita(tam);
    
    printf("\nDigite a chave que deseja buscar no vetor: ");
    scanf("%d", &num);
    
    printf("\n %d", funçaobusca1(tam,num));
    printf("\n %d", funçaobusca2(tam,num));
    printf("\n %d", buscaord(tam,num));
    printf("\n %d", buscabin(tam,num));

    return 0;
}

