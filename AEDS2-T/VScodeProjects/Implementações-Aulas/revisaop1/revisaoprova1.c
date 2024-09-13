#include <stdlib.h>
#include <stdio.h>

typedef struct encadeada{
    int chave;
    struct encadeada *prox;
}enc;
//--------------------------------------
typedef struct sequencial{
    int chave;
}simples;
//---------------------------------------------
typedef struct DPE{
    int chave;
    struct DPE *ant;
    struct DPE *post;
}DPE;
//------------------------------------------------
int busca1(simples L[],int x, int n){
    for(int i=0; i<n; i++){
        if(L[i].chave==x){
            return i;
        }
    }
    return -1;
}
//---------------------------------------------------------------------------------------
int busca(simples L[], int x, int n){
    L[n].chave=x;
    int i=0;
    while(L[i].chave!=x){
        i++;
    }
    if(i==n){
        return -1;
    }
    else return i;
}
//---------------------------------------------------------------------------------------
int busca_ord(simples L[], int x, int n){
    L[n].chave=x;
    int i=0;
    while(L[i].chave<x){
        i++;
    }
    if(i==n || L[i].chave>x){
        return -1;
    }
    else return i;
}
//---------------------------------------------------------------------------------------
int busca_bin(simples L[], int x, int n){
    int inf=0, sup=n-1;
    int meio;
    while(inf<=sup){
        meio=(inf+sup)/2;
        if(L[meio].chave==x){
            return meio;
        }
        if(L[meio].chave>x){
            sup=meio-1;
        }
        else inf=meio+1;
    }
    return -1;
}
//---------------------------------------------------------------------------------------
int insertionListaS(simples L[], simples novo, int n, int M){
    if(n<M){
        int indice = busca1(L,novo.chave,n);
        if(indice ==-1){
            L[n]=novo;
            n++;
            return n;
        }
    }
    return -1;
}
simples *removeListaS(simples L[],int x, int n){
    simples *exclude=NULL;
    if(n>0){
        int indice=busca1(L,x,n);
        if(indice!=-1){
            exclude=malloc(sizeof(simples));
            *exclude=L[indice];
            n--;
            for(int i=indice;i<=n;i++){
                L[i]=L[i+1];
            }
        }
    }
    return exclude;
}
//---------------------------------------------------------------------------------------
int insertionPilhaS(simples P[], simples novo, int *topo, int M){
    if((*topo)<M){
        P[(*topo)]=novo;
        (*topo)++;
        return (*topo);
    }
    return -1;
}
simples *removePilhaS(simples P[], int *topo){
    simples *exclude=NULL;
    if((*topo)>-1){
        exclude=malloc(sizeof(simples));
        *exclude=P[(*topo)];
        (*topo)--;
    }
    return exclude;
}
//---------------------------------------------------------------------------------------
int insertionFilaS(simples F[], simples novo, int *f, int *r, int M){
    int prov=((*r)+1)%M;
    if(prov!=(*f)){
        F[(*r)]=novo;
        (*r)=prov;
        if((*f)==-1){
            (*f)=(*r);
        }
        return (*r);
    }
    return -1;
}
simples *removeFilaS(simples F[], int *f, int *r, int M){
    simples *exclude=NULL;
    if((*f)!=-1){
        exclude=malloc(sizeof(simples));
        *exclude=F[(*f)];
        if((*f)==(*r)){
            (*f)=-1;
            (*r)=-1;
        }
        else (*f)=((*f)+1)%M;
    }
    return exclude;
}
//---------------------------------------------------------------------------------------
void busca_enc(enc *ptlista, enc **ant, enc **pont, int x){
    *ant=ptlista;
    *pont=NULL;
    enc *ptr=(*ptlista).prox;
    while(ptr!=NULL){
        if((*ptr).chave<x){
            *ant=ptr;
            ptr=(*ptr).prox;
        }
        else{
            if((*ptr).chave==x){
                *pont=ptr;
            }
            ptr=NULL;
        }
    }
}
int insertionListaE(enc *ptlista, enc *novo){
    enc *ant=NULL;
    enc *pont=NULL;
    busca_enc(ptlista,&ant,&pont,(*novo).chave);
    if(pont==NULL){
        (*novo).prox=(*ant).prox;
        (*ant).prox=novo;
        return 0;       
    }
    return -1;
}
enc *removeListaE(enc *ptlista, int x){
    enc *ant;
    enc *pont;
    busca_enc(ptlista,&ant,&pont,x);
    if(pont!=NULL){
        (*ant).prox=(*pont).prox;
        return pont;
    }
    return NULL;
}
//-------------------------------------------------------------
void inserePilhaE(enc **topo, enc *novo){
    (*novo).prox=(*topo);
    (*topo)=novo;
}
enc *removePilhaE(enc **topo){
    enc *exclude=NULL;
    if((*topo)!=NULL){
        exclude=(*topo);
        (*topo)=(*(*topo)).prox;
    }
    return exclude;
}
//----------------------------------------------------------------
void insereFilaE(enc **inicio,enc **fim,enc *novo){
    if((*fim)!=NULL){
        (*(*fim)).prox=novo;
    }
    else (*inicio)=novo;
    (*fim)=novo;
}
enc *removeFilaE(enc **inicio,enc **fim){
    enc *exclude=NULL;
    if((*inicio)!=NULL){
        exclude=(*inicio);
        (*inicio)=(*(*inicio)).prox;
        if((*inicio)==NULL){
            (*fim)=NULL;
        }
    }
    return exclude;
}
//---------------------------------------------------------------
DPE *buscaListaDE(DPE *ptlista,int x){
    DPE *ultimo=(*ptlista).ant;
    if(ultimo != ptlista && x<=(*ultimo).chave){
        DPE *pont=(*ptlista).post;
        while((*pont).chave<x){
            pont=(*pont).post;
        }
        return pont;
    }
    return ptlista;
}
DPE *insereListaDE(DPE *ptlista, DPE *novo){
    DPE *pont=buscaListaDE(ptlista,(*novo).chave);
    if(pont==ptlista || (*pont).chave!=(*novo).chave){
        DPE *anterior=(*pont).ant;
        (*novo).post=pont;
        (*novo).ant=(*pont).ant;
        (*anterior).post=novo;
        (*pont).ant=novo;
        return NULL;
    }
    return pont;
}
DPE *removeListaDE(DPE *ptlista,int x){
    DPE *exclude=NULL;
    if((*ptlista).post!=NULL){
        DPE *pont=buscaListaDE(ptlista,x);
        if((*pont).chave==x){
            exclude=pont;
            DPE *anterior=(*pont).ant;
            DPE *posterior=(*pont).post;
            (*anterior).post=(*pont).post;
            (*posterior).ant=(*pont).ant;
        }

    }
    return exclude;
}








