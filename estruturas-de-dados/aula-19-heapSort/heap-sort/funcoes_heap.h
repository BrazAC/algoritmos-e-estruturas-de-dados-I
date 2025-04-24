#ifndef __FUNCOES_HEAP_H__
#define __FUNCOES_HEAP_H__

//====HEAP
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

//====LISTA EX.
typedef struct est_lista{
    int lista[MAX_HEAP];
    int cont;
} est_lista;

void listaEst_insereFinal(est_lista* lista, int dado);
int listaEst_removeFinal(est_lista *lista);
void listaEst_mostra(est_lista);

//====HEAP SORT
//Obs: para a versao crescente use heap mínimo com as funcoes pertinentes, para o decrescente o oposto;
est_dado heap_removeRoot(est_heap*);
void heap_sortCrescente(est_lista* lista);
void heap_sortDecrescente(est_lista* lista, est_heap *heap_aux);


#endif