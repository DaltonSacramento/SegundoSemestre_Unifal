#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define capacity 10
int heap_size=0;

int parent(int i){
    int var;
    var=(i-1)/2;
    return var;
}

void swap(int *vetor, int *vetor2){
    int aux = *vetor;
    *vetor = *vetor2;
    *vetor2 = aux;
}

void insercao(int k, int vetor[]){
    if(heap_size==capacity){
        printf("\nOverflow:Could not insertkey");
        return;
    }
    heap_size=heap_size+1;
    int i=heap_size-1;
    vetor[i]=k;
    
    while(i!=0 && vetor[parent(i)]>vetor[i]){
        swap(&vetor[i],&vetor[parent(i)]);
        i=parent(i);
    }
}

int left(int k){
    int var;
    var=(2*k)+1;
    return var;
}

int right(int k){
    int var;
    var=(2*k)+2;
    return var;
}

void remover(int k, int vetor[]){

    int l=left(k);
    int r=right(k);
    int smallest=k;
    if(l<heap_size && vetor[l]<vetor[k]){
        smallest=l;
    }
    if(r<heap_size && vetor[r]<vetor[smallest]){
        smallest=r;
    }
    if(smallest!=k){
        swap(&vetor[k],&vetor[smallest]);
        remover(smallest,vetor);
    }
}

int minimizar(int vetor[]){
    if(heap_size<=0){
        return INT_MAX;
    }
    if(heap_size==1){
        heap_size=heap_size-1;
        return vetor[0];
    }

    int root=vetor[0];
    vetor[0]=vetor[heap_size-1];
    heap_size--;
    remover(0,vetor);

    return root;
}

int main(){

    int vetor[capacity];

    int k;


    int opçao;
    do{
        printf("\nDigite a opçao: ");
        scanf("%d", &opçao);
        switch(opçao){
            case 1:
                printf("\nDigite o valor a inserir: ");
                scanf("%d",&k);
                insercao(k,vetor);
                break;

            case 2:
                minimizar(vetor);
                break;
        }
    }while(opçao!=0);



    printf("\n");
    for(int i=0;i<heap_size;i++){
        printf(" %d", vetor[i]);
    }
    printf("\n");



    return 0;
}