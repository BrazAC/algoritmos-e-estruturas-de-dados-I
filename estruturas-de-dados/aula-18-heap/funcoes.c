#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

void heapInit(est_heap* heap){
    heap->cont = 0;
    for(int i = 0; i < MAX_HEAP; i ++){
        //INciializar dados
        heap->lista[i].dado = ' ';
        heap->lista[i].chave = 0;
    }
}

void heap_sobeHeap(est_heap* heap, int pos){
    int posPai = (int)((pos - 1) / 2);

    //Separando info
    int dadoAtual = (heap->lista[pos]).dado;
    int chaveAtual = (heap->lista[pos]).chave;
    int dadoPai = (heap->lista[posPai]).dado;
    int chavePai = (heap->lista[posPai]).chave;

    if (pos != 0 && chaveAtual > chavePai) {
        //Fazer swap entre no atual e do pai
        //Obs: vc pode mover os structs inteiros de uma vez, não necessariamente apenas os dados (na vdd faça isso mesmo)
        (heap->lista[posPai]).dado = dadoAtual;
        (heap->lista[posPai]).chave = chaveAtual;

        (heap->lista[pos]).dado = dadoPai;
        (heap->lista[pos]).chave = chavePai;

        //Chamar sobeDado novamente
        heap_sobeHeap(heap, posPai);
    }

    return;
}

void heap_insere(est_heap* heap, int dado, int chave){
    if (heap->cont >= MAX_HEAP){
        printf("[ERRO] Tentando inserir em lista heap cheia!");
        return;
    } 

    //Inserir no final da lista
    (heap->lista[heap->cont]).chave = chave;
    (heap->lista[heap->cont]).dado = dado;
    heap->cont ++;

    //Subir dado recursivamente
    heap_sobeHeap(heap, heap->cont - 1);


}

est_dado heap_remove(est_heap* heap, int chave){
    int pos;
    //Encontrar posicao do noh a ser removido
    for (pos = 0; pos < heap->cont; pos++){
        if (heap->lista[pos].chave == chave) {
            break;
        }
    }

    //Verificando se a chave esta ou nao cadastradas
    if (heap->lista[pos].chave != chave) {
        printf("[ERRO] nao e possivel remover, chave nao cadastrada\n");
    }
    else{
        est_dado dadoRm = heap->lista[pos];
        heap->cont --;

        heap->lista[pos] = heap->lista[heap->cont];
        heap_desceHeap(heap, pos);

        return dadoRm;
    }

}

void heap_desceHeap(est_heap* heap, int pos){
    int idx_esq, idx_dir, idx_maior;
    idx_esq = 2*pos + 1;
    idx_dir = 2*pos + 2;

    //Identificar se ele tem filhos, e qual o maior
    if (idx_esq < heap->cont) {
        if(idx_dir < heap->cont){
            //Se tem dois filhos, identifica o maior
            if (heap->lista[idx_esq].chave > heap->lista[idx_dir].chave){
                idx_maior = idx_esq;
            }
            else{
                idx_maior = idx_dir;
            }
        }
        else{
            //Só tem filho esquerdo
            idx_maior = idx_esq;
        }
    }

    //Descer valor, verifica se o filho e maior que o pai, se sim, faça o swap
    if (heap->lista[pos].chave < heap->lista[idx_maior].chave) {
        est_dado aux = heap->lista[pos];
        heap->lista[pos] = heap->lista[idx_maior];
        heap->lista[idx_maior] = aux;
        heap_desceHeap(heap, idx_maior);
    }
}

void heap_mostra(est_heap heap){
    if (heap.cont == 0) return;

    printf("[dado, chave] => ");
    for (int i = 0; i < heap.cont; i++){
        printf("[%c, %d]", heap.lista[i].dado, heap.lista[i].chave);
    }
    printf("\n");
}

