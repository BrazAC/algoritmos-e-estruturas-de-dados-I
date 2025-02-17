#include <stdlib.h>
#include <stdio.h>
#include "funcoes-pilha-din.h"

tipo_no* criaNo(int novoValor){
    tipo_no *novoNo = (tipo_no*)malloc(sizeof(tipo_no));
    novoNo->valor = novoValor;
    novoNo->proximo = NULL;
    return novoNo;
}

void pilhaDin_insere(tipo_no** prtBase, int novoDado){
    //Criar novo no
    tipo_no *novoNo = criaNo(novoDado);
    //Apontar próximo do novoNo para o antigo topo
    novoNo->proximo = (*prtBase);
    //Apontar ponteiro base para o novoNo
    (*prtBase) = novoNo;

}

int pilhaDin_remove(tipo_no** prtBase){
    if ((*prtBase) == NULL){
        printf("[ERRO] Tentando remover de pilha vazia");
        return -1;
    }

    tipo_no *aux;
    //Fazer copia do no do topo
    aux = (*prtBase);
    int dadoRm = aux->valor;
    //Apontar a base para o novo topo
    *prtBase = aux->proximo;
    //Liberar memoria atigo topo
    free(aux);
    //Retornar dado removido
    return dadoRm;
}

int pilhaDin_mostra(tipo_no** prtBase){
    if ((*prtBase) == NULL) {
        printf("[WARNING] Tentando mostrar de pilha vazia");
        return -1;
    }

    tipo_no *aux = *prtBase;
    while(aux->proximo != NULL){
        printf("[%d]", aux->valor);
        aux = aux->proximo;
    }
    printf("[%d]\n", aux->valor);
    return 0;
}

int pilhaDinRec_mostra(tipo_no** prtBase){
    if ((*prtBase) == NULL) {
        //printf("[WARNING] Tentando mostrar de pilha vazia");
        return -1;
    }

    printf("[%d]", (*prtBase)->valor);
    (*prtBase) = (*prtBase)->proximo;
    pilhaDinRec_mostra(&(*prtBase));

    return 0;
}