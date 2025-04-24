#include <stdlib.h>
#include <stdio.h>
#include "funcoes-fila-estatica.h"

int main(){

    est_listaEstatica lista;
    lista.cont = 0;

    insere_comecolistaEstatica(&lista, 7);
    insere_comecolistaEstatica(&lista, 4);
    insere_comecolistaEstatica(&lista, 1);
    insere_comecolistaEstatica(&lista, 3);
    insere_comecolistaEstatica(&lista, 2);
    insere_comecolistaEstatica(&lista, 3);
    insere_comecolistaEstatica(&lista, 6);
    mostra_listaEstatica(&lista);

    //ordenaInsert_listaEstatica(&lista);
    mostra_listaEstatica(&lista);

    return 0;
}