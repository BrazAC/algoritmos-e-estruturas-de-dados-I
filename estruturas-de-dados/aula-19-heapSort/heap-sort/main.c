#include <stdlib.h>
#include <stdio.h>
#include "funcoes_heap.h"
#include <time.h>

int main(){

    srand(0);
    int min = 1, max = 10, chave;
    //char dados[MAX_HEAP] = {'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j'};

    //Inicializar heap
    est_heap meuHeap;
    heapInit(&meuHeap);

    //Mostrar heap
    heap_mostra(meuHeap);

    //===Testando ordenacao
    //INicializar lista
    est_lista minhaLista;
    minhaLista.cont = 0;

    for (int i = 0; i < MAX_HEAP; i++) {
        //Criar chave sem repetir
        int chave;
        chave = min + rand() % (max - min + 1);
        //Inserir na lista
        listaEst_insereFinal(&minhaLista, chave);
    }

    listaEst_mostra(minhaLista);

    //Ordenar decrescente
    heap_sortDecrescente(&minhaLista, &meuHeap);

    printf("Ordenada decrescente: ");
    listaEst_mostra(minhaLista);

    return 0;
}