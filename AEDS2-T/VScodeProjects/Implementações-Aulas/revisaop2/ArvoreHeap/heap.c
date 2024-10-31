#include <stdlib.h>
#include <stdio.h>

int capacity = 10;
int heap_size = 0;

int parent(int i){
    int temp=(i-1)/2;
    return temp;
}

void swap(int *x, int *y){
    int aux=*x;
    *x=*y;
    *y=aux;
}

void insere(int vetor[], int k){
    if(heap_size==capacity){
        return;
    }
    int i=heap_size;
    vetor[heap_size]=k;
    heap_size++;
    while(i!=0 && vetor[parent(i)]>vetor[i]){
        swap(&vetor[parent(i)],&vetor[i]);
        i=parent(i);
    }
}

int left(int k){
    int temp = (k*2)+1;
    return temp;
}

int right(int k){
    int temp = (k*2)+2;
    return temp;
}

void remover(int k, int vetor[]){
    int l = left(k);
    int r = right(k);
    int menor = k;
    if(l<heap_size && vetor[l]<vetor[k]){
        menor=l;
    }
    if(r<heap_size && vetor[r]<vetor[menor]){
        menor=r;
    }
    if(menor!=k){
        swap(&vetor[menor],&vetor[k]);
        remover(menor,vetor);
    }
}

int minimizar(int vetor[]){
    if(heap_size<=0){
        return 0;
    }
    if(heap_size==1){
        heap_size--;
        int temp=vetor[0];
        vetor[0]=0;
        return temp;
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
                insere(vetor,k);
                break;

            case 2://Remoção
                /*Remove sempre a raiz e a substitui pelo ultimo elemento do vetor,
                se a nova raiz for maior que algum dos seus filhos, troca-se de lugar
                com o menor deles
                Essa operação é realizada recursivamente*/
                minimizar(vetor);
                break;

            case 3://Exibição
                printf("\n");
                for(int i=0;i<heap_size;i++){
                    printf(" %d", vetor[i]);
                }
                printf("\n");
                break;
        }

    }while(opçao!=0);

    return 0;
}