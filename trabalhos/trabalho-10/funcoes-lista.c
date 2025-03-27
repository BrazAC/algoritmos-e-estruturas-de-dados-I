#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "funcoes-lista.h"

//==Manipulação da lista
est_no* alocaNo(int userId, int movieId, float rating){
    est_no *novoNo = (est_no*)malloc(sizeof(est_no));
    
    novoNo->userId = userId;
    novoNo->movieId = movieId;
    novoNo->rating = rating;

    novoNo->prox = NULL;
    novoNo->ant = NULL;

    return novoNo;
}

void filaDinD_insereFinal(est_no **fila, int userId, int movieId, float rating){
    if(*fila == NULL){
        *fila = alocaNo(userId, movieId, rating);
        return;
    }

    est_no *aux = *fila;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    est_no *novoNo = alocaNo(userId, movieId, rating);
    aux->prox = novoNo;
    novoNo->ant = aux;
}

void filaDinD_mostraX(est_no *fila, int quant){
    if (fila == NULL) return;

    est_no *aux = fila;
    printf("Mostrando [%d] primeiros elementos da lista:\n", quant);
    while(aux->prox != NULL && quant > 0){
        printf("UserId: [%d] | MovieId: [%d] | Rating [%f]\n", aux->userId, aux->movieId, aux->rating);
        aux = aux->prox;
        quant --;
    }
    if (quant > 0 && aux->prox == NULL){
        printf("UserId: [%d] | MovieId: [%d] | Rating [%f]\n", aux->userId, aux->movieId, aux->rating);
    }
}

//Manipulação dos arquivos
void posicionaPonteiro_proxNewLine(FILE* arquivo){
    while(1){
        if(fgetc(arquivo) == '\n'){
            break;
        }
    }
}

