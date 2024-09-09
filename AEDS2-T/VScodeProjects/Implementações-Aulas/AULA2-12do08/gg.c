#include <stdlib.h>
#include <stdio.h>


typedef struct{
    int chave;
    int valor;
}ff;
ff vetor[1000];
ff aux;
ff remove1;

int x, y, z, i, busca1, n, m;
int *chave, *tama;

int busca(int ch, int n){
    i=1;
    busca1=-1;
    for(;i<=n;){
        if(vetor[i].chave==ch){
            busca1=i;
            i=n+1;
        }
        else i++;
    }
    return busca1;
}

int funçaobusca2(int tam, int z){
    int i, busca1;
    
    vetor[tam+1].chave=z;
    busca1=0;
    for(i=1;vetor[i].chave!=z;){
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
    
    vetor[tam+1].chave=z;
    for(i=1;vetor[i].chave<z;){
        i++;
    }
    if(i==tam+1 || vetor[i].chave!=z){
        busca1=0;
    }
    else{
        busca1=i;
    }
    
    return busca1;
}

int buscabin(int tam, int z){
    int buscabin, inf, sup, meio;
    
    sup=tam;
    buscabin=0;
    for(inf=1;inf<=sup;){
        meio=((inf+sup)/2);
        if(vetor[meio].chave==z){
            buscabin=meio;
            inf=sup+1;
        }
        else{
            if(vetor[meio].chave<z){
                inf=meio+1;
            }
            else{
                sup=meio-1;
            }
        }
    }
    
    return buscabin;
}

int insere(ff aux, int m, int n){
    int insere1=0;
    if(n>m){
        if(busca(aux.chave,n)==0){
            vetor[m+1]=aux;
            m++;
            insere1=m;
        }
        else insere1=0;
    }
    else insere1=-1;
    return insere1;
}
/*
ff * remove(int ){
    int ch=5;
    int n=10;
    int indice;
    ff *remover = NULL;
    if(n!=0){
        indice=busca(ch,n);
        if(indice!=0){
            *remover=vetor[indice];
            for(i=indice; i<=n-1;i++){
                vetor[i]=vetor[i+1];
            }
            n--;
            return *remover;
        }
        else return *remover;
    
    }
    else return *remover;
}
*/

ff * remover(int ch, int n){
    ff * retorno=NULL;
    if(n!=0){
        int indice=busca(ch,n);
        if(indice>=0){
            retorno=(ff*)malloc(sizeof(ff));
            (*retorno).chave=vetor[indice].chave;
            for(int i=indice;i<=(n-2);i++){
                vetor[i]=vetor[i+1];
            }
            n--;
        }
    }
    return NULL;
}


int main(){

    printf("\nTamanho: ");
    scanf("%d", &n);
    printf("\nNumero de elementos do vetor: ");
    scanf("%d", &m);
    for(x=1,y=1; x<=m; x++, y++){
        vetor[x].chave=y;
    }
    for(x=1; x<=n; x++){
        printf(" %d", vetor[x].chave);
    }
    

    x=0;
    do{
        printf("\nDigite o caso: ");
        scanf("%d", &x);
        switch(x){
            case 1:
                printf("\nChave: ");
                scanf("%d", &z);
                printf("\n%d", busca(z,n));
                break;
            
            case 2:
                printf("\nNova estrutura: ");
                printf("\nChave: ");
                scanf("%d", &aux.chave);
                printf("\n%d", insere(aux,m,n));
                if(insere(aux,m,n)>0){
                    m++;
                }
                break;

            case 3:
                
                printf("\nChave para excluir: ");
                scanf("%d", &z); 
                ff * ff_removido=remover(z,n);
                if((ff_removido==NULL)){
                    printf("\ngg easy");
                }
                free(ff_removido);
                break;

            case 4:
                printf("\nChave: ");
                scanf("%d", &z);
                printf("\n%d", funçaobusca2(n,z));
                break;

            case 5:
                printf("\nChave: ");
                scanf("%d", &z);
                printf("\n%d", buscaord(n,z));
                break;

            case 6:
                printf("\nChave: ");
                scanf("%d", &z);
                printf("\n%d", buscabin(n,z));
                break;

        }
    }while(x!=0);

    return 0;
}