int main(){

    //Alocação Sequencial
    int M=10;
    int n=0, z;
    simples L[M];
    simples P[M];
    int topo;
    simples F[M];
    int f,r;
    for(int i=0;i<M;i++){
        L[i].chave=0;
    }
    for(int i=0;i<M;i++){
        P[i].chave=0;
    }
    for(int i=0;i<M;i++){
        F[i].chave=0;
    }

    //Alocação Encadeada
    enc *ptlista=malloc(sizeof(enc));
    (*ptlista).prox=NULL;
    enc *topera=NULL;
    enc *fim=NULL;
    enc *inicio=NULL;
    DPE *ptlistaDE=malloc(sizeof(DPE));
    (*ptlistaDE).post=ptlistaDE;
    (*ptlistaDE).ant=ptlistaDE;


    int x;
    do{
        printf("\nDigite o caso: ");
        scanf("%d", &x);
        switch(x){
            //Buscas
            case 1://Busca1
                printf("\nValor: ");
                scanf("%d", &z);
                printf("\nRetorno busca1: %d", busca1(L,z,n));
                break;
            case 2://Busca
                printf("\nValor: ");
                scanf("%d", &z);
                printf("\nRetorno busca: %d", busca1(L,z,n));
                break;
            case 3://Busca Ordenada
                printf("\nValor: ");
                scanf("%d", &z);
                printf("\nRetorno busca-ord: %d", busca_ord(L,z,n));
                break;
            case 4://Busca Binária
                printf("\nValor: ");
                scanf("%d", &z);
                printf("\nRetorno busca-bin: %d", busca_bin(L,z,n));
                break;
            //-----------------------------------------------------
            //Lista Simples
            case 5://Insertion
                simples novo;
                printf("\nNovo no: ");
                scanf("%d", &novo.chave);
                printf("\nRetorno insertionListaS: %d", insertionListaS(L,novo,n,M));
                n++;
                break;
            case 6://Remove
                int y;
                printf("\nChave remover: ");
                scanf("%d", &y);
                simples *retorno=removeListaS(L,y,n);
                if(retorno==NULL){
                    printf("\nNULO removeListaS");
                }
                else printf("\nRetorno removeListaS: %d", (*retorno).chave);
                break;
            //-------------------------------------------------------
            //Pilha Simples
            case 7://Insertion
                printf("\nNovo no: ");
                scanf("%d", &novo.chave);
                printf("\nRetorno insertionPilhaS: %d", insertionPilhaS(P,novo,&topo,M));
                break;
            case 8://Remove
                retorno=removePilhaS(P,&topo);
                if(retorno==NULL){
                    printf("\nNULO removePilhaS");
                }
                else printf("\nRetorno removePilhaS: %d", (*retorno).chave);
                break;
            //------------------------------------------------------
            //Fila Simples
            case 9://Insertion
                printf("\nNovo no: ");
                scanf("%d", &novo.chave);
                printf("\nRetorno insertionFilaS: %d", insertionFilaS(F,novo,&f,&r,M));
                break;
            case 10://Remove
                retorno=removeFilaS(F,&f,&r,M);
                if(retorno==NULL){
                    printf("\nNULO removeFilaS");
                }
                else printf("\nRetorno removeFilaS: %d", (*retorno).chave);
                break;
            case 11://Exibir todas sequenciais
                printf("\nLista\n");
                for(int i=0;i<n;i++){
                    printf(" %d",L[i].chave);
                }
                printf("\nPilha\n");
                for(int i=0;i<topo;i++){
                    printf(" %d",P[i].chave);
                }
                printf("\nFila\n");
                for(int i=f;i<r;i++){
                    printf(" %d",F[i].chave);
                }
                printf("\n");
                break;
            //--------------------------------------------------------
            //Lista Encadeada
            case 12://Insertion
                enc *newLE=malloc(sizeof(enc));
                printf("\nNovo no: ");
                scanf("%d", &(*newLE).chave);
                printf("\nRetorno insertionListaE: %d", insertionListaE(ptlista,newLE));
                break;
            case 13://Remove
                int k;
                printf("\nChave remover: ");
                scanf("%d", &k);
                enc *retornoLE=removeListaE(ptlista,k);
                if(retornoLE==NULL){
                    printf("\nNULO removeListaE");
                }
                else{
                    printf("\nRetorno removeListaE: %d", (*retornoLE).chave);
                }
                break;
            //--------------------------------------------------------
            //Pilha Encadeada
            case 14://Insertion
                enc *newPE=malloc(sizeof(enc));
                printf("\nNovo no: ");
                scanf("%d", &(*newPE).chave);
                inserePilhaE(&topera,newPE);
                printf("\nInserido");
                break;
            case 15://Remove
                enc *retornoPE=removePilhaE(&topera);
                if(retornoPE==NULL){
                    printf("\nNULO removePilhaEnc");
                }
                else{
                    printf("\nRetorno removePilhaE: %d", (*retornoPE).chave);
                }
                break;
            //-------------------------------------------------------------
            //Fila Encadeada
            case 16:
                enc *newFE=malloc(sizeof(enc));
                printf("\nNovo no: ");
                scanf("%d", &(*newFE).chave);
                insereFilaE(&inicio,&fim,newFE);
                printf("\nInserido");
                break;
            case 17:
                enc *retornoFE=removeFilaE(&inicio,&fim);
                if(retornoFE==NULL){
                    printf("\nNULO removeFilaEnc");
                }
                else{
                    printf("\nRetorno removeFilaE: %d", (*retornoFE).chave);
                }
                break;
            case 18://Exibir Encadeadas
                printf("\nLista Enc\n");
                for(enc *i=(*ptlista).prox;i!=NULL;){
                    printf(" %d", (*i).chave);
                    i=(*i).prox;
                }
                printf("\nPilha Enc\n");
                for(enc *i=topera;i!=NULL;){
                    printf(" %d", (*i).chave);
                    i=(*i).prox;
                }
                printf("\nFila Enc\n");
                enc *i=inicio;
                while(i!=fim){
                    printf(" %d", (*i).chave);
                    i=(*i).prox;
                }
                printf(" %d", (*i).chave);
                printf("\n");
                break;
            //-------------------------------------------------------------
            //Lista Duplamente Encadeada
            case 19://Buscar
                printf("\nChave para buscar: ");
                scanf("%d", &k);
                DPE *retornoBLDE=buscaListaDE(ptlistaDE,k);
                printf("\nRetorno: %d", (*retornoBLDE).chave);
                break;
            case 20://Inserir
                DPE *auxDE=malloc(sizeof(DPE));
                printf("\nNova estrutura: ");
                printf("\nChave: ");
                scanf("%d", &(*auxDE).chave);
                DPE *retornoILDE=insereListaDE(ptlistaDE,auxDE);
                if(retornoILDE==NULL){
                    printf("\nInserido");
                }
                else{
                    printf("\nNao inserido, retorno posterior: %d", (*retornoILDE).chave);
                }
                break;
            case 21://Remover
                int w;
                printf("\nChave para remover: ");
                scanf("%d", &w);
                DPE *retornera = removeListaDE(ptlistaDE,w);
                if (retornera == NULL) {
                    printf("\nNulo");
                } else {
                    printf("\nRemovido: %d", (*retornera).chave);
                    
                }
                break;
            case 22://Exibir Dupla Encadeada
                for(DPE *i=(*ptlistaDE).post;i!=ptlistaDE;){
                    printf(" %d", (*i).chave);
                    i=(*i).post;
                }
                break;
        }
    }while(x!=0);


    return 0;
}