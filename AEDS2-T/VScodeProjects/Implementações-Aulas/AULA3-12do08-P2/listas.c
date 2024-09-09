#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int chave;
    int valor;
}no;

/*Funçao de busca em um vetor, comparando as chaves
enquanto percorre todo o vetor, se a chave for encontrada
a condiçao de repetiçao é refutada*/
/*
int busca1(no *L, int x, int *n){
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
*/

int pilhainsere(no N, no *P, int *M, int *topo){
    int insere1=-1;
    if((*topo)<(*M)){   
        (*topo)++;
        (*(P + (*topo))).chave=N.chave;       
        insere1=(*topo);
    }

    return insere1;
}

no * pilhasremover(no *P, int *topo){
    no *retorno=NULL;
    if((*topo)!=0){
        (*topo)--;
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
    int *topo=&num_elementos;
    for(int i=1; i<=(*topo);i++){
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
            /*
                int x;
                printf("\nChave para buscar: ");
                scanf("%d", &x);
                printf("\nRetorno: %d", busca1(L,x,topo));
                break;
                */

            case 2:
                no N;
                printf("\nNova estrutura");
                printf("\nChave nova: ");
                scanf("%d", &N.chave);
                printf("\nRetorno: %d", pilhainsere(N,L,&tamanho,topo));
                break;

            case 3:
                printf("\nggggg");
                pilhasremover(L,topo);
            /*
                no *removido=pilharemover(L,topo);
                if(removido==NULL){
                    printf("\nRetorno: %p", removido);
                }
                else{
                    printf("\nRetorno: %d", (*removido).chave);
                }
                free(removido);
                */
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