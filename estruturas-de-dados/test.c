#include <stdlib.h>
#include <stdio.h>

typedef struct tipo_no{
    int dado;
    struct tipo_no *proximo;
} tipo_no;

tipo_no* criaNo(int);

void pilhaDin_insere(tipo_no**, int);
int pilhaDin_remove(tipo_no**);
int pilhaDin_mostra(tipo_no**);

int main(){
    tipo_no *prtBase;
    prtBase = NULL;

    pilhaDin_insere(&prtBase, 8);
    pilhaDin_insere(&prtBase, 12);
    pilhaDin_insere(&prtBase, 24);
    pilhaDin_mostra(&prtBase);



    return 0;
}

tipo_no* criaNo(int novoDado){
    tipo_no* novoNo = (tipo_no*)malloc(sizeof(tipo_no));
    novoNo->dado = novoDado;
    novoNo->proximo = NULL;

    return novoNo;
}

void pilhaDin_insere(tipo_no** prtBase, int novoDado){
    tipo_no *novoNo = criaNo(novoDado);
    novoNo->proximo = (*prtBase);
    (*prtBase) = novoNo;
}

int pilhaDin_remove(tipo_no** prtBase){
    if ((*prtBase) == NULL) {
        return -1;
    }

    tipo_no *aux = (*prtBase);
    int dadoRm = aux->dado;

    (*prtBase) = aux->proximo;
    free(aux);
    return dadoRm;
}

int pilhaDin_mostra(tipo_no** prtBase){
    if ((*prtBase) == NULL) {
        return -1;
    }

    tipo_no *aux = (*prtBase);
    while(aux->proximo != NULL){
        printf("[%d]", aux->dado);
        aux = aux->proximo;
    }
    printf("[%d]\n", aux->dado);
}