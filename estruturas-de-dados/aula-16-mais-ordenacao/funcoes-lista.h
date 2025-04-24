#ifndef __FUNCOES_LISTA_H__
#define __FUNCOES_LISTA_H__

#define MAX_SIZE 10

typedef struct est_lista{
    int vetInt[10];
    int cont;
} est_lista;

void quick_sort(int[], int, int);
int sort(int[], int, int);
int mostra_listaEstatica(est_lista*);
int insere_comecolistaEstatica(est_lista*, int);


#endif