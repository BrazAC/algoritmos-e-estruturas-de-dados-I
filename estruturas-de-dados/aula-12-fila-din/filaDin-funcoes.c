#include "filaDin-funcoes.h"
#include <stdlib.h>
#include <stdio.h>

//Visualizar
int filaDin_mostra(tipo_no *primeiroNo){
    if (primeiroNo == NULL) {
        printf("[AVISO] Tentando mostrar fila vazia\n");
        return -1;
    }

    tipo_no *aux = primeiroNo;
    while (aux->prox != NULL)
    {
        printf("[%d]", aux->dado);
        aux = aux->prox;
    }
    printf("[%d]\n", aux->dado);
    
}

//Inserir
int filaDin_insereInicio(tipo_no** prtBase, int novoDado){ //CORRIGIR
    if ((*prtBase) == NULL) {
        *prtBase = criaNo(novoDado);
        return 0;
    }

    tipo_no *novoNo = criaNo(novoDado);
    novoNo->prox = (*prtBase);
    (*prtBase) = novoNo;
}

int filaDin_insereFinal(tipo_no** prtBase, int novoDado){ //PRONTO
    if ((*prtBase) == NULL) {
        *prtBase = criaNo(novoDado);
        return 0;
    }

    tipo_no *aux = (*prtBase);
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    
    aux->prox = criaNo(novoDado);
    
}

int filaDin_inserePos(tipo_no** prtBase, int novoDado, int posicao){ //CORRIGIR
    tipo_no *aux = (*prtBase), *auxa, *novoNo;
    posicao --;

    //Se lista estiver vazia
    if ((*prtBase) == NULL) {
        if (posicao != 0) {
            printf("[ERRO] Tentando inserir em posicao fora dos limites\n");
            return -1;
        }

        *prtBase = criaNo(novoDado);
        //Ou chamar funcao inserir no inicio
        return 0;
    }

    //Avancar ate a posicao 
    int cont = 0;
    while (cont < posicao && aux->prox != NULL)
    {
        auxa = aux;
        aux = aux->prox;
        cont ++;
    }

    //TODO: DEVE SUPORTAR INSERIR NO ELEMENTO DE POSICAO N, NAO APENAS ATE O N-1
    //Se a posicao estiver fora dos limites
    if (cont < posicao){
        printf("[ERRO] Tentando inserir em posicao fora dos limites\n");
        return -1;
    } 

    //auxa apontando pra o anterior ao alvo
    //aux apontando para o alvo
    novoNo = criaNo(novoDado);
    novoNo->prox = aux;
    auxa->prox = novoNo;
}

tipo_no* criaNo(int novoDado){
    tipo_no *novoNo = (tipo_no*)malloc(sizeof(tipo_no));
    novoNo->dado = novoDado;
    novoNo->prox = NULL;

    return novoNo;
}

//Remover
int filaDin_removeInicio(tipo_no **prtBase){
    if ((*prtBase) == NULL) {
        printf("[ERRO] Tentando retirar de lista vazia\n");
        return -1;
    }

    tipo_no *aux = *prtBase;
    int dadoRm = (*prtBase)->dado;

    (*prtBase) = (*prtBase)->prox;
    free(aux);
    return dadoRm;
}

int filaDin_removeFim(tipo_no** prtBase){
    if ((*prtBase) == NULL) {
        printf("[ERRO] Tentando retirar de lista vazia\n");
        return -1;
    }

    //Avancando ate o fim
    tipo_no *aux = (*prtBase), *auxa = NULL;
    while (aux->prox != NULL) {
        auxa = aux;
        aux = aux->prox;
    }

    //Se houver apenas um elemento
    if (auxa == NULL) {
        int dadoRm = (*prtBase)->dado;
        free(*prtBase);
        *prtBase = NULL;
        return dadoRm;
    }

    int dadoRm = aux->dado;
    free(aux);
    auxa->prox = NULL;
    return dadoRm;
}

int filaDin_removePos(tipo_no** prtBase, int posicao){
    if ((*prtBase) == NULL) {
        printf("[ERRO] Tentando remover por posicao de uma lista vazia");
        return -1;
    }

    tipo_no *aux = (*prtBase), *auxa;
    int cont = 0;
    posicao --;
    while (aux->prox != NULL && cont < posicao)
    {
        auxa = aux;
        aux = aux->prox;
        cont ++;
    }

    int dadoRm = aux->dado;
        
}