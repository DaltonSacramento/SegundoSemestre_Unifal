#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int chave;
    int valor;
}no;

/*Funçao de busca em um vetor, comparando as chaves
enquanto percorre todo o vetor, se a chave for encontrada
a condiçao de repetiçao é refutada*/
int busca1(no *L, int x, int n){
    int busca1=0;
    for(int i=1;i<=n;){
        if((*(L + i)).chave==x){
            busca1=i;
            i=n+1;
        }
        else i++;
    }

    return busca1;
}

int insere(no N, no *L, int n, int *m){
    int insere1;
    if(n>(*m)){
        if((busca1(L,N.chave,n))==0){
            L[(*m)+1]=N;
            (*m)++;
            insere1=(*m);
        }
        else insere1=0;
    }
    else insere1=-1;

    return insere1;
}

no * remover(no *L, int x, int n){
    no *retorno=NULL;
    if(n!=0){
        int indice = busca1(L,x,n);
        if(indice>0){
            retorno=malloc(sizeof(no));
            (*retorno).chave=L[indice].chave;
            for(int i=indice; i<=n;i++){
                L[i]=L[i+1];
            }
            n--;
        }
    }
    return (retorno);
}

int main(){
    int tamanho, num_elementos;
    printf("\nTamanho: ");
    scanf("%d", &tamanho);
    no *L=malloc(tamanho * sizeof(no));

    printf("\nNum elementos: ");
    scanf("%d", &num_elementos);
    for(int i=1; i<=num_elementos;i++){
        (*(L + i)).chave=i;
    }
    for(int i=1; i<=tamanho;i++){
        printf(" %d", (*(L + i)).chave);
    }

    int escolha;
    do{
        printf("\nDigite o caso: ");
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                int x;
                printf("\nChave para buscar: ");
                scanf("%d", &x);
                printf("\nRetorno: %d", busca1(L,x,num_elementos));
                break;

            case 2:
                no N;
                printf("\nNova estrutura");
                printf("\nChave nova: ");
                scanf("%d", &N.chave);
                printf("\nRetorno: %d", insere(N,L,tamanho,&num_elementos));
                break;

            case 3:
                //remover
                printf("\nChave para remover: ");
                scanf("%d", &x);
                no *removido=remover(L,x,num_elementos);
                if(removido==NULL){
                    printf("\nRetorno: %p", removido);
                }
                else{
                    printf("\nRetorno: %d", (*removido).chave);
                }
                free(removido);
                break;
        }
    }while(escolha!=0);

    printf("\n-------------------\n");
    for(int i=1; i<=tamanho;i++){
        printf(" %d", (*(L+i)).chave);
    }

    free(L);
    return 0;
}