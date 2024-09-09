#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int valor;
    int chave;
}no;

int insere(no aux, int M, int *r,int *f, no *F){
    int insere1=-1;
    int prov=((*r)%M)+1;
    if(prov!=(*f)){
        (*r)=prov;
        F[(*r)]=aux;
        insere1=(*r);
        if((*f)==0){
            (*f)=1;
        }
    }
    return insere1;
}

no *remover(int M, int *r,int *f, no *F){
    if (*f == -1) {
        return NULL;  // Queue is empty
    }
    no *remove1 = malloc(sizeof(no));
    if (remove1 != NULL) {
        *remove1 = F[*f];
        if (*f == *r) {  // Queue becomes empty
            *f = -1;
            *r = -1;
        } else {
            *f = (*f + 1) % M;  // Corrected for circular increment
        }
    }
    return remove1;
}

int main(){
    int x, tamanho;

    int num_elementos;

    printf("\nTamanho: ");
    scanf("%d", &tamanho);
    no *F=malloc(tamanho * sizeof(no));
    int r=0;
    int f=0;

    printf("\nnum elementos: ");
    scanf("%d", &num_elementos);

    for(int i=1;i<=num_elementos;i++){
        (*(F + i)).chave=i;
        r++;
        if(i==1){
            f++;
        }
    }
    for(int i=1;i<=tamanho;i++){
        printf(" %d", (*(F + i)).chave);
    }

    x=0;
    do{
        printf("\nDigite o caso: ");
        scanf("%d", &x);
        switch(x){
            case 1:
            /*
                printf("\nChave: ");
                scanf("%d", &z);
                printf("\n%d", busca(z,n));*/
                break;
            
            case 2:
                no aux;
                printf("\nNova estrutura: ");
                printf("\nChave: ");
                scanf("%d", &aux.chave);
                printf("\n%d", insere(aux,tamanho,&r,&f,F));
                break;

            case 3:
                    no *retorno = remover(tamanho, &r, &f, F);
                    if (retorno == NULL) {
                        printf("\nNulo");
                    } else {
                        printf("\nremovido: %d", retorno->chave);
                        free(retorno);
                    }

                break;

        }
    }while(x!=0);

    for(int i=1;i<=tamanho;i++){
        printf(" %d", (*(F + i)).chave);
    }

    free(F);

    return 0;
}