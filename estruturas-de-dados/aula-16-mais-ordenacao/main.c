/*
Gastei todo meu tempo tentando entender o quick sort, que é oq eu tinha começado em sala.
Acabou que no final não consegui implementar nem o quick sort nem o merge :D

mas eu tentei
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "funcoes-lista.h"

int main(){
    est_lista lista;
    lista.cont = 0;

    srand(time(NULL));
    int min = 0, max = 10;

    for (int i = 0; i < 10; i++) {
        insere_comecolistaEstatica(&lista, min + rand() % (max - min + 1));
 
    }
    mostra_listaEstatica(&lista);
    quick_sort(lista.vetInt, 0, lista.cont - 1);
    mostra_listaEstatica(&lista);

    return 0;
}