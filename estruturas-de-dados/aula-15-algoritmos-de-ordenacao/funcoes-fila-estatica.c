#include <stdlib.h>
#include <stdio.h>
#include "funcoes-fila-estatica.h"
/*
int ordenaBubble_listaEstatica(est_listaEstatica *lista){
    if (lista->cont == MAX_SIZE) {
        return -1;
    }

    for (int i = lista->cont; i > 0; i--) {
        lista->vetInt[i] = lista->vetInt[i - 1];
    }

    //lista->vetInt[0] = dado;
    lista->cont ++;
    return 0;
}
    */

int mostra_listaEstatica(est_listaEstatica* lista){
    for (int i = 0; i < lista->cont; i++){
        printf("[%d]", lista->vetInt[i]);
    }
    printf("\n");
}

int ordenaBubble_listaEstatica(est_listaEstatica *lista){
    int temp, flag = 0;
    do{
        flag = 0;
        for (int j = 0; j < lista->cont - 1; j++) {
            if (lista->vetInt[j] > lista->vetInt[j + 1]) {
                temp = lista->vetInt[j];
                lista->vetInt[j] = lista->vetInt[j + 1];
                lista->vetInt[j + 1] = temp;
                
                flag = 1;
            }
        }
    }while(flag);
    //Obs: na versão do professor não foi usado lista->cont - i e sim lista->cont - 1
    //Pois nao altera a analise sintotica, continua n² em ambos os casos 
}

int ordenaShell_listaEstatica(est_listaEstatica* lista){
    int temp, salto = lista->cont/2, flag;
    do{
        flag = 0;
        for (int i = 0; i < ((lista->cont - 1) - salto); i ++){
            if (lista->vetInt[i] > lista->vetInt[i + salto]) {
                temp = lista->vetInt[i];
                lista->vetInt[i] = lista->vetInt[i + salto];
                lista->vetInt[i + salto] = temp;

                flag = 1;
            }
        }
        if (salto != 1){
            salto = salto/2;
        }

    }while(flag);
}

