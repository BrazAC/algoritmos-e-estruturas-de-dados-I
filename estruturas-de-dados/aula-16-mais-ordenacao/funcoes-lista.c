#include <stdlib.h>
#include <stdio.h>
#include "funcoes-lista.h"

int insere_comecolistaEstatica(est_lista* lista, int dado){
    if (lista->cont == MAX_SIZE) {
        return -1;
    }

    for (int i = lista->cont; i > 0; i--) {
        lista->vetInt[i] = lista->vetInt[i - 1];
    }

    lista->vetInt[0] = dado;
    lista->cont ++;
    return 0;
}

int mostra_listaEstatica(est_lista* lista){
    for (int i = 0; i < lista->cont; i++){
        printf("[%d]", lista->vetInt[i]);
    }
    printf("\n");
}

void quick_sort(int vet[], int e, int d){
    if (d > e) {
        int j = sort(vet, e, d);
        quick_sort(vet, e, j);
        quick_sort(vet, j + 1, d); 
    }
}

int sort(int vet[], int e, int d){
    //Inicializando pivo, i, j
    int pivo = vet[(e + d) / 2];
    int i = e - 1;
    int j = d + 1;

    //Ordenar
    while(1){
        do{
            i++;
        }while(vet[i] < pivo);
            
        do{
            j--;
        }while(vet[j] > pivo);

        if(j <= i){
            return j;
            
        }

        int temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
    }
}


