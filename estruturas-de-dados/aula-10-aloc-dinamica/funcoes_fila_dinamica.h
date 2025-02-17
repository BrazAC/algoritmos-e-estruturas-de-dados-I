#ifndef __FUNCOES_FILA_DINAMICA__
#define __FUNCOES_FILA_DINAMICA__

/*
typedef struct tipo_no{
    tipo_de_dado dado;
    tipo_no *prox;
} tipo_no;
*/

typedef struct tipo_no{
    int dado;
    tipo_no *prox;
} tipo_no;

void* alocaNo(int);
void insere_fila_din(tipo_no**, int);
int remove_fila_din(tipo_no**);
int primeiro_fila_din(tipo_no*);
void mostra_fila_din(tipo_no*);


#endif