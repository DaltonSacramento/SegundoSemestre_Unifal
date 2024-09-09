#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int valor;
    int chave;
    struct no *prox;
}no;


void insereenc(no *novo, no **topo){
    (*novo).prox=(*topo);
    (*topo)=novo;
}


no *removeenc(no **topo){
    no *remove1=NULL;
    if(topo!=NULL){
        remove1=(*topo);
        (*topo)=(*(*topo)).prox;
    }
    return remove1;
}


int main(){

no *topo=malloc(sizeof(no));
topo=NULL;


int x;
do{
    printf("\nDigite a opção: ");
    scanf("%d", &x);
    switch(x){
            
        case 2:
            no *novo=malloc(sizeof(no));
            printf("\nChave do novo no: ");
            scanf("%d", &(*novo).chave);
            insereenc(novo,&topo);
            printf("\nRetorno: %d", (*topo).chave);
            break;

        case 3:
            no *retornera=removeenc(&topo);
            if(retornera==NULL){
                printf("\nNULO");
            }
            else{
                printf("\nRetorno: %d", (*retornera).chave);
            }
        
            break;
    }

}while(x!=0);


no *i=topo;
while(i!=NULL){
    printf(" %d", (*i).chave);
    i=(*i).prox;
}
printf("\n");



}