#ifndef __FUNCOES_H__
#define __FUNCOES_H__

#define MAX_HEAP 10

typedef struct est_dado{
    char dado;
    int chave;
} est_dado;

typedef struct est_heap{
    est_dado lista[MAX_HEAP];
    int cont;
} est_heap;


void heapInit(est_heap*);
void heap_insere(est_heap*, int, int);
est_dado heap_remove(est_heap*, int);

void heap_sobeHeap(est_heap*, int);
void heap_desceHeap(est_heap*, int);

void heap_mostra(est_heap);

#endif