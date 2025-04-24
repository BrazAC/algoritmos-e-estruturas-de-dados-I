#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"
#include <time.h>

int main(){
    srand(time(NULL));
    int min = 1, max = 10, chave;
    char dados[MAX_HEAP] = {'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j'};

    //Inicializar heap
    est_heap meuHeap;
    heapInit(&meuHeap);

    for (int i = 0; i < MAX_HEAP; i++) {
        //Criar chave sem repetir
        int chave, sentinel = 1;
        while(sentinel){
            sentinel = 0;
            chave = min + rand() % (max - min + 1);
            //Se a chave nao tiver sido usada ainda, adicionar dado com essa chave
            for (int j = 0; j < meuHeap.cont; j++){
                if (meuHeap.lista[j].chave == chave){
                    sentinel = 1;
                }
            }
        }

        //Inserir no heap
        heap_insere(&meuHeap, dados[i], chave);
    }

    //Mostrar heap
    heap_mostra(meuHeap);

    //Remover um elemento
    heap_remove(&meuHeap, 2);

    //Mostrar heap
    heap_mostra(meuHeap);

    return 0;
}
