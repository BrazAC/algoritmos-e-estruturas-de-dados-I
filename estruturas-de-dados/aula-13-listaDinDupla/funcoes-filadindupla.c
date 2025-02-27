#include "funcoes-filadindupla.h"
#include <stdlib.h>
#include <stdio.h>

tipo_no* alocaNo(int novoDado){
    tipo_no *novoNo = (tipo_no*)malloc(sizeof(tipo_no));
    novoNo->dado = novoDado;
    novoNo->prox = NULL;
    novoNo->ant = NULL;

    return novoNo;
}

int listaDinDupla_insereInicio(tipo_no **prt_base, int novoDado){
    if ((*prt_base) == NULL) {
        *prt_base = alocaNo(novoDado);
        return 0;
    }

    tipo_no *aux, *novoNo = alocaNo(novoDado);

    //Conectando novo no
    novoNo->prox = *prt_base;
    novoNo->ant = NULL;
    //Conectando anterior do antigo primeiro ao novo no
    (*prt_base)->ant = novoNo;
    //Conectando o prtBase ao novo primeiro novo
    *prt_base = novoNo;
    return 0;
}

int listaDinDupla_mostrar(tipo_no** prt_base){
    if ((*prt_base) == NULL) {
        printf("[WARNING] Tentando mostrar lista vazia");
        return -1;
    }

    tipo_no *aux = *prt_base;
    while (aux->prox != NULL)
    {
        printf("[%d]", aux->dado);
        aux=aux->prox;
    }
    printf("[%d]\n", aux->dado);
    
}

int listaDinDupla_inserePos(tipo_no **prt_base, int novoDado, int posicao){
    if ((*prt_base) == NULL) {
        *prt_base = alocaNo(novoDado);
    }

    posicao --;
    int cont = 0;
    tipo_no *aux = *prt_base;

    while (aux->prox != NULL && cont < posicao) {
        aux = aux->prox;
        cont ++;
    }

    if (cont == (posicao - 1)) {
        //Inserir no final
        listaDinDupla_insereFinal(prt_base, novoDado);
    }
    else if (cont == posicao){
        //Inserir na posicao
        tipo_no *novoNo;
        novoNo->prox = aux;
        novoNo->ant = aux->ant;

        novoNo->prox->ant = novoNo;
        novoNo->ant->prox = novoNo;
    }
    else {
        //Erro, posicao fora dos limites
    }
}