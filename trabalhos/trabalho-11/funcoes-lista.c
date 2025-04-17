#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcoes.h"

tipo_no_lista* alocaNo(tipo_no_lista novoNo){
    tipo_no_lista *novoNoAlocado = (tipo_no_lista*)malloc(sizeof(tipo_no_lista));
    if (novoNoAlocado == NULL) return novoNoAlocado;
    
    novoNoAlocado->prox = NULL;
    novoNoAlocado->confirmados = novoNo.confirmados;
    novoNoAlocado->mortes = novoNo.mortes;
    novoNoAlocado->recuperados = novoNo.recuperados;
    novoNoAlocado->mortes100 = novoNo.mortes100;
    novoNoAlocado->recuperados100 = novoNo.recuperados100;
    strcpy(novoNoAlocado->pais, novoNo.pais);

    return novoNoAlocado;
}

int lista_insereInicio(tipo_no_lista **lista, tipo_no_lista nohAux){
    if (*lista == NULL) {
        tipo_no_lista *novoNo = alocaNo(nohAux);
         
        if (novoNo != NULL) {
            *lista = novoNo;
            return 0;
        }

        return -1;
    }

    tipo_no_lista *novoNo = alocaNo(nohAux);
    if (novoNo == NULL) return -1;

    tipo_no_lista *aux = *lista;

    *lista = novoNo;
    novoNo->prox = aux;
    return 0;
}

tipo_no_lista lista_removeInicio(tipo_no_lista **lista){
    if (*lista == NULL) {
        tipo_no_lista noVazio;
        noVazio.confirmados = -1;
        return noVazio;
    }

    tipo_no_lista noRm = *(*lista);
    tipo_no_lista *aux = *lista;

    *lista = (*lista)->prox;
    free(aux);
    return noRm;
}

void lista_mostra(tipo_no_lista *lista){
    if(lista == NULL){
        printf("[AVISO] Tentando mostrar lista vazia!\n");
        return;
    }

    tipo_no_lista *aux = lista;
    printf("|Pais/Regiao                     |Confirmados|Mortes|Recuperados|Mortes/100|Recuperados/100|\n");
    printf("|--------------------------------|-----------|------|-----------|----------|---------------|\n");
    while(aux != NULL){
        printf("|%-32s|%-11d|%6d|%11d|%10.2f|%15.2f|\n", 
            aux->pais,
            aux->confirmados, 
            aux->mortes, 
            aux->recuperados,
            aux->mortes100,
            aux->recuperados100
        );

        aux = aux->prox;
    }
}

