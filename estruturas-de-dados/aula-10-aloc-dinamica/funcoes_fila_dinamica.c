#include <stdlib.h>
#include <stdio.h>
#include "funcoes_fila_dinamica.h"


void insere_fila_din(tipo_no **prt_prt_base_fila, int novoInt){
    //A fila esta vazia (ponteiro da base esta vazio)
    //*prt_prt_base_fila == prt_base_fila
    if ((*prt_prt_base_fila) == NULL) {
        //Criar novo no (criar por chamada da funcao alocaNo())
        tipo_no *novoNo = alocaNo(novoInt);
        //Guardar endereco do novo no na base da fila (em *prt_prt_base_fila)
        *prt_prt_base_fila = novoNo;
    }
    //A fila nao esta vazia (ponteiro da base aponta pra alguma coisa)
    else{
        //-- Avancar ate o ultimo no
        //Criar ponteiros auxiliares
        tipo_no *aux, *novoNo;
        //Posicionar ponteiro auxiliar no ultino no
        aux = *prt_prt_base_fila;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        //Alocar novo noh, cadastrar seu endereco no ultimo no (criar no e encadear na estrutura)
        novoNo = alocaNo(novoInt);
        aux->prox = novoNo;
    }
}

int remove_fila_din(tipo_no **prt_prt_base_fila){
    //A fila esta vazia
    if (*prt_prt_base_fila == NULL) {
        printf("Nao e possivel remover de fila vazia");
    }
    //A fila nao esta vazia
    else{
        tipo_no *aux = *prt_prt_base_fila;
        int aux_dado = aux->dado;
        (*prt_prt_base_fila) = (*prt_prt_base_fila)->prox;
        free(aux);
        return aux_dado;
    }
}

void imprimeFila(tipo_no *prt_base_fila){
    printf("Mostrando fila: ");
    while(prt_base_fila != NULL){
        printf("%d", prt_base_fila->dado);
        prt_base_fila = prt_base_fila->prox;
    }
    printf("Chegou no noh nulo!");
}